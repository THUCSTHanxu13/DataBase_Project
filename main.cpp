#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <iostream>
#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include "DataFileManager.h"
#include "Header.h"

using namespace std;

class DBManger {

	std::vector<std::string> dbList;
	std::vector<std::string> tbList;
	std::string pathName;
	std::vector<DataFileManager*> tbFileManager;
	FILE * file, *fileDB;
	bool DBOpenFlag;

private:
	bool check(char tip) {
		if (tip == '\t' || tip == ' ' || tip == ';') return false;
		return true;
	}

	bool checkDbInList(std::string name) {
		for (int i =dbList.size() - 1; i >= 0; i--)
			if (dbList[i] == name) return true;
		return false;
	}

	bool checkTbInList(std::string name) {
		for (int i = tbList.size() - 1; i >= 0; i--)
			if (tbList[i] == name) return true;
		return false;
	}

	void addDbList(std::string name) {
		file = fopen((name + "_datalist.txt").c_str(), "a");
		fclose(file);
		char DBname[1000];
		dbList.clear();
		file = fopen((name + "_datalist.txt").c_str(), "r");
		while (fscanf(file, "%s\n", DBname) == 1)
			dbList.push_back(DBname);
		fclose(file);
	}

	void backDbList() {
		file = fopen("_datalist.txt", "w");
		for (int i = dbList.size() - 1; i >= 0; i--)
			fprintf(file, "%s\n", dbList[i].c_str());
		fclose(file);
	}

	void addTbList(std::string name) {
		file = fopen((name + "_datalist.txt").c_str(), "a");
		fclose(file);
		char DBname[1000];
		tbList.clear();
		tbFileManager.clear();
		file = fopen((name + "_datalist.txt").c_str(), "r");
		while (fscanf(file, "%s\n", DBname) == 1)
			tbList.push_back(DBname);
		fclose(file);
	}

	void backTbList(std::string name) {
		file = fopen((name + "_datalist.txt").c_str(), "w");
		for (int i = tbList.size() - 1; i >= 0; i--)
			fprintf(file, "%s\n", tbList[i].c_str());
		fclose(file);	
	}

	void analyseTable(std::string &inst, int &lef, int len, Table &table) {
		std::string condition = "";
		std::string ln = "";
		std::string tp = "";
		bool empty;
		bool flag = false;
		while (lef < len) {
			char tip =  inst[lef++];
			if (tip == '(') {
				tp = condition;
				condition = "";
				flag = true;
			} else
			if (tip == ')' && flag) {
				ln = condition;
				condition = "";
				flag = false;
			} else
			if (tip == ',' || tip == ')') {
				if (condition == "NOTNULL") empty = false; else empty = true;
				condition = "";
				if (tp == "PRIMARYKEY") {
					table.primarykey = ln;
				} else  {
					int len = tp.length();
					if (tp[len - 1] == 't') {
						table.push(tp.substr(0, len - 3), "int", atoi(ln.c_str()), empty);
					} else
					if (tp[len - 1] == 'r') {
						table.push(tp.substr(0, len - 7), "varchar", atoi(ln.c_str()), empty);
					}
				}
			}  else
			if (check(tip))
				condition = condition + tip;
		}
	}

public:

	DBManger() {
		pathName = "";
		addDbList(pathName);
		DBOpenFlag = false;
	}

	~DBManger() {
		for (int i = 0; i < tbFileManager.size(); i++)
			delete tbFileManager[i];
		backDbList();
		if (DBOpenFlag) {
			DBOpenFlag = false;
			backTbList(pathName);
		}
	}

//***************************************************************************************
	
	void createDatabase(std::string &inst, int &lef, int len) {
		std::string condition = "";
		while (lef < len) {
			char tip =  inst[lef++];
			if (check(tip))
				condition = condition + tip;
		}
		if (!checkDbInList(condition)) {
			system(("mkdir " + condition).c_str());
			dbList.push_back(condition);
			file = fopen((condition + "/_datalist.txt").c_str(), "a");
			fclose(file);
		}
	}

