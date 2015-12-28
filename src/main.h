#ifndef MAIN_HPP
#define MAIN_HPP

#include "Expr.h"
#include "Entity.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

struct TableStmt {
	std::vector<TableEntity> TableEntityLists;
	std::string strValue;
};

class Tree {

public : 

	std::string strValue;
	int intValue;
	
	ValueEntity valueEntity;
	
	TableEntity tableEntity;
	std::vector<TableEntity> TableEntityLists;

	std::vector<PriceEntity> PriceEntityLists;
	std::vector<std::vector<PriceEntity> >ValueEntityLists;

	DBIdent dbIdent;
	std::vector<DBIdent> dbIdentLists;

	Expr *expr;

	Assign assign;
	std::vector<Assign> assignLists;

	TableStmt tableStmt;

};

#define YYSTYPE Tree

#endif
