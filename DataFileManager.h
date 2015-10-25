#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "DataStruct.h"
#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include <cstdlib>

class DataFileManager {

	private:
		std::string path;
		FileManager* fm;
		BufPageManager* bpm;
		int fileID;

		std::string readString(void *src) {
			int len = *(int *)(src);
			src = (char *)src + 4;
			std::string tableName = "";
			for (int i = 0; i < len; i++)
				tableName = tableName + *((char*)src + i);
			return tableName;
		}

		int readInteger(void *src) {
			return *(int *)(src);
		}

		BufType getPage(int fileID, int pageID, int &index) {
			BufType result = bpm->getPage(fileID, pageID, index);
			bpm->access(index);
			return result;
		}

		void searchPage(int fileID, int pageID, DataStruct table) {
			int index;
			BufType result = getPage(fileID, pageID, index);
			void *header = (char *)result + PAGE_HEADER;
			for (int i = result[2047]; i > 0; i--) {
				int j = result[2047 -  i];
				if (result[j] != -1 && table.checkData((char *)header + result[j])) {
				}
			}
			bpm->access(index);
		}

		void newEmptyPage(int fileID, int pageID) {
			int index;
			BufType result = bpm->allocPage(fileID, pageID, index, false);
			memset(result, 0, MAX_PAGE_SIZE);
			result[2047] = 0;
			result[0] = 0;
			result[1] = 0;
			result[2] = 8192 - PAGE_HEADER - 4;
			bpm->access(index);
			bpm -> markDirty(index);
		}

		void writePage(int fileID, int pageID, DataStruct table) {
			int index;
			BufType result = getPage(fileID, pageID, index);
			int headOffset = PAGE_HEADER + result[0];
			int size = table.getSize();
			int contentTot = result[2047];
			int tailOffset = 8192 - result[2047] * 4 - 8;
			if (tailOffset - headOffset >= size) {
				result[2047]++;
				result[2047 - result[2047]] = result[0];
			} else {
				for (int i = result[2047]; i > 0; i--)
					if (result[2047 - i] == -1) {
						result[2047 - i] = result[0];
						break;
					}
			}
			table.writeToBuffer((char *)result + headOffset);
			result[0] += size;
			result[1] ++;
			result[2] -= size + 4;
			bpm->access(index);
			bpm -> markDirty(index);
		}

		void newHeaderPage(int fileID, int pageID, int lastPage) {
			int index;
			BufType result = bpm->allocPage(fileID, pageID, index, false);
			memset(result, 0, MAX_PAGE_SIZE);
			result[0] = 0;
			result[1] = 1;
			result[2] = 8192 - PAGE_HEADER - 4;
			result[3] = lastPage;
			result[4] = 0;
			result[2047] = 0;
			bpm->access(index);
			bpm->markDirty(index);
		}

		void writeHeaderPage(int fileID, int pageID, DataStruct table) {
			char *con = (char *)calloc(MAX_PAGE_SIZE, sizeof(char));
			int size = table.getStruct(con);
			int index;
			BufType result = getPage(fileID, pageID, index);
			int headOffset = PAGE_HEADER + result[0];
			int tableTot = result[2047];
			int tailOffset = 8192 - result[2047] * 4 - 8;
			if (tailOffset - headOffset >= size) {
				result[2047]++;
				result[2047 - result[2047]] = result[0];
				newEmptyPage(fileID, pageID + result[2047]);
				writePage(fileID, pageID + result[2047], table);
			} else {
				for (int i = result[2047]; i > 0; i--)
					if (result[2047 - i] == -1) {
						result[2047 - i] = result[0];
						newEmptyPage(fileID, pageID + result[2047 - i]);
						writePage(fileID, pageID + result[2047 - i], table);
						break;
					}
			}
			memcpy(result, con, size);
			result[0] += size;
			result[1] ++;
			result[2] -= size + 4;
			bpm->access(index);
			bpm -> markDirty(index);
			free(con);
		}

		bool checkWritePage(int fileID, int pageID, int size) {
			int index;
			BufType result = getPage(fileID, pageID, index);
			bpm->access(index);
			return result[2] >= size + 4;
		}

