#ifndef EXPRESSION_H
#define EXPRESSION_H
#define TREE_OP_NOT 0
#define TREE_OP_NEG 1
#define TREE_OP_PLUS 2
#define TREE_OP_MINUS 3
#define TREE_OP_AND 4
#define TREE_OP_OR 5
#define TREE_OP_XOR 6
#define TREE_OP_SELF 7
#define TREE_OP_LT 8
#define TREE_OP_GT 9
#define TREE_OP_LE 10
#define TREE_OP_GE 11
#define TREE_OP_EQ 12
#define TREE_OP_NEQ 13
#define TREE_OP_IS 14
#define TREE_OP_MINUS1 15


#include <cstdio>
#include <vector>
#include <cstdlib>
#include <string>
#include <regex>
#include <cstring>

struct RebackEntity {

	int intValue, tip;
	std::string strValue;

	void setEmpty(int value) {
		if (value == 1) tip = -1;
	}

	void setString(std::string con) {
		tip = 1;
		strValue = con;
	}
	
	void setInteger(int con) {
		intValue = con;
		tip = 0;
	}

	RebackEntity() {
		tip = -2;
	}

	RebackEntity(std::string con) {
		strValue = con;
		tip = 1;
	}

	RebackEntity(int con) {
		intValue = con;
		tip = 0;
	}

};

struct RebackTable {
	std::vector<std::string> tableNameLists;
	std::vector<RebackEntity> tableValueLists;

	RebackTable() {
		tableValueLists.clear();
		tableNameLists.clear();
	}

	void setEntity(std::string name, RebackEntity entity) {
		tableValueLists.push_back(entity);
		tableNameLists.push_back(name);
	}

	RebackEntity find(std::string name) {
		for (int i = tableNameLists.size() - 1; i >= 0; i--)
			if (tableNameLists[i] == name) return tableValueLists[i];
	}

	void show() {
		for (int  i = 0; i < tableNameLists.size(); i++) {
			if (tableValueLists[i].tip == -1) printf("\t NULL"); else
			if (tableValueLists[i].tip == 0) printf("\t%d", tableValueLists[i].intValue ); else
			printf("\t\'%s\'", tableValueLists[i].strValue.c_str());
		}
	}
};


struct Compare {
	std::vector<std::string> nameLists;
	std::vector<RebackTable> dataLists;
	int tot;

	Compare() {
		tot = 0;
		nameLists.clear();
		dataLists.clear();		
	}

	void setInitial() {
		tot = 0;
		nameLists.clear();
		dataLists.clear();
	}

	void setValue(std::string table, std::string name, std::string &strValue, int &intValue, int &empty) {
		for (int i = 0; i < tot; i++)
			if (table == nameLists[i]) {
				for (int j = dataLists[i].tableNameLists.size() - 1; j>=0; j--)
					if (dataLists[i].tableNameLists[j] == name) {
					if (dataLists[i].tableValueLists[j].tip == -1) empty = 1; else {
						if (dataLists[i].tableValueLists[j].tip == 0) intValue = dataLists[i].tableValueLists[j].intValue; else
						strValue = dataLists[i].tableValueLists[j].strValue;
						empty = 0;
					}
					return;
				}
			}
	}

	int setValue1(std::string table, std::string name, std::string &strValue, int &intValue, int &empty) {
		for (int i = 0; i < tot; i++)
			if (table == nameLists[i]) {
				for (int j = dataLists[i].tableNameLists.size() - 1; j>=0; j--)
					if (dataLists[i].tableNameLists[j] == name) {
					if (dataLists[i].tableValueLists[j].tip == -1) empty = 1; else {
						if (dataLists[i].tableValueLists[j].tip == 0)
							intValue = dataLists[i].tableValueLists[j].intValue;
						else {
							strValue = dataLists[i].tableValueLists[j].strValue;
							return 1;
						}
						empty = 0;
					}
					return 0;
				}
			}
	}

	void setValue(std::string table, std::string name, std::string &strValue, int &intValue, int &empty, int &tip) {
		for (int i = 0; i < tot; i++)
			if (table == nameLists[i]) {
				for (int j = dataLists[i].tableNameLists.size() - 1; j>=0; j--)
					if (dataLists[i].tableNameLists[j] == name) {
					if (dataLists[i].tableValueLists[j].tip == -1) {
						empty = 1;
						tip = -1; 
					}
					else {
						if (dataLists[i].tableValueLists[j].tip == 0) {
							intValue = dataLists[i].tableValueLists[j].intValue; 
							tip = 0;
						}
						else {
							strValue = dataLists[i].tableValueLists[j].strValue;
							tip = 1;
						}
						empty = 0;
					}
					return;
				}
			}
	}

