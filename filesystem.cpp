/*
 * testfilesystem.cpp
 *
 *  Created on: 2015年10月6日
 *      Author: lql
 */
#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include "DataStruct.h"
#include "DataFileManager.h"
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
	DataFileManager manager("database");
	DataStruct a();
	a.InitialData("Int");
		a.InitialData("Int");
	return 0;
}