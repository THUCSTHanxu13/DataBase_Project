#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "DataStruct.h"
#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include <cstdlib>

class DataFileManager {

	private:
		FileManager* fm;
		BufPageManager* bpm;
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

	public:
		std::string path;

		DataFileManager() {
			fm = NULL;
			bpm = NULL;
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
			bpm -> close();
			fm -> closeFile(fileID);
			delete bpm;
			delete fm;
			bpm = NULL;
			fm = NULL;
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
			// for (int i = 0; i < content.size(); i++)
			// 	printf("%s ", content[i].c_str());
			// printf("\n");
		}

		~DataFileManager() {
			if (bpm != NULL) bpm->close();
			if (fm != NULL) fm -> closeFile(fileID);
		}
};

#endif
