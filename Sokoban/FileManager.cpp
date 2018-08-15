#include "FileManager.h"

FileManager::FileManager() {
	found = false;
}

FileManager::~FileManager() {

}



void FileManager::LoadContent(const char *filename, vector<vector<string>> &attributes, vector<vector<string>> &contents) {
	ifstream openfile(filename);
	string line, newLine;

	if (openfile.is_open()) {
		while (!openfile.eof()) {
			stringstream str;
			getline(openfile, line);

			if (line.find("Load=") != string::npos) {
				type = LoadType::Attributes;
				line = line.erase(0, line.find("=") + 1);
				tempAttributes.clear();
			}
			else {
				type = LoadType::Contents;
				tempContents.clear();
			}

			str << line;
			
			while (getline(str, newLine, ']')) {
				
				
				newLine.erase(remove(newLine.begin(), newLine.end(), '['), newLine.end());
				string erase = " \t\n\r";
				newLine.erase(newLine.find_last_not_of(erase)+1);
				
				if (type == LoadType::Attributes) {
					tempAttributes.push_back(newLine);
				}
				else {
					tempContents.push_back(newLine);
				}

				cout << newLine << endl;
			}
			if (type == LoadType::Contents && tempContents.size() > 0) {
				attributes.push_back(tempAttributes);
				contents.push_back(tempContents);
			}

		}
	}
	else {
		
	
	}

}

void FileManager::LoadContent(const char *filename, vector<vector<string>> &attributes, vector<vector<string>> &contents, string ID) {
	ifstream openfile(filename);
	string line, newLine;

	if (openfile.is_open()) {
		while (!openfile.eof()) {
			stringstream str;
			getline(openfile, line);

			if (line.find("EndLoad=") != string::npos && line.find(ID) != string::npos) {
				found = false;
				break;
			}
			else {
				if (line.find("Load=") != string::npos && line.find(ID) != string::npos) {
					found = true;
					continue;
				}
			}

			if (found) {

				if (line.find("Load=") != string::npos) {
					type = LoadType::Attributes;
					line = line.erase(0, line.find("=") + 1);
					tempAttributes.clear();
				}
				else {
					type = LoadType::Contents;
					tempContents.clear();
				}

				str << line;

				while (getline(str, newLine, ']')) {


					newLine.erase(remove(newLine.begin(), newLine.end(), '['), newLine.end());
					string erase = " \t\n\r";
					newLine.erase(newLine.find_last_not_of(erase) + 1);

					if (type == LoadType::Attributes) {
						tempAttributes.push_back(newLine);
					}
					else {
						tempContents.push_back(newLine);
					}

					cout << newLine << endl;
				}
				if (type == LoadType::Contents && tempContents.size() > 0) {
					attributes.push_back(tempAttributes);
					contents.push_back(tempContents);
				}

			
		}

		}
	}
	else {


	}

}