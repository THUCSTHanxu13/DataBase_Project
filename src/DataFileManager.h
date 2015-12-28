#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "DataStruct.h"
#include "DataType.h"
#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <unistd.h>
#include "SearchTree.h"

class DataFileManager {

	private:
		int fileID;
		Table table;
		int finderTot, finderPage, currentPage;
		std::string primarykeyName;
		int primaryRank;
		int primaryType;
		std::string updateStr;
		int updateInt;
		std::vector<std::string> constrainleft, constrainright;

		void writeString(char * &last, std::string name) {
			int len = name.length();
			memcpy(last, &len, 4);
			last = last + 4;
			for (int i = 0; i < len; i++) {
				*last = name[i];
				last = last + 1;
			}
		}

		std::string readString(char * &last, int len) {
			std::string res = "";
			for (int i = 0; i < len; i++) {
				res = res + *last;
				last++;
			}
			return res;
		}

		int readInteger(char * &last) {
			int res = *(int *)(last);
			last = last + 4;
			return res;
		}

		void writeInteger(char * &last, int len) {
			memcpy(last, &len, 4);
			last = last + 4;			
		}

		void constrain(std::string con) {
			std::string lef = "";
			for (int  i = 0; i < con.length(); i++)
				if (con[i] == '_') {
					std::string rig = "";
					for (int  j = i +1; j < con.length(); j++)
						rig = rig + con[j];
					constrainleft.push_back(lef);
					constrainright.push_back(rig);
					return;
				} else lef = lef + con[i];
			constrainleft.push_back("");
			constrainright.push_back("");
		}

		void newHeaderPage(int fileID, int pageID, int lastPage) {
			int index;
			constrainleft.clear();
			constrainright.clear();
			BufType result = bpm->allocPage(fileID, pageID, index, false);
			memset(result, 0, MAX_PAGE_SIZE);
			int header = 3;
			result[2] = 0;
			result[0 + header] = table.size;
			result[1 + header] = -1;
			char * last = (char *)result + 8 + header * 4;
			for (int i = 0; i < table.name.size(); i++) {
				if (table.primarykey == table.name[i]) {
					result[header + 1] = i; 
					primaryRank = i;
					primarykeyName = table.primarykey;
					if (table.type[i] == "int") primaryType = 0; else primaryType = 1;
				}
				constrain(table.name[i]);
				writeString(last, table.name[i]);
				writeInteger(last, table.len[i]);
				writeInteger(last, table.empty[i]);
				if (table.type[i] == "int") writeInteger(last, 0); else writeInteger(last, 1);
			}
			result[0] = last - (char*)(result);
			int tot = table.checkNameLists.size();
			writeInteger(last, tot);
			for (int  i = 0; i < tot; i++) {
				writeString(last, table.checkNameLists[i]);
				int tot1 = table.checkValueLists[i].size();
				writeInteger(last, tot1);
				if (table.checkValueLists[i][0].tip == 0) {
					writeInteger(last, 0);
					for (int j = 0; j < tot1; j++)
						writeInteger(last, table.checkValueLists[i][j].num);
				}
				else {
					writeInteger(last, 1);
					for (int j = 0; j < tot1; j++)
						writeString(last, table.checkValueLists[i][j].str);
				}
			}
			result[1] = last - (char*)(result);
			bpm->access(index);
			bpm->markDirty(index);
		}

