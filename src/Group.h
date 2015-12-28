#ifndef GROUP_H
#define GROUP_H
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

struct  GroupEntity{
	int tip;
	std::string table;
	std::string name;
	std::string strValue;
	int intValue;

	GroupEntity(std::string table, std::string name, std::string strValue) {
		this -> table = table;
		this -> name =  name;
		this -> strValue = strValue;
		tip = 1;
	}

	GroupEntity(std::string table, std::string name, int intValue) {
		this -> table = table;
		this -> name =  name;
		this -> intValue = intValue;
		tip = 0;
	}
};

struct GroupList {
	int ss;
	std::vector<GroupEntity>  groupEntityLists;
	std::vector<std::string> nameLists;
	std::vector<std::string> tableLists;
	std::vector<int> typeLists;
	std::vector<long long> sum;
	std::vector<long long> tot;
	std::vector<long long> mx;
	std::vector<long long> mi;

	int miner(int a, int b) {
		if (a <  b) return a;
		return b;
	}

	int maxer(int a, int b) {
		if (a > b) return a;
		return b;
	}

	GroupList() {
		groupEntityLists.clear();
		nameLists.clear();
		mi.clear();
		mx.clear();
		sum.clear();
		tot.clear();
		typeLists.clear();
	}

	void push(std::string table, std::string name, int content) {
		groupEntityLists.push_back(GroupEntity(table, name, content));
	}

	void push(std::string table, std::string name, std::string content) {
		groupEntityLists.push_back(GroupEntity(table, name, content));
	}

	bool checkEqual(const GroupList& con) {
		for (int i = groupEntityLists.size() - 1; i >= 0; i--)
			if ((con.groupEntityLists[i].tip == 1 && groupEntityLists[i].strValue == con.groupEntityLists[i].strValue)||(con.groupEntityLists[i].tip == 0 && groupEntityLists[i].intValue == con.groupEntityLists[i].intValue))
				continue;
			else 
				return false;
		return true;
	}

	bool push(const GroupList& con) {
		for (int i = mx.size() - 1; i >=0; i--) {
			mx[i] = maxer(mx[i], con.mx[i]);
			mi[i] = miner(mi[i], con.mi[i]);
			tot[i] += con.tot[i];
			sum[i] += con.sum[i];
		}
	}

	void push(std::string table, std::string name, int content, int type) {
		for (int i = nameLists.size() - 1; i >= 0; i--)
			if (nameLists[i] == name && tableLists[i] == table) {
				if (content < mi[i]) mi[i] = content;
				if (content > mx[i]) mx[i] = content;
				tot[i] = tot[i] + 1;
				sum[i] = sum[i] + content;
				return;
			}
		nameLists.push_back(name);
		tableLists.push_back(table);
		mx.push_back(content);
		mi.push_back(content);
		sum.push_back(content);
		typeLists.push_back(type);
		tot.push_back(1);
	}

	void show() {
		for (int i = 0; i < groupEntityLists.size(); i++)
			if (groupEntityLists[i].tip == 0)
				printf("\t%d", groupEntityLists[i].intValue);
			else
				printf("\t%s", groupEntityLists[i].strValue.c_str());
		for (int i = 0; i < typeLists.size(); i++) {
			if (typeLists[i] == 0) printf("\t%lld\n", sum[i]); else
			if (typeLists[i] == 1) printf("\t%lf\n", (double)(sum[i]) / (double)(tot[i])); else
			if (typeLists[i] == 2) printf("\t%lld\n", mx[i]); else
			if (typeLists[i]== 3) printf("\t%lld\n", mi[i]); 
		}
	}
};

#endif