#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include "Entity.h"

const int MAX_BUFFER_SIZE = 8000;
const int MAX_PAGE_SIZE = 8192;
const int PAGE_HEADER = 96;

struct Table{
	std::string tableName;
	std::vector<std::string> name;
	std::vector<std::string> type;
	std::vector<int> len;
	std::vector<bool> empty;
	int sum;
	int size;
	std::string primarykey;
	std::vector<std::string> checkNameLists;
	std::vector<std::vector<PriceEntity> > checkValueLists ;

	Table() {
		name.clear();
		type.clear();
		len.clear();
		sum = 0;
		size = 0;
		primarykey = "";
		tableName = "";
	}

	void push(std::string nam, std::string typ, int le, bool empty) {
		this -> name.push_back(nam);
		this -> type.push_back(typ);
		this -> len.push_back(le);
		this -> empty.push_back(empty);
		if (typ == "int") this->size += 4+4; else 
		this -> size += le + 4;
		this -> sum++;
	}

	void push(std::string nam, std::vector<PriceEntity> entity) {
		checkNameLists.push_back(nam);
		checkValueLists.push_back(entity);
	}
};


#endif