	void createTable(std::string &inst, int &lef, int len) {
		std::string condition = "";
		Table table;
		while (lef < len) {
			char tip =  inst[lef++];
			if (tip == '(') {
				table.tableName = condition;
				condition = "";
				analyseTable(inst, lef, len, table);
			} else
			if (check(tip))
				condition = condition + tip;
		}
		if (!checkTbInList(table.tableName)) {
			DataFileManager dataFileManager;
			dataFileManager.setFile(pathName + table.tableName);
			dataFileManager.setTable(table);
			dataFileManager.createFile();
			tbList.push_back(table.tableName);
		}
	}

//***************************************************************************************

	void useDatabase(std::string &inst, int &lef, int len) {
		if (DBOpenFlag) {
			backTbList(pathName);
			DBOpenFlag = false;
			pathName = "";
		}
		std::string condition = "";
		while (lef < len) {
			char tip =  inst[lef++];
			if (check(tip))
				condition = condition + tip;
		}
		if (checkDbInList(condition)) {
			pathName = condition + "/";
			DBOpenFlag = true;
			addTbList(pathName);
		}
	}

//***************************************************************************************
	
	void dropDatabase(std::string &inst, int &lef, int len) {
		std::string condition = "";
		while (lef < len) {
			char tip =  inst[lef++];
			if (check(tip))
				condition = condition + tip;
		}
		for (std::vector<std::string>::iterator iter = dbList.begin(); iter != dbList.end(); iter++) 
			if (*iter == condition) {
				dbList.erase(iter);
				system(("rm -r " + condition).c_str());
				break;
			}
	}

	void dropTable(std::string &inst, int &lef, int len) {
		std::string condition = "";
		while (lef < len) {
			char tip =  inst[lef++];
			if (check(tip))
				condition = condition + tip;
		}
		for (std::vector<std::string>::iterator iter = tbList.begin(); iter != tbList.end(); iter++) 
			if (*iter == condition) {
				tbList.erase(iter);
				system(("rm " + pathName + condition).c_str());
				break;
			}
	}

//***************************************************************************************
	
	void showDatabase(std::string &inst, int &lef, int len) {
		std::string condition = "";
		while (lef < len) {
			char tip =  inst[lef++];
			if (check(tip))
				condition = condition + tip;
		}
		if (checkDbInList(condition)) {
			FILE *fin = fopen((condition + "/_datalist.txt").c_str(), "r");
			char buffer[1000];
			while (fscanf(fin, "%s", buffer) == 1) {
				printf("%s\n", buffer);
			}
			fclose(fin);
		}
	}

	void showTable(std::string &inst, int &lef, int len) {
		std::string condition = "";
		while (lef < len) {
			char tip =  inst[lef++];
			if (check(tip))
				condition = condition + tip;
		}
		if (checkTbInList(condition)) {
			DataFileManager dataFileManager;
			dataFileManager.setFile(pathName + condition);
			dataFileManager.openFile();
			dataFileManager.showTable();
		}
	}

//***************************************************************************************
	void create(std::string &inst, int &lef, int len) {
		std::string condition = "";
		while (lef < len) {
			char tip =  inst[lef++];
			if (check(tip))
				condition = condition + tip;
			if (condition == "DATABASE") createDatabase(inst, lef, len);
			if (condition == "TABLE") createTable(inst, lef, len);
		}
	}

	void use(std::string &inst, int &lef, int len) {
		useDatabase(inst, lef, len);
	}

	void drop(std::string &inst, int &lef, int len) {
		std::string condition = "";
		while (lef < len) {
			char tip =  inst[lef++];
			if (check(tip))
				condition = condition + tip;
			if (condition == "DATABASE") dropDatabase(inst, lef, len);
			if (condition == "TABLE") dropTable(inst, lef, len);
		}
	}

