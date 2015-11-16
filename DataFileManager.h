#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "DataStruct.h"
#include "DataType.h"
#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include <cstdlib>

class DataFileManager {

	private:
		int fileID;
		Table table;

		void writeString(char * &last, std::string name) {
			int len = name.length();
			memcpy(last, &len, 4);
			last = last + 4;
			for (int i = 0; i < len; i++) {
				*last = name[i];
				last = last + 1;
			}
		}

		std::string readString(char * &last, int len) {
			std::string res = "";
			for (int i = 0; i < len; i++) {
				res = res + *last;
				last++;
			}
			return res;
		}

		int readInteger(char * &last) {
			int res = *(int *)(last);
			last = last + 4;
			return res;
		}

		void writeInteger(char * &last, int len) {
			memcpy(last, &len, 4);
			last = last + 4;			
		}

		void newHeaderPage(int fileID, int pageID, int lastPage) {
			int index;
			BufType result = bpm->allocPage(fileID, pageID, index, false);
			memset(result, 0, MAX_PAGE_SIZE);
			int header = 1;
			result[0 + header] = table.size;
			result[1 + header] = -1;
			char * last = (char *)result + 8 + header * 4;
			for (int i = 0; i < table.name.size(); i++) {
				if (table.primarykey == table.name[i]) result[header + 1] = table.name.size() - i - 1; 
				writeString(last, table.name[i]);
				writeInteger(last, table.len[i]);
				writeInteger(last, table.empty[i]);
				if (table.type[i] == "int") writeInteger(last, 0); else writeInteger(last, 1);
			}
			result[0] = last - (char*)(result);
			bpm->access(index);
			bpm->markDirty(index);
		}

		void getHeaderPage(int fileID, int pageID, int lastPage) {
			int index;
			BufType result = bpm->getPage(fileID, pageID, index);
			int header = 1;
			table.size = result[0 + header];
			char * last = (char *)result + 8 + header * 4;
			char * end = (char *)result + result[0];
			while (last != end) {
				int len = readInteger(last);
				table.name.push_back(readString(last, len));
				table.len.push_back(readInteger(last));
				table.empty.push_back(readInteger(last));
				table.sum++;
				if (readInteger(last) == 0) table.type.push_back("int"); else table.type.push_back("varchar");
			}
			if (result[1 + header] != -1)
				table.primarykey = table.name[result[1 + header]];
			bpm->access(index);
		}

		void newPage(int fileID, int pageID) {
			int index;
			BufType result = bpm->allocPage(fileID, pageID, index, false);
			memset(result, 0, MAX_PAGE_SIZE);
			result[0] = PAGE_HEADER * 4;
			result[1] = MAX_PAGE_SIZE - PAGE_HEADER * 4 - 4;
			bpm->access(index);
			bpm->markDirty(index);
		}

	public:
		std::string path;
		DataStruct *dataStruct;
		FileManager* fm;
		BufPageManager* bpm;

		DataFileManager() {
			fm = NULL;
			bpm = NULL;
			dataStruct = new DataStruct("gg");
		}

		void setTable(Table table) {
			this->table = table;
		}

		void createFile() {
			int index;
			fm = new FileManager();
			fm->createFile(path.c_str());
			fm->openFile(path.c_str(), fileID);
			bpm = new BufPageManager(fm);
			newHeaderPage(fileID, 0, 0);
			bpm -> close();
			fm -> closeFile(fileID);
			delete bpm;
			delete fm;
			bpm = NULL;
			fm = NULL;
		}

		void openFile() {
			int index;
			fm = new FileManager();
			fm->openFile(path.c_str(), fileID);
			bpm = new BufPageManager(fm);
			getHeaderPage(fileID, 0, 0);
			for (int i = 0; i < table.name.size(); i++) {
				dataStruct -> addDataType(table.name[i], table.type[i], table.len[i]);
			}
		}

		void setFile(std::string route) {
			path = route;
		}

		void showTable() {
			for (int i = 0; i < table.name.size(); i++) {
				printf("%s ", table.name[i].c_str());
				printf("%s ",table.type[i].c_str());
				printf("(%d) ", table.len[i]);
				if (!table.empty[i]) printf("NOT NULL ");
				printf("\n");
			}
			if (table.primarykey != "") printf("PRIMARY KEY (%s)\n", table.primarykey.c_str());
		}

		void insert(std::vector<std::string> content) {
			int index;
			BufType result = bpm->getPage(fileID, 0, index);
			int page = 0;
			for (int i = 1; i <= result[2047]; i++)
				if (result[2047 - i] == 0) {
					page = i;
				}
			if (page == 0) {
				result[2047]++;
				result[2047 - result[2047]] = 0;
				page = result[2047];
				newPage(fileID, page);
			}
			int index1 = index;
			BufType res = result;
			for (int i = 0; i < content.size(); i++) {
				dataStruct ->setData(table.name[i], table.type[i], content[i]);
			}
			result = bpm->getPage(fileID, page, index);
			if (result[0] + table.size + 4 < (2047 - result[2047]) * 4) {
				result[1] = result[1] - table.size - 4;
				result[2047]++;
				result[2047 - result[2047]] = result[0];
				dataStruct -> writeToBuffer((char *)result +  result[0] , 0, table.size);
				result[0] = result[0] + table.size;
			} else {
				for (int i = 1; i <= result[2047]; i++)
					if (result[2047 - i] == -1) {
						result[2047 - i] = result[2047 - i + 1] + table.size;
						result[1] = result[1] - table.size;
						dataStruct -> writeToBuffer((char *)result + result[2047 - i], 0, table.size);
						break;
					}
			}
			if (result[1] <= table.size + 4) {
				res[2047 - page] = 1;
			}
			bpm->access(index1);
			bpm->markDirty(index1);
			bpm->access(index);
			bpm->markDirty(index);			
		}

		~DataFileManager() {
			if (bpm != NULL) {bpm->close();delete bpm;}
			if (fm != NULL) {fm -> closeFile(fileID);delete fm;}
			if (dataStruct != NULL) delete(dataStruct);
		}
};

#endif
