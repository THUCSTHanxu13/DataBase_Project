#ifndef ENTITY_H
#define ENTITY_H
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include "Entity.h"

struct PriceEntity {
	int num;
	std::string str;
	int tip;

	PriceEntity() {
		num = 0;
		str = "";
		tip = 0;
	}

	PriceEntity(int num, int t = 0) {
		if (t == 0) {
			this->num = num;
			tip = 0;
		} else tip = -1;
	}

	PriceEntity(std::string str, int t = 0) {
		if (t == 0) {
			this->str = str;
			tip = 1;
		} else tip = -1;
	}
};

struct ValueEntity {
	std::vector<PriceEntity> lists;
};

struct TableEntity {

	bool empty, pri;
	int len;
	std::string ident;
	std::string type;
	std::vector<PriceEntity> checkEntity;

	TableEntity(){}

	TableEntity(std::string ident, std::string type, int len, bool empty = false, bool pri = false) {
		this -> empty = empty;
		this -> type = type;
		this -> ident = ident;
		this -> len = len;
		this -> pri = pri;
		checkEntity.clear();
	}

	TableEntity(std::string ident, std::vector<PriceEntity> checkEntity) {
		empty = 0;
		this->ident = ident;
		this->len = 0;
		this -> pri = 0;
		this -> type = "";
		this -> checkEntity = checkEntity;
	}
};

#endif