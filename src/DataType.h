#ifndef DATATYPE_H
#define DATATYPE_H
#include "Header.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>

class DataType {
	protected:
		int length;
		std::string type;
		std::string name;
		int empty;

	public:
		DataType() {}
		~DataType() {}

		void setType(std::string type) {
			this -> type = type;
		}

		void setName(std::string name) {
			this -> name = name;
		}
		
		std::string getName() {
			return name;
		}

		std::string getType() {
			return type;
		}

		int getSize() {
			return length;
		}

		void setEmpty(int con) {
			empty = con;
		}
		
		virtual void writeToBuffer(void *src, int offset = 0, int len = MAX_BUFFER_SIZE) {};
		virtual void readFromBuffer(const void *src, int offset = 0, int len = MAX_BUFFER_SIZE) {};
		virtual bool checkBuffer(void *src, int offset = 0) {};
};

class Int : public DataType {

	public:
		int value;

		Int(std::string name, std::string type) {
			this -> name = name;
			this -> type = type;
			value = 0;
			this -> length = 4;
			this -> empty = 1;
		}
		
		void readFromBuffer(const void *src, int offset = 0, int len = MAX_BUFFER_SIZE) {
			value = *(int *)((char *)src + offset);
		}

		void writeToBuffer(void *src, int offset = 0, int len = MAX_BUFFER_SIZE) {
			*(int *)((char*)src + offset) = empty;
			offset += 4;
			*(int *)((char *)src + offset) = value;
		}

		bool checkBuffer(void *src, int offset = 0) {
			if (value == *(int *)((char *)src + offset))
				return true;
			else
				return false;
		}
};

class VarChar : public DataType {

	
	public:
		char *value;

		VarChar(std::string name, std::string type, int len = 1) {
			this -> name = name;
			this -> type = type;
			this -> length = len;
			value = (char *)calloc(len, sizeof(char));
			this -> empty = 1;
		}
		
		void readFromBuffer(const void *src, int offset = 0, int len = MAX_BUFFER_SIZE) {
			for (int i = 0; i < length; i++)
				value[i] = '\0';
			if (length < len) len = length;
			for (int i = 0; i < len; i++)
				value[i] = *((char *)src + offset + i);			
		}

		void writeToBuffer(void *src, int offset = 0, int len = MAX_BUFFER_SIZE) {
			*(int *)((char*)src + offset) = empty;
			offset += 4;
			if (length < len) len = length;
			for (int i = 0; i < len; i++)
				*((char *)src + offset + i) = value[i];
		}

		bool checkBuffer(void *src, int offset = 0) {
			for (int i = 0; i <= length; i++)
				if (*((char *)src + offset + i) != value[i])
					return false;
			return true;
		}

		~VarChar() {
			if (value != NULL) free(value);
		}
};

#endif