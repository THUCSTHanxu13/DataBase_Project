#ifndef TERMINAL_H
#define TERMINAL_H

#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include "DataFileManager.h"
#include "Header.h"
#include "Group.h"

Compare static_compare;

class DBManger {

	std::vector<std::string> dbList;
	std::vector<std::string> tbList;
	std::string pathName;
	std::vector<DataFileManager*> tbFileManager;
	FILE *file, *fileDB;
	bool DBOpenFlag;
	long long select_max;
	long long select_min;
	long long select_tot;
	long long select_sum;



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
		while (fscanf(file, "%s\n", DBname) == 1) {
			tbList.push_back(DBname);
			std::string name = DBname;
			int con = DataFileManagerIndex(name);
		}
		fclose(file);
	}

	void backTbList(std::string name) {
		file = fopen((name + "_datalist.txt").c_str(), "w");
		for (int i = tbList.size() - 1; i >= 0; i--)
			fprintf(file, "%s\n", tbList[i].c_str());
		fclose(file);
		for (int i = 0; i < tbFileManager.size(); i++)
			delete tbFileManager[i];
		tbFileManager.clear();	
	}

public:

	DBManger() {
		pathName = "";
		addDbList(pathName);
		DBOpenFlag = false;
	}

	~DBManger() {
		backDbList();
		if (DBOpenFlag) {
			DBOpenFlag = false;
			backTbList(pathName);
		}
	}

//***************************************************************************************
	
	void createDatabase(std::string condition) {
		if (!checkDbInList(condition)) {
			system(("mkdir " + condition).c_str());
			dbList.push_back(condition);
			file = fopen((condition + "/_datalist.txt").c_str(), "a");
			fclose(file);
		}
	}

	void createTable(std::string name, std::vector<TableEntity> TableEntityLists) {
		std::string condition = "";
		Table table;
		table.tableName = name;

		for (int i = 0; i < TableEntityLists.size(); i++)
			if (TableEntityLists[i].checkEntity.size() != 0) {
				table.push(TableEntityLists[i].ident, TableEntityLists[i].checkEntity);
			} else
			if (TableEntityLists[i].pri)
				table.primarykey = TableEntityLists[i].ident;
			else
				table.push(TableEntityLists[i].ident, TableEntityLists[i].type, TableEntityLists[i].len, TableEntityLists[i].empty);
		
		if (!checkTbInList(table.tableName)) {
			DataFileManager dataFileManager;
			dataFileManager.setFile(pathName + table.tableName);
			dataFileManager.setTable(table);
			dataFileManager.createFile();
			tbList.push_back(table.tableName);
		}
	}

//***************************************************************************************

	void useDatabase(std::string condition) {
		if (DBOpenFlag) {
			backTbList(pathName);
			DBOpenFlag = false;
			pathName = "";
		}
		if (checkDbInList(condition)) {
			pathName = condition + "/";
			DBOpenFlag = true;
			addTbList(pathName);
		}
	}

//***************************************************************************************
	
	void dropDatabase(std::string condition) {
		for (std::vector<std::string>::iterator iter = dbList.begin(); iter != dbList.end(); iter++) 
			if (*iter == condition) {
				dbList.erase(iter);
				system(("rm -r " + condition).c_str());
				break;
			}
	}

	void dropTable(std::string condition) {
		for (std::vector<std::string>::iterator iter = tbList.begin(); iter != tbList.end(); iter++) 
			if (*iter == condition) {
				tbList.erase(iter);
				system(("rm " + pathName + condition).c_str());
				break;
			}
	}

//***************************************************************************************
	
	void showDatabase(std::string condition) {
		if (checkDbInList(condition)) {
			FILE *fin = fopen((condition + "/_datalist.txt").c_str(), "r");
			char buffer[1000];
			while (fscanf(fin, "%s", buffer) == 1) {
				printf("%s\n", buffer);
			}
			fclose(fin);
		}
	}

	void showTable(std::string condition) {
		if (checkTbInList(condition)) {
			DataFileManager dataFileManager;
			dataFileManager.setFile(pathName + condition);
			dataFileManager.openFile();
			dataFileManager.showTable();
		}
	}

