#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include "Header.h"
#include "DataType.h"
#include <vector>
#include <map>

class DataStruct {
	std::vector<DataType> DataList;
	std::map<std::string, int> DataName;
	int length;
	std::string name;

	public:
		DataStruct(std::string name) {
			length = 0;
			this -> name = name;
			DataList.clear();
		}

		~DataStruct() {
			DataList.clear();
		}

		std::string getTableName() {
			return name;
		}

		int getSize() {
			return length;
		}

		void addDataType(std::string name, std::string type, int len = 0) {
			if (type == "Int") {
				DataList.push_back(Int("Int"));
				DataName[name] = DataList.size() - 1;
				length += 4;
			} else
			if (type == "VarChar") {
				DataList.push_back(VarChar("VarChar", len));
				DataName[name] = DataList.size() - 1;
				length += len;
			}
		}

		void setData(std::string name, void* src, int offset = 0, int len = MAX_BUFFER_SIZE) {
			DataList[DataName[name]].readFromBuffer(src, offset, len);
		}

		void getData(std::string name, void*dst, int offset = 0, int len = MAX_BUFFER_SIZE) {
			DataList[DataName[name]].writeToBuffer(dst, offset, len);			
		}

		void initialCheck() {
			checkNameList.clear();
			checkPosition.clear();
		}

		void releaseCheck() {

		}

		bool checkData(std::vector<std::string> nameList, std::vector<void *>position) {
			for (int i = nameList.size() - 1; i >= 0; i--) {
				if (!DataName[i] -> checkBuffer(position[i])) return false;
			}
			return true;
		}

		void readFromBuffer(void*src, int offset = 0, int len = MAX_BUFFER_SIZE) {
			src = (char *)src + offset;
			for (int i = 0; i < DataList.size(); i++) {
				DataType *con = &DataList[i];
				int size = con -> getSize();
				len -= size;
				if (len > 0)
					con -> readFromBuffer(src, 0);
				else {
					con -> readFromBuffer(src, 0, len + size);
					break;
				}
				src = (char *)src + size;
			}
		}

		void writeToBuffer(void *dst, int offset = 0, int len = MAX_BUFFER_SIZE) {
			dst = (char *)dst + offset;
			for (int i = 0; i < DataList.size(); i++) {
				DataType *con = &DataList[i];
				int size = con -> getSize();
				len -= size;
				if (len > 0)
					con -> writeToBuffer(dst, 0);
				else {
					con -> writeToBuffer(dst, 0, len + size);
					break;
				}
				dst = (char *)dst + size;
			}
		}

};

#endif