	void show(std::string &inst, int &lef, int len) {
		std::string condition = "";
		while (lef < len) {
			char tip =  inst[lef++];
			if (check(tip))
				condition = condition + tip;
			if (condition == "DATABASE") showDatabase(inst, lef, len);
			if (condition == "TABLE") showTable(inst, lef, len);
		}		
	}

	int DataFileManagerIndex(std::string &name) {
		for (int i = tbFileManager.size() - 1; i >= 0; i--)
			if (tbFileManager[i]->path == pathName + name) return i;
		DataFileManager *dataFileManager = new DataFileManager();
		dataFileManager->setFile(pathName + name);
		dataFileManager->openFile();
		tbFileManager.push_back(dataFileManager);
		return tbFileManager.size() - 1;
	}

	void insertIntoValues(std::string &inst, int &lef, int len, std::string &name) {
		if (!checkTbInList(name)) {
			lef = len;
			return;
		}
		int dataFileManagerIndex = DataFileManagerIndex(name);
		std::string condition = "";
		std::vector<std::string> content;
		bool flag = false;
		while (lef < len) {
			char tip =  inst[lef++];
			if (tip == ')') {
				content.push_back(condition);
				tbFileManager[dataFileManagerIndex]->insert(content);
				condition = "";
			} else
			if (tip == '(') {
				content.clear();
				condition = "";
			} else 
			if (tip == ',')
			{
				content.push_back(condition);
				condition = "";
			} else
			if (tip == '\'') {
				flag = not flag;
			} else 
			if (flag || check(tip)) {
				condition = condition + tip;
			}
		}
	}

	void insertInto(std::string &inst, int &lef, int len) {
		std::string condition = "";
		std::string tip = "";
		while (lef < len) {
			char ch =  inst[lef++];
			if (!check(ch)) continue;
			if (tip == "") {
				if (ch == 'V') {
					tip = "V";
				} else {
					condition = condition + tip + ch;
					tip = "";
				}
			} else
			if (tip == "V") {
				if (ch == 'A') {
					tip = "VA";
				} else {
					condition = condition + tip + ch;
					tip = "";
				}
			} else
			if (tip == "VA") {
				if (ch == 'L') {
					tip = "VAL";
				} else {
					condition = condition + tip + ch;
					tip = "";
				}
			} else
			if (tip == "VAL") {
				if (ch == 'U') {
					tip = "VALU";
				} else {
					condition = condition + tip + ch;
					tip = "";
				}
			} else
			if (tip == "VALU") {
				if (ch == 'E') {
					tip = "VALUE";
				} else {
					condition = condition + tip + ch;
					tip = "";
				}
			} else
			if (tip == "VALUE") {
				if (ch == 'S') {
					insertIntoValues(inst, lef, len, condition);
				}
			}
		}
	}

	void insert(std::string &inst, int &lef, int len) {
		std::string condition = "";
		while (lef < len) {
			char tip =  inst[lef++];
			if (check(tip))
				condition = condition + tip;
			if (condition == "INTO") insertInto(inst, lef, len);
		}
	}


//***************************************************************************************

	void run(std::string &inst, int &lef, int len) {
		std::string condition = "";
		while (lef < len) {
			char tip =  inst[lef++];
			if (check(tip))
				condition = condition + tip;
			if (condition == "CREATE") create(inst, lef, len);
			if (condition == "USE") use(inst, lef, len);
			if (condition == "DROP") drop(inst, lef, len);
			if (condition == "SHOW") show(inst, lef, len);
			if (condition == "INSERT") insert(inst, lef, len);
		}
	}

	void run(std::string &inst) {
		int lef = 0;
		int rig = inst.length();
		run(inst, lef, rig);
	}
};

int main() {
	DBManger dbma;
	FILE * fin = fopen("dataset_small/orders.sql", "r");
	std::string inst = "";
	char tip;
	while (fscanf(fin, "%c", &tip) == 1) {
		if (tip == '\n' || tip == ' ' || tip == '\r') continue; else
		if (tip == ';')  {
			dbma.run(inst);
			inst = "";
		} else {
			inst = inst + tip;
		}
	}
	fclose(fin);
	return 0;
}