	void push(std::string name, RebackTable table) {
		if (tot < nameLists.size()) {
			nameLists[tot] = name;
			dataLists[tot] = table;
		} else {
			nameLists.push_back(name);
			dataLists.push_back(table);
		}
		tot++;
	}

	void erase() {
		tot--;
	}

	void show() {
		for (int i = 0; i < tot; i++)
			dataLists[i].show();
	}

	void show(std::string table, std::string name) {
		for (int i = 0; i < tot; i++)
			if (table == nameLists[i]) {
				for (int j = dataLists[i].tableNameLists.size() - 1; j>=0; j--)
					if (dataLists[i].tableNameLists[j] == name) {
						if (dataLists[i].tableValueLists[j].tip == -1) printf("\t NULL"); else
						if (dataLists[i].tableValueLists[j].tip == 0) printf("\t%d", dataLists[i].tableValueLists[j].intValue ); else
						printf("\t\'%s\'", dataLists[i].tableValueLists[j].strValue.c_str());
						return;
					}
				return;
			}
	}
};


struct DBIdent {
	int work;
	std::string table;
	std::string ident;
};

extern Compare static_compare;

class Expr {

public:
	int intValue;
	std::string strValue;
	bool boolValue;

	int type;
	int valueType;
	int value;

	void setType(int con) {
		type = con;
	}

	void setValue(std::string con) {
		strValue = con;
	}

	void setValue(int con) {
		intValue = con;
	}

	void setValue(bool con) {
		boolValue = con;
	}

	virtual void setLefValue(int con) {}
	virtual void setLefValue(std::string con) {}
	virtual void setRigValue(int con) {}
	virtual void setRigValue(std::string con) {}

	virtual void flush(std::string con) {}

	virtual void setDBIdent(DBIdent con) {}
	virtual void setLefDBIdent(DBIdent con) {}
	virtual void setRigDBIdent(DBIdent con) {}

	virtual int calcValue() {return 0;};
	virtual int getValue() {return 0;};
 	virtual void deleteExpr() {};
};

class Unary : public Expr {

public:
	Expr *expr;

	Unary(Expr *con) {
		expr = con;
	}

	int calcValue() {
		if (type == TREE_OP_NOT) {
			value = !(bool)(expr -> calcValue());	
		} else 
		if (type == TREE_OP_NEG) {
			value = - expr -> calcValue();
		} else
			value = expr -> calcValue();
		return value;
	}

	int getValue() {
		return value;
	}

	void deleteExpr() {
		expr -> deleteExpr();
		delete expr;
	}

	void flush(std::string con) {
		expr -> flush(con);
	}
};

class Binary : public Expr {

public:
	Expr *expr1;
	Expr *expr2;

	Binary(Expr *lef, Expr *rig) {
		expr1 = lef;
		expr2 = rig;
	}

	int calcValue() {
		if (type == TREE_OP_PLUS) {
			value = expr1 -> calcValue() + expr2 -> calcValue();
		} else 
		if (type == TREE_OP_MINUS){
			value = expr1 -> calcValue() - expr2 -> calcValue();
		} else 
		if (type == TREE_OP_MINUS1){
			value = - expr1 -> calcValue() + expr2 -> calcValue();
		} else 		
		if (type == TREE_OP_AND) {
			value = (bool)(expr1 -> calcValue()) && (bool)(expr2 -> calcValue());
		} else
		if (type == TREE_OP_OR) {
			value = (bool)(expr1 -> calcValue()) || (bool)(expr2 -> calcValue());
		} else
		if (type == TREE_OP_XOR) {
			value = (bool)(expr1 -> calcValue()) ^ (bool)(expr2 -> calcValue());
		}
		return value;
	}

	int getValue() {
		return value;
	}

	void deleteExpr() {
		expr1 -> deleteExpr();
		delete expr1;
		expr2 -> deleteExpr();
		delete expr2;
	}

	void flush(std::string con) {
		expr1 -> flush(con);
		expr2 -> flush(con);
	}
};

class ConstExpr : public Expr {

public:

	ConstExpr() {
	}

	int calcValue() {
		value = 1;
	}

	int getValue() {
		return value;
	}

	void deleteExpr() {
	}

	void flush(std::string con) {
	}
};

class Id2Id : public Expr {

public:

	std::string lefStrValue, rigStrValue;
	int lefIntValue, rigIntValue;
	DBIdent lefIdent, rigIdent;

	void setRigDBIdent(DBIdent con) {
		rigIdent = con;
	}

	void setLefDBIdent(DBIdent con) {
		lefIdent = con;
	}

	void setValueType(int con) {
		valueType = con;
	}

	void setLefValue(std::string con) {
		lefStrValue = con;
	}

	void setLefValue(int con) {
		lefIntValue = con;
	}

	void setRigValue(std::string con) {
		rigStrValue = con;
	}