		void getHeaderPage(int fileID, int pageID, int lastPage) {
			int index;
			constrainleft.clear();
			constrainright.clear();	
			BufType result = bpm->getPage(fileID, pageID, index);
			int header = 3;
			table.size = result[0 + header];
			char * last = (char *)result + 8 + header * 4;
			char * end = (char *)result + result[0];
			while (last != end) {
				int len = readInteger(last);
				std::string name = readString(last, len);
				constrain(name);
				table.name.push_back(name);
				table.len.push_back(readInteger(last));
				table.empty.push_back(readInteger(last));
				table.sum++;
				if (readInteger(last) == 0) table.type.push_back("int"); else table.type.push_back("varchar");
			}
			table.checkNameLists.clear();
			table.checkValueLists.clear();
			int tot = readInteger(last);
			for (int  i = 0; i < tot; i++) {
				int len = readInteger(last);
				std::string name = readString(last, len);
				int tot1 = readInteger(last);
				int type = readInteger(last);
				std::vector<PriceEntity> lists;
				lists.clear();
				if (type == 0) {
					for (int j = 0; j < tot1; j++) {
						int num = readInteger(last);
						lists.push_back(PriceEntity(num));
					}
				}
				else {
					for (int j = 0; j < tot1; j++) {
						int len =  readInteger(last);
						std::string str = readString(last, len);
						lists.push_back(PriceEntity(str));
					}
				}
				table.checkNameLists.push_back(name);
				table.checkValueLists.push_back(lists);
			}
			if (result[1 + header] != -1) {
				primaryRank = result[1 + header];
				table.primarykey = table.name[primaryRank];
				primarykeyName = table.primarykey;
				if (table.type[primaryRank] == "int") primaryType = 0; else primaryType = 1;
			}
			bpm->access(index);
		}

		void newPage(int fileID, int pageID) {
			int index;
			BufType result = bpm->allocPage(fileID, pageID, index, false);
			memset(result, 0, MAX_PAGE_SIZE);
			result[0] = PAGE_HEADER * 4;
			result[1] = MAX_PAGE_SIZE - PAGE_HEADER * 4 - 4;
			bpm->access(index);
			bpm->markDirty(index);
		}

	public:
		std::string path;
		DataStruct *dataStruct;
		FileManager* fm;
		BufPageManager* bpm;
		SearchTree tree;
		std::vector<DataFileManager*> *tbFileManager;
		std::string tableName;

		void setTableName(std::string con) {
			tableName = con;
		}

		bool findKey(std::string table, std::string name, std::string title) {
			for (int i = tbFileManager->size() - 1; i >= 0; i--)
				if ((*tbFileManager)[i]->tableName == table) {
					return (*tbFileManager)[i]->tree.find(title);
				}
			return false;
		}

		bool findKey(std::string table, std::string name, int title) {
			for (int i = tbFileManager->size() - 1; i >= 0; i--)
				if ((*tbFileManager)[i]->tableName == table) {
					return (*tbFileManager)[i]->tree.find(title);
				}
			return false;
		}

		DataFileManager() {
			fm = NULL;
			bpm = NULL;
			primaryRank = -1;
			primarykeyName = "";
			dataStruct = new DataStruct("gg");
		}

		DataFileManager(std::vector<DataFileManager*> *tbFileManager) {
			fm = NULL;
			bpm = NULL;
			primaryRank = -1;
			primarykeyName = "";
			dataStruct = new DataStruct("gg");
			this->tbFileManager = tbFileManager;
		}

		void setTable(Table table) {
			this->table = table;
		}

		void createFile() {
			int index;
			fm = new FileManager();
			fm->createFile(path.c_str());
			fm->openFile(path.c_str(), fileID);
			bpm = new BufPageManager(fm);
			newHeaderPage(fileID, 0, 0);
			bpm -> close();
			fm -> closeFile(fileID);
			delete bpm;
			delete fm;
			bpm = NULL;
			fm = NULL;
			if( (access((path + ".key").c_str(), R_OK)) !=0 ) {
				FILE * fout;
				fout = fopen((path + ".key").c_str(), "w");
				if (primaryRank >= 0) {
					fprintf(fout, "%s\n", table.primarykey.c_str());
					fprintf(fout, "%s\n", table.type[primaryRank].c_str());
				} else {
					fprintf(fout, "#\n");
					fprintf(fout, "#\n");
				}
				fclose(fout);
			}
			tree = SearchTree(path + ".key");
		}

		void openFile() {
			int index;
			fm = new FileManager();
			fm->openFile(path.c_str(), fileID);
			bpm = new BufPageManager(fm);
			getHeaderPage(fileID, 0, 0);
			for (int i = 0; i < table.name.size(); i++) {
				dataStruct -> addDataType(table.name[i], table.type[i], table.len[i]);
			}
			if( (access((path + ".key").c_str(), R_OK)) !=0 ) {
				FILE * fout;
				fout = fopen((path + ".key").c_str(), "w");
				if (primaryRank >= 0) {
					fprintf(fout, "%s\n", table.primarykey.c_str());
					fprintf(fout, "%s\n", table.type[primaryRank].c_str());
				} else {
					fprintf(fout, "#\n");
					fprintf(fout, "#\n");
				}
				fclose(fout);
			}
			tree = SearchTree(path + ".key");
		}