//***************************************************************************************

	int DataFileManagerIndex(std::string &name) {
		for (int i = tbFileManager.size() - 1; i >= 0; i--)
			if (tbFileManager[i]->path == pathName + name) return i;
		DataFileManager *dataFileManager = new DataFileManager(&tbFileManager);
		dataFileManager->setTableName(name);
		dataFileManager->setFile(pathName + name);
		dataFileManager->openFile();
		tbFileManager.push_back(dataFileManager);
		return tbFileManager.size() - 1;
	}

	void insertIntoValues(std::string name, std::vector<std::vector<PriceEntity> >ValueEntityLists) {
		if (!checkTbInList(name)) return;
		int dataFileManagerIndex = DataFileManagerIndex(name);
		for (int i = 0; i < ValueEntityLists.size();i++ ) {
			std::vector<std::string> content;
			content.clear();
			bool flag = true;
			for (int j = 0; j< ValueEntityLists[i].size(); j++)
				if (ValueEntityLists[i][j].tip == 0) {
					if (!tbFileManager[dataFileManagerIndex]->check(j, ValueEntityLists[i][j].num)) {
						flag = false;
						break;
					}
					std::stringstream newstr;
					newstr<<ValueEntityLists[i][j].num;
					content.push_back(newstr.str());
				}
				else
				if (ValueEntityLists[i][j].tip == 1) {
					if (!tbFileManager[dataFileManagerIndex]->check(j, ValueEntityLists[i][j].str)) {
						flag = false;
						break;
					}
					content.push_back(ValueEntityLists[i][j].str);
				} else {
					if (!tbFileManager[dataFileManagerIndex]->checkCanBeEmpty(j))
						content.push_back("#NULL");
					else {
						flag = false;
						break;
					}
				}
			if (flag)
				tbFileManager[dataFileManagerIndex]->insert(content);
			else
				printf("\t Error in update : value is not in the check list\n");
		}
	}

	void find(int lef, int rig, std::vector<DBIdent> &tbIdentLists, Expr *expr) {
		if (lef == rig) {
			if (expr -> calcValue()) {
				static_compare.show();
				printf("\n");
			}
			return;
		}
		std::string name = tbIdentLists[lef].ident;
		int dataFileManagerIndex = DataFileManagerIndex(name);
		tbFileManager[dataFileManagerIndex]->finderInitial();
		while (true) {
			RebackTable res = tbFileManager[dataFileManagerIndex]->finderNext();
			if (res.tableNameLists.size() == 0) break;
			static_compare.push(tbIdentLists[lef].ident, res);
			find(lef + 1, rig, tbIdentLists, expr);
			static_compare.erase();
		}
	}


	void find(int lef, int rig, std::vector<DBIdent> &identLists, std::vector<DBIdent> &tbIdentLists, Expr *expr) {
		if (lef == rig) {
			if (expr -> calcValue()) {
				for (int i = 0; i < identLists.size(); i++)
					if (identLists[i].work == -1) {
						static_compare.show(identLists[i].table, identLists[i].ident); 
					}else 
					{
						std::string str;
						int con;
						int empty;
						static_compare.setValue(identLists[i].table, identLists[i].ident, str, con, empty);
						if (!empty) {
							if (con > select_max) select_max =  con;
							if (con < select_min) select_min =  con;
							select_tot+=1;
							select_sum+=con;
						}
					}
				printf("\n");
			}	
			return;
		}
		std::string name = tbIdentLists[lef].ident;
		int dataFileManagerIndex = DataFileManagerIndex(name);
		tbFileManager[dataFileManagerIndex]->finderInitial();
		while (true) {
			RebackTable res = tbFileManager[dataFileManagerIndex]->finderNext();
			if (res.tableNameLists.size() == 0) break;
			static_compare.push(tbIdentLists[lef].ident, res);
			find(lef + 1, rig, identLists, tbIdentLists, expr);
			static_compare.erase();
		}

	}

	void selectAllFromTable(std::vector<DBIdent> tbIdentLists, Expr *expr) {
		select_max = -2147483647;
		select_min =  2147483647;
		select_tot = 0;
		select_sum = 0;

		if (tbIdentLists.size() == 1) {
			expr -> flush(tbIdentLists[0].ident);
		}
		static_compare.setInitial();
		printf("select : \n");
		find(0, tbIdentLists.size(), tbIdentLists, expr);
	}

	void selectFromTable(std::vector<DBIdent> identLists, std::vector<DBIdent> tbIdentLists, Expr *expr) {
		select_max = -2147483647;
		select_min =  2147483647;
		select_tot = 0;
		select_sum = 0;

		if (tbIdentLists.size() == 1) {
			for (int i = 0; i < identLists.size(); i++)
				identLists[i].table = tbIdentLists[0].ident;
			expr -> flush(tbIdentLists[0].ident);
		}
		static_compare.setInitial();
		printf("select : \n");
		find(0, tbIdentLists.size(), identLists, tbIdentLists, expr);
		if (select_tot != 0) {
			if (identLists[0].work == 0) printf("\t%lld\n", select_sum); else
			if (identLists[0].work == 1) printf("\t%lf\n", (double)select_sum / (double)(select_tot)); else
			if (identLists[0].work == 2) printf("\t%lld\n", select_max); else
			if (identLists[0].work == 3) printf("\t%lld\n", select_min); 
		}
	}

	std::vector<GroupList> groupConditon;
	int GroupTitleTot;

	void groupHashInitial(int con) {
		groupConditon.clear();
		GroupTitleTot = con;
	}


	void find(int lef, int rig, std::vector<DBIdent> &identLists, std::vector<DBIdent> &tbIdentLists, std::vector<DBIdent> &groupLists) {
		if (lef == rig) {
			GroupList grouplist;
			for (int i = 0; i < identLists.size(); i++)  {
				std::string str;
				int con;
				int empty;
				int tip;
				static_compare.setValue(identLists[i].table, identLists[i].ident, str, con, empty, tip);
				if (identLists[i].work != -1) {
					grouplist.push(identLists[i].table, identLists[i].ident, con, identLists[i].work);
				} else {
					if (tip == 0)
						grouplist.push(identLists[i].table, identLists[i].ident, con);
					else
						grouplist.push(identLists[i].table, identLists[i].ident, str);
				}
			}
			for (int  i = groupConditon.size() - 1; i >= 0; i--)
				if (groupConditon[i].checkEqual(grouplist)) {
					groupConditon[i].push(grouplist);
					return;
				}
			groupConditon.push_back(grouplist);
			return;
		}
		std::string name = tbIdentLists[lef].ident;
		int dataFileManagerIndex = DataFileManagerIndex(name);
		tbFileManager[dataFileManagerIndex]->finderInitial();
		while (true) {
			RebackTable res = tbFileManager[dataFileManagerIndex]->finderNext();
			if (res.tableNameLists.size() == 0) break;
			static_compare.push(tbIdentLists[lef].ident, res);
			find(lef + 1, rig, identLists, tbIdentLists, groupLists);
			static_compare.erase();
		}
	}

	void selectFromTable(std::vector<DBIdent> identLists, std::vector<DBIdent> tbIdentLists, std::vector<DBIdent> groupLists) {
		if (tbIdentLists.size() == 1) {
			for (int i = 0; i < identLists.size(); i++)
				identLists[i].table = tbIdentLists[0].ident;
			for (int i = 0; i < groupLists.size(); i++)
				groupLists[i].table = tbIdentLists[0].ident;
		}
		groupHashInitial(groupLists.size());
		static_compare.setInitial();
		printf("select : \n");
		find(0, tbIdentLists.size(), identLists, tbIdentLists, groupLists);
		for (int  i = groupConditon.size() - 1; i >= 0; i--) {
			groupConditon[i].show();
		}
	}

	void updateTable(std::string name, std::vector<Assign> assignLists, Expr *expr) {
		if (!checkTbInList(name)) return;
		expr->flush(name);
		static_compare.setInitial();
		int dataFileManagerIndex = DataFileManagerIndex(name);
		tbFileManager[dataFileManagerIndex]->finderInitial();
		while (true) {
			RebackTable res = tbFileManager[dataFileManagerIndex]->finderNext();
			if (res.tableNameLists.size() == 0) break;
			static_compare.push(name, res);
			if (expr -> calcValue()) {
				printf("update : \n");
				res.show();
				printf("\n");
				tbFileManager[dataFileManagerIndex]->updateInitial();
				tbFileManager[dataFileManagerIndex]->setNowData();
				bool flag = true;
				for (int i = 0; i < assignLists.size(); i++)
					if (assignLists[i].type == 1) {
						if (!tbFileManager[dataFileManagerIndex] -> check(assignLists[i].dbident.ident, assignLists[i].strValue)) {
							flag = false;
							break;
						}
						tbFileManager[dataFileManagerIndex] -> update(assignLists[i].dbident.ident, assignLists[i].strValue); 
					}
					else
					if (assignLists[i].type == 0) {
						if (!tbFileManager[dataFileManagerIndex] -> check(assignLists[i].dbident.ident, assignLists[i].intValue)) {
							flag = false;
							break;
						}
						tbFileManager[dataFileManagerIndex] -> update(assignLists[i].dbident.ident, assignLists[i].intValue);
					}
					else 
					if (assignLists[i].type == -1)
					{
						if (!tbFileManager[dataFileManagerIndex]->checkCanBeEmpty(i))
							tbFileManager[dataFileManagerIndex] -> update(assignLists[i].dbident.ident, "#NULL");
						else {
							flag = false;
							break;
						}
					} else {
						 assignLists[i].expr->flush(name);
						int intValue = assignLists[i].expr->calcValue();
						if (!tbFileManager[dataFileManagerIndex] -> check(assignLists[i].dbident.ident, intValue)) {
							flag = false;
							break;
						}
						tbFileManager[dataFileManagerIndex] -> update(assignLists[i].dbident.ident, intValue);
					}
				if (flag)
					tbFileManager[dataFileManagerIndex]->update();
				else
					printf("\t Error in update : value is not in the check list\n");
			}
			static_compare.erase();
		}
	}

	void deleteTable(std::string name, Expr *expr) {
		if (!checkTbInList(name)) return;
		expr->flush(name);
		static_compare.setInitial();
		int dataFileManagerIndex = DataFileManagerIndex(name);
		tbFileManager[dataFileManagerIndex]->finderInitial();
		while (true) {
			RebackTable res = tbFileManager[dataFileManagerIndex]->finderNext();
			if (res.tableNameLists.size() == 0) break;
			static_compare.push(name, res);
			if (expr -> calcValue()) {
				printf("delete : \n");
				tbFileManager[dataFileManagerIndex]->del();
				res.show();
				printf("\n");
			}
			static_compare.erase();
		}
	}

	bool findKey(std::string table, std::string name, std::string title) {
		if (!checkTbInList(name)) return false;
		int dataFileManagerIndex = DataFileManagerIndex(table);
		return tbFileManager[dataFileManagerIndex]->tree.find(title);
	}

	bool findKey(std::string table, std::string name, int title) {
		if (!checkTbInList(name)) return false;
		int dataFileManagerIndex = DataFileManagerIndex(table);
		return tbFileManager[dataFileManagerIndex]->tree.find(title);
	}

};

#endif
