#ifndef SEARCHTREE_H
#define SEARCHTREE_H
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <cstdlib>

class SearchTree {

	std::set<std::string> tree_str;
	std::set<int> tree_int;

public:

	std::string path;
	std::string type;
	std::string key;
	FILE *fout;

	std::string getKey() {
		return key;
	}

	SearchTree() {
		
	}
	
	SearchTree(std::string path) {
		this -> path = path;
		fout = fopen(path.c_str(), "r");
		char buffer[1000];
		fscanf(fout, "%s\n", buffer);
		key = buffer;
		fscanf(fout, "%s\n", buffer);
		type = buffer;
		while (fscanf(fout, "%s\n", buffer) == 1) {
			if (type == "int") {
				tree_int.insert(atoi(buffer));
			} else {
				tree_str.insert(std::string(buffer));
			}
		}
		fclose(fout);
	}

	bool find(std::string key) {
		std::set<std::string>::iterator iter = tree_str.lower_bound(key);
		if (iter != tree_str.end() && *iter == key)
			return true;
		return false;
	}

	void push(std::string key) {
		std::set<std::string>::iterator iter = tree_str.lower_bound(key);
		if (iter != tree_str.end() && *iter == key)
			return;
		tree_str.insert(key);
	}

	void erase(std::string key) {
		std::set<std::string>::iterator iter = tree_str.lower_bound(key);
		if (iter != tree_str.end() && *iter == key)
			tree_str.erase(iter);
	}

	bool find(int key) {
		std::set<int>::iterator iter = tree_int.lower_bound(key);
		if (iter != tree_int.end() && *iter == key)
			return true;
		return false;
	}

	void push(int key) {
		std::set<int>::iterator iter = tree_int.lower_bound(key);
		if (iter != tree_int.end() && *iter == key)
			return;
		tree_int.insert(key);
	}

	void erase(int key) {
		std::set<int>::iterator iter = tree_int.lower_bound(key);
		if (iter != tree_int.end() && *iter == key)
			tree_int.erase(iter);
	}
	
	~SearchTree() {
		fout = fopen(path.c_str(), "w");
		fprintf(fout, "%s\n", key.c_str());
		fprintf(fout, "%s\n", type.c_str());
		if (type == "int")
			for (std::set<int>::iterator iter = tree_int.begin(); iter != tree_int.end(); iter++)
				fprintf(fout, "%d\n", *iter);
		else
			for (std::set<std::string>::iterator iter = tree_str.begin(); iter != tree_str.end(); iter++)
				fprintf(fout, "%s\n", iter->c_str());
		fclose(fout);
	}	

};

#endif