		void delPageInHeaderPage(int fileID, int pageID, int page, DataStruct table) {
			int size = table.getStructSize();
			int index;
			BufType result = getPage(fileID, pageID, index);
			for (int i = 1; i <= result[2047]; i++)
				if (result[2047 - i] > result[2047 - page + pageID]) {
					int offset = result[2047 - i] - result[2047 - page + pageID];
					for (int j = result[2047 - i]; j < result[0]; j++)
						*((char *)result + PAGE_HEADER + j - offset) = *((char *)result + PAGE_HEADER + j);
					break;
				}
			result[0] -= size;
			result[2047 - page + pageID] = -1;
			result[2] += 4 + size;
			if (page - pageID == result[2047]) result[2047]--;
			bpm->access(index);
		}

		void delPage(int fileID, int pageID) {
			int index;
			BufType result = getPage(fileID, pageID, index);

			bpm->access(index);
		}

	public:

		DataFileManager() {
			fm = NULL;
			bpm = NULL;
		}

		void createFile() {
			int index;
			fm = new FileManager();
			if (access(path.c_str(), 0) != -1) {
				fm -> createFile(path.c_str());
			}
			fm->openFile(path.c_str(), fileID);
			bpm = new BufPageManager(fm);
			newHeaderPage(fileID, 0, 0);
			bpm->markDirty(index);
			bpm -> close();
			fm -> closeFile(fileID);
			delete bpm;
			delete fm;
			bpm = NULL;
			fm = NULL;
		}

		void openFile() {
			if (access(path.c_str(), 0) != -1)
				createFile();
			fm = new FileManager();
			bpm = new BufPageManager(fm);
			fm->openFile(path.c_str(), fileID);
		}

		void setFile(std::string route) {
			path = route;
		}

		void setPage(int fileID, int pageID, void *dst, int offset = 0, int len = 8192) {
			int index;
			BufType result = bpm->getPage(fileID, pageID, index);
			memcpy(result, (char *)dst + offset, len);
			bpm->markDirty(index); 
		}

		void searchPage(int fileID, DataStruct table) {
			std::string name = table.getTableName();
			int index;
			int pageNumber = 0;
			BufType pageHeader = getPage(fileID, 0, index);
			while (true) {
				int pageTot = pageHeader[1];
				int pagePre = pageHeader[3];
				int pageNxt = pageHeader[4];
				int tableTot = pageHeader[2047];
				for (int i = 1; i <= tableTot; i++) {
					int offset = pageHeader[2047 - i];
					if (offset == -1) continue;
					void *src = (char *)pageHeader + PAGE_HEADER + offset;
					std::string tableName = readString((char *)src);
					if (tableName == name) searchPage(fileID, pageNumber + i, table);
				}
				if (pageNxt == 0) break;
				pageHeader = getPage(fileID, pageNxt, index);
				pageNumber = pageNxt;
			}
		}

		void pushPage(int fileID, DataStruct table) {
			std::string name = table.getTableName();
			int index;
			int pageNumber = 0;
			int size = table.getSize();
			BufType pageHeader = getPage(fileID, 0, index);
			while (true) {
				int pageTot = pageHeader[1];
				int pagePre = pageHeader[3];
				int pageNxt = pageHeader[4];
				int tableTot = pageHeader[2047];
				for (int i = 1; i <= tableTot; i++) {
					int offset = pageHeader[2047 - i];
					if (offset == -1) continue;
					void *src = (char *)pageHeader + PAGE_HEADER + offset;
					std::string tableName = readString((char *)src);
					if (tableName == name)
						if (checkWritePage(fileID, pageNumber + i, size)) {
							writePage(fileID, pageNumber + i, table);
							break;
						}
				}
				if (pageNxt == 0) {
					if (checkWritePage(fileID, pageNumber, table.getStructSize())) {
						writeHeaderPage(fileID, pageNumber + pageTot, table);	
					} else {
						newHeaderPage(fileID, pageNumber + pageTot, pageNumber);
						writeHeaderPage(fileID, pageNumber + pageTot, table);
					}
					break;
				}
				pageHeader = getPage(fileID, pageNxt, index);
				pageNumber = pageNxt;
			}
		}

		void delPageTable(int fileID, DataStruct table) {

		}

		~DataFileManager() {
			bpm->close();
			fm -> closeFile(fileID);
		}
};

#endif