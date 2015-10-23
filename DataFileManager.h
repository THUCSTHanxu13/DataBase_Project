#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "DataStruct.h"
#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"

class DataFileManager {

	private:
		std::string path;
		FileManager* fm;
		BufPageManager* bpm;
		int fileID;

	public:
		DataFileManager(std::string route) {
			path = route;
			fm = new FileManager();
			bpm = new BufPageManager(fm);
			if (access(route.c_str(), 0) != -1)
				fm->createFile(route.c_str()); 
			fm->openFile(route.c_str(), fileID);
		}

		void setPage(int fileID, int pageID, void *dst, int offset, int len) {
			int index;
			BufType result = bpm->getPage(fileID, pageID, index);
			memcpy(result, (char *)dst + offset, len);
			bpm->markDirty(index); 
		}

		void* getPage(int fileID, int pageID) {
			int index;
			BufType result = bpm->getPage(fileID, pageID, index);
			bpm->access(index);
			return (void *)(result);
		}

		~DataFileManager() {
			bpm->close();
			fm -> closeFile(fileID);
		}
};

#endif