#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include "Header.h"
#include "DataType.h"
#include <vector>
#include <map>

class DataStruct {

		std::vector<std::string> checkNameList;
		std::vector<DataType *> dataList;
		std::vector<int> lenList;
		std::map<std::string, int> DataName;
		int length;
		int structLength;
		std::string name;

		void* writeString(std::string name, void *dst) {
			int len = name.length();
			memcpy(dst, &len, sizeof(int));
			dst = (char *)dst + sizeof(int);
			for (int i = name.length() - 1; i >= 0; i--)
				*((char *)dst + i) = name[i];
			dst = (char *)dst + name.length();
			return dst;
		}

		void* writeInteger(int name, void *dst) {
			memcpy(dst, &name, sizeof(int));
			dst = (char *)dst + sizeof(int);
			return dst;
		}

	public:

		DataStruct(std::string name) {
			length = 0;
			structLength = name.length() + 4 + 4;
			this -> name = name;
			for (int i = dataList.size() -1; i >= 0; i--)
				delete dataList[i];
			dataList.clear();
			lenList.clear();
		}

		~DataStruct() {
			dataList.clear();
			lenList.clear();
		}

		std::string getTableName() {
			return name;
		}

		int getSize() {
			return length;
		}

		int getStructSize() {
			return structLength;
		}

		int getStruct(void *dst, int offset = 0) {
			void *start = dst;
			dst = (char *)dst + offset;
			dst = writeString(name, dst);
			dst = writeInteger(length, dst);
			for (int i = 0; i < dataList.size(); i++) {
				dst = writeString(dataList[i]->getType(), dst);
				dst = writeString(dataList[i]->getName(), dst);
			}
			return (char *)start - (char *)dst;
		}

		void addDataType(std::string name, std::string type, int len = 0) {
			if (type == "int") {
				dataList.push_back(new Int(name, "Int"));
				lenList.push_back(length);
				DataName[name] = dataList.size() - 1;
				length += 4;
				structLength += 4 + 3 + 4 + name.length();
			} else
			if (type == "varchar") {
				dataList.push_back(new VarChar(name, "VarChar", len));
				lenList.push_back(length);
				DataName[name] = dataList.size() - 1;
				length += len;
				structLength += 4 + 7 + 4 + name.length();
			}
		}

		void setData(std::string name, void* src, int offset = 0, int len = MAX_BUFFER_SIZE) {
			dataList[DataName[name]]->readFromBuffer(src, offset, len);
		}

		void setData(std::string name, std::string type, std::string content) {
			if (type == "int") {
				if (content == "NULL") dataList[DataName[name]]->setEmpty(1); else {
					dataList[DataName[name]]->setEmpty(0); 
					int num = atoi(content.c_str());
					dataList[DataName[name]]->readFromBuffer(&num, 0, 4);
				}
			} else {
				if (content == "NULL") dataList[DataName[name]]->setEmpty(1); else {
					dataList[DataName[name]]->setEmpty(0); 
					dataList[DataName[name]]->readFromBuffer(content.c_str(), 0, content.length());
				}
			}
		}

		void getData(std::string name, void*dst, int offset = 0, int len = MAX_BUFFER_SIZE) {
			dataList[DataName[name]]->writeToBuffer(dst, offset, len);			
		}

		void readFromBuffer(void*src, int offset = 0, int len = MAX_BUFFER_SIZE) {
			src = (char *)src + offset;
			for (int i = 0; i < dataList.size(); i++) {
				DataType *con = dataList[i];
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
			for (int i = 0; i < dataList.size(); i++) {
				DataType *con = dataList[i];
				int size = con -> getSize();
				len -= size;
				if (len > 0)
					con -> writeToBuffer(dst, 0);
				else {
					con -> writeToBuffer(dst, 0, len + size);
					break;
				}
				dst = (char *)dst + size + 4;
			}
		}

		void initialChecker() {
			checkNameList.clear();
		}

		void addChecker(std::string name, void* position, int len = 0) {
			checkNameList.push_back(name);
			dataList[DataName[name]]->writeToBuffer(position, 0, len);
		}

		bool checkData(std::vector<std::string> nameList, void *position) {
			for (int i = nameList.size() - 1; i >= 0; i--) {
				int j = DataName[nameList[i]];
				if (dataList[j]->checkBuffer(((char *)position + lenList[j]))) return false;
			}
			return true;
		}

		bool checkData(void *position) {
			return checkData(checkNameList, position);
		}

};

#endif