		void setFile(std::string route) {
			path = route;
		}

		bool checkCanBeEmpty(std::string name) {
			for (int i =  table.name.size() - 1; i >= 0; i--)
				if (table.name[i] == name)
					return table.empty[i];
			return false;
		}

		bool checkCanBeEmpty(int con) {
			return table.empty[con];
		}

		bool check(std::string name, int con) {
			for (int  i = 0; i < table.checkNameLists.size(); i++)
				if (table.checkNameLists[i] == name) {
					for (int j = table.checkValueLists[i].size() - 1; j >=0; j--)
						if (table.checkValueLists[i][j].num == con)
							return true;
					return false;					
				}
			return true;
		}

		bool check(std::string name, std::string con) {
			for (int i = 0; i < table.checkNameLists.size(); i++)
				if (table.checkNameLists[i] == name) {
					for (int j = table.checkValueLists[i].size() - 1; j >=0; j--)
						if (table.checkValueLists[i][j].str == con)
							return true;
					return false;
				}
			return true;
		}

		bool check(int num, int con) {
			return check(table.name[num], con);
		}

		bool check(int num, std::string con) {
			return check(table.name[num], con);
		}


		void showTable() {
			for (int i = 0; i < table.name.size(); i++) {
				printf("%s ", table.name[i].c_str());
				printf("%s ",table.type[i].c_str());
				printf("(%d) ", table.len[i]);
				if (table.empty[i]) printf("NOT NULL ");
				printf("\n");
			}
			if (table.primarykey != "") printf("PRIMARY KEY (%s)\n", table.primarykey.c_str());
			for (int i = 0; i < table.checkNameLists.size(); i++) {
				printf("CHECK ( %s in (", table.checkNameLists[i].c_str());
				int tot = table.checkValueLists[i].size();
				for (int j = 0; j < tot; j++)
					if (table.checkValueLists[i][j].tip == 0)
					printf(" %d ",table.checkValueLists[i][j].num );
					else
					printf(" \'%s\' ", table.checkValueLists[i][j].str.c_str());
				printf(") )\n");
			}
		}

