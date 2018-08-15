#pragma once
#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class FileManager {

public:
	FileManager();
	~FileManager();

	void LoadContent(const char *filename, vector<vector<string>> &attributes, vector<vector<string>> &contents);
	void LoadContent(const char *filename, vector<vector<string>> &attributes, vector<vector<string>> &contents, string ID);
private:
	enum LoadType {Attributes, Contents};
	int type;
	bool found;
	vector<string> tempAttributes, tempContents;

};

#endif // !FILEMANAGER_H