	void setRigValue(int con) {
		rigIntValue = con;
	}

	int calcValue() {
		int con;
		valueType = static_compare.setValue1(lefIdent.table, lefIdent.ident, lefStrValue, lefIntValue, con);
		valueType = static_compare.setValue1(rigIdent.table, rigIdent.ident, rigStrValue, rigIntValue, con);
		if (valueType) {
			if (type == TREE_OP_LT) {
				value = lefStrValue < rigStrValue;
			} else
			if (type == TREE_OP_GT) {
				value = lefStrValue > rigStrValue;
			} else
			if (type == TREE_OP_LE) {
				value = lefStrValue <= rigStrValue;
			} else
			if (type == TREE_OP_GE) {
				value = lefStrValue >= rigStrValue;
			} else
			if (type == TREE_OP_EQ) {
				value = lefStrValue == rigStrValue;
			}
		} else {
			if (type == TREE_OP_LT) {
				value = lefIntValue < rigIntValue;
			} else
			if (type == TREE_OP_GT) {
				value = lefIntValue > rigIntValue;
			} else
			if (type == TREE_OP_LE) {
				value = lefIntValue <= rigIntValue;
			} else
			if (type == TREE_OP_GE) {
				value = lefIntValue >= rigIntValue;
			} else
			if (type == TREE_OP_EQ) {
				value = lefIntValue == rigIntValue;
			}			
		}
		return value;
	}

	int getValue() {
		return value;
	}

	void deleteExpr() {}

	void flush(std::string con) {
		lefIdent.table = con;
		rigIdent.table = con;
	}
};

class Id2Num: public Expr {

public:

	int compare;
	DBIdent ident;

	void setDBIdent(DBIdent con) {
		ident = con;
	}

	Id2Num(int num) {
		compare = num;
	}

	int calcValue() {
		int con;
		static_compare.setValue(ident.table, ident.ident, strValue, intValue, con);
		if (type == TREE_OP_LT) {
			value = intValue < compare;
		} else
		if (type == TREE_OP_GT) {
			value = intValue > compare;
		} else
		if (type == TREE_OP_LE) {
			value = intValue <= compare;
		} else
		if (type == TREE_OP_GE) {
			value = intValue >= compare;
		} else
		if (type == TREE_OP_EQ) {
			value = intValue == compare;
		} else
		if (type == TREE_OP_PLUS) {
			value = intValue + compare;
		} else
		if (type == TREE_OP_MINUS) {
			value = intValue - compare;
		} else
		if (type == TREE_OP_MINUS1) {
			value = - intValue + compare;
		}		
		return value;
	}

	int getValue() {
		return value;
	}

	void deleteExpr() {}

	void flush(std::string con) {
		ident.table = con;
	}
};

class Id2Str: public Expr {

public:
	
	std::string compare;
	DBIdent ident;
	std::regex pat;
	std::smatch mat;

	void setDBIdent(DBIdent con) {
		ident = con;
	}

	Id2Str(std::string str) {
		compare = str;
		pat  = std::regex(compare);
	}

	int calcValue() {
		static_compare.setValue(ident.table, ident.ident, strValue, intValue, intValue);
		if (type == TREE_OP_LT) {
			value = strValue < compare;
		} else
		if (type == TREE_OP_GT) {
			value = strValue > compare;
		} else
		if (type == TREE_OP_LE) {
			value = strValue <= compare;
		} else
		if (type == TREE_OP_GE) {
			value = strValue >= compare;
		} else
		if (type == TREE_OP_EQ) {
			value = regex_match(strValue, mat, pat);
		}
		return value;
	}

	int getValue() {
		return value;
	}

	void deleteExpr() {}

	void flush(std::string con) {
		ident.table = con;
	}
};

class IdIsNULL : public Expr {

public:
	
	DBIdent ident;

	void setDBIdent(DBIdent con) {
		ident = con;
	}

	IdIsNULL() {
	}

	int calcValue() {
		int con;
		static_compare.setValue(ident.table, ident.ident, strValue, intValue, value);
		return value;
	}

	int getValue() {
		return value;
	}

	void deleteExpr() {}

	void flush(std::string con) {
		ident.table = con;
	}

};


struct Assign {

	DBIdent dbident;
	int intValue;
	std::string strValue;
	int type;
	Expr *expr;

	Assign() {}

	Assign(DBIdent con, int value) {
		intValue = value;
		dbident = con;
		type = 0;
	}

	Assign(DBIdent con, std::string value) {
		strValue = value;
		dbident = con;
		type = 1;
	}

	Assign(DBIdent con) {
		dbident = con;
		type = -1;
	}

	Assign(DBIdent con, Expr *expr) {
		this -> expr = expr;
		dbident = con;
		type = -2;
	}
	
	void setEmpty() {
		type = -1;
	}

};

#endif