		void insert(std::vector<std::string> content) {
			bool flag = false;
			bool flag1;
			if (primaryRank != -1) {
				if (primaryType == 0) {
					flag = tree.find(atoi(content[primaryRank].c_str()));
				}
				else {
					flag = tree.find(content[primaryRank]);
				}
			}
			if (flag) {
				if (primaryType == 0) {
					printf("\tError in insert : primary key %d %s\n", atoi(content[primaryRank].c_str()), ("in database/table " + path +" has existed").c_str());
				}
				else {
					printf("\tError in insert : primary key %s %s\n", content[primaryRank].c_str(), ("in database/table " + path +" has existed").c_str());
				}
				return;
			}

			flag = true;
			for (int  i = 0; i < constrainleft.size(); i++)
				if (constrainleft[i] != "") {
					bool flag1;
					if (table.type[i] == "int")
						flag1 = findKey(constrainleft[i], constrainright[i], atoi(content[i].c_str()));
					else
						flag1 = findKey(constrainleft[i], constrainright[i], content[i]);
					if (!flag1) {
						printf("\tError in insert : %s key has not existed in %s\n", constrainright[i].c_str(), constrainleft[i].c_str());
						flag = false;
						break;
					}
				}
			if (!flag) {
				return;
			}


			int index;
			int currentPage = 0;
			int page = 0;
			BufType result;

			while (true) {
				result = bpm->getPage(fileID, currentPage, index);
				page = currentPage;
				for (int i = 1; i <= result[2047]; i++)
					if (result[2047 - i] == 0) {
						page = currentPage + i;
					}
				if (page == currentPage) {
					if ((2047 - result[2047] - 1) * 4 > result[1]) {
						result[2047]++;
						result[2047 - result[2047]] = 0;
						page = currentPage + result[2047];
						newPage(fileID, page);
						break;
					} else {
						if (result[2] != 0) {
							currentPage = result[2];
							bpm->access(index);
						}
						else {
							result[2] = currentPage + result[2047] + 1;
							int index1;
							BufType result1 = bpm->getPage(fileID, result[2], index1);
							result1[0] = 16;
							result1[1] = 16;
							result1[2] = 0;
							bpm->access(index);
							bpm->access(index1);
							bpm->markDirty(index);
							bpm->markDirty(index1);
							currentPage = result[2];
						}
					}
				} else 
					break;
			}
			int index1 = index;
			BufType res = result;
			for (int i = 0; i < content.size(); i++) {
				if (content[i] == "#NULL")
					dataStruct ->setData(table.name[i], table.type[i], content[i], 1); 
				else					
					dataStruct ->setData(table.name[i], table.type[i], content[i], 0);
			}
			result = bpm->getPage(fileID, page, index);
			if (result[0] + table.size + 4 < (2047 - result[2047]) * 4) {
				result[1] = result[1] - table.size - 4;
				result[2047]++;
				result[2047 - result[2047]] = result[0];
				dataStruct -> writeToBuffer((char *)result +  result[0] , 0, table.size);
				result[0] = result[0] + table.size;
			} else {
				for (int i = 1; i <= result[2047]; i++)
					if (result[2047 - i] == -1) {
						result[2047 - i] = result[2047 - i + 1] + table.size;
						result[1] = result[1] - table.size;
						dataStruct -> writeToBuffer((char *)result + result[2047 - i], 0, table.size);
						break;
					}
			}
			if (result[1] <= table.size + 4) {
				res[2047 - (page - currentPage)] = 1;
			}
			bpm->access(index1);
			bpm->markDirty(index1);
			bpm->access(index);
			bpm->markDirty(index);
			if (primaryRank != -1) {
				if (primaryType == 0)
					tree.push(atoi(content[primaryRank].c_str()));
				else
					tree.push(content[primaryRank]);
			}
		}

		void del() {
			int index, index0;
			BufType result0 = bpm->getPage(fileID, currentPage, index0);
			if (finderPage > result0[2047]) return;
			BufType result = bpm->getPage(fileID, finderPage, index);
			if (finderTot > result[2047]) return;
			result[2047 - finderTot] = -1;
			result[1] += table.size;
			result0[2047 - finderPage] = 0;
			bpm->access(index0);
			bpm->markDirty(index0);
			bpm->access(index);
			bpm->markDirty(index);
			if (primaryRank!=-1) {
				if (primaryType == 0)
					tree.erase(static_compare.dataLists[0].tableValueLists[primaryRank].intValue);
				else
					tree.erase(static_compare.dataLists[0].tableValueLists[primaryRank].strValue);	
			}
		}

		void update() {
			if (!updateflag) {
				return;
			}

			if (primaryRank!=-1) {
				if (primaryType == 0)
					tree.erase(static_compare.dataLists[0].tableValueLists[primaryRank].intValue);
				else
					tree.erase(static_compare.dataLists[0].tableValueLists[primaryRank].strValue);
			}
			bool flag = false;
			if (primaryRank!=-1) {
				if (primaryType == 0)
					flag = tree.find(updateInt);
				else
					flag = tree.find(updateStr);
			}
			if (flag) {
				if (primaryType == 0) {
					printf("\tError in update: primary key %d %s\n", static_compare.dataLists[0].tableValueLists[primaryRank].intValue, ("in database/table " + path +" has existed").c_str());
					tree.push(static_compare.dataLists[0].tableValueLists[primaryRank].intValue);
				}
				else {
					printf("\tError in update: primary key %s %s\n", static_compare.dataLists[0].tableValueLists[primaryRank].strValue.c_str(), ("in database/table " + path +" has existed").c_str());
					tree.push(static_compare.dataLists[0].tableValueLists[primaryRank].strValue);
				}
				return;
			}

			int index, index0;
			BufType result0 = bpm->getPage(fileID, currentPage, index0);
			if (finderPage > currentPage + result0[2047]) return;
			BufType result = bpm->getPage(fileID, finderPage, index);
			if (finderTot > result[2047]) return;
			dataStruct -> writeToBuffer((char *)result +  result[2047 - finderTot] , 0, table.size);
			bpm->access(index0);
			bpm->markDirty(index0);
			bpm->access(index);
			bpm->markDirty(index);
			if (primaryRank!=-1) {
				if (primaryType == 0)
					tree.push(updateInt);
				else
					tree.push(updateStr);
			}
		}

		void finderInitial() {
			currentPage = 0;
			finderPage = 1;
			finderTot = 0;
		}

		RebackTable finderNext() {
			int index0, index;
			BufType result0;
			BufType result;

			bool flag = false;

			while (true) {
				result0 = bpm->getPage(fileID, currentPage, index0);
				while (finderPage <= currentPage + result0[2047]) {
					result = bpm->getPage(fileID, finderPage, index);
					for (int i = finderTot + 1; i <= result[2047]; i++)
						if (result[2047 - i] != -1) {
							flag = true;
							finderTot = i;
							break;
						}
					bpm->access(index);
					if (flag) break;
					finderPage++;
					finderTot = 0;
				}
				bpm->access(index0);
				if (flag) break;
				if (result0[2] != 0) {
					currentPage = result0[2];
					finderPage = currentPage + 1;
					finderTot = 0;
				} else
				break;
			}

			RebackTable res;
			if (!flag) return res;
			res  = dataStruct -> loadFromBuffer((char *)(result) + result[2047 - finderTot]);
			return res;
		}

		bool updateflag;

		void updateInitial() {
			updateflag = true;
		}

		void update(std::string name, std::string content) {
			if (!updateflag) return;

			if (content == "#NULL")
				dataStruct->setData(name, "varchar",content, 1);
			else					
				dataStruct->setData(name, "varchar",content);
			if (name == primarykeyName)
				updateStr = content;
			for (int  i = 0; i < constrainleft.size(); i++)
				if (constrainleft[i] + "_" + constrainright[i] == name) {
					bool flag1;
					flag1 = findKey(constrainleft[i], constrainright[i], content);
					if (!flag1) {
						updateflag = false;
						printf("\tError in update : %s %s key has not existed in %s\n", constrainright[i].c_str(), content.c_str(), constrainleft[i].c_str());
						return;
					}
				}
		}

		void update(std::string name, int content) {
			if (!updateflag) return;
			dataStruct->setData(name, "int", content);
			if (name == primarykeyName)
				updateInt = content;
			for (int  i = 0; i < constrainleft.size(); i++)
				if (constrainleft[i] + "_" + constrainright[i] == name) {
					bool flag1;
					flag1 = findKey(constrainleft[i], constrainright[i], content);
					if (!flag1) {
						updateflag = false;
						printf("\tError in update : %s %d key has not existed in %s\n", constrainright[i].c_str(), content, constrainleft[i].c_str());
						return;
					}
				}
		}

		void setNowData() {
			for (int i = 0; i < static_compare.dataLists[0].tableValueLists.size(); i++) {
				if (static_compare.dataLists[0].tableValueLists[i].tip == 0) {
					dataStruct ->setData(static_compare.dataLists[0].tableNameLists[i], "int", static_compare.dataLists[0].tableValueLists[i].intValue); 
					if (i == primaryRank) 
						updateInt = static_compare.dataLists[0].tableValueLists[i].intValue;
				}
				else
				if (static_compare.dataLists[0].tableValueLists[i].tip == 1) {
					dataStruct ->setData(static_compare.dataLists[0].tableNameLists[i], "varchar", static_compare.dataLists[0].tableValueLists[i].strValue); 
					if (i == primaryRank) 
						updateStr = static_compare.dataLists[0].tableValueLists[i].strValue;
				}
				else
					dataStruct ->setData(static_compare.dataLists[0].tableNameLists[i], "int", "NULL", 1);
			}
		}

		~DataFileManager() {
			if (bpm != NULL) {bpm->close();delete bpm;}
			if (fm != NULL) {fm -> closeFile(fileID);delete fm;}
			if (dataStruct != NULL) delete(dataStruct);
		}
};

#endif
