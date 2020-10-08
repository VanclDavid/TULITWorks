#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include "User.h"

using namespace std;

class FileMachine {
public:
	vector<User> parseCSV(string fileName) {
		vector<User> users;

		int skip = 1;
		int index = 0;
		for (string row : this->loadDataFromCSV(fileName)){
			if (skip > index) {
				index++;
				continue;
			}
			users.push_back(User(this->splitString(row)));
			index++;
		}

		return users;
	}

private:
	vector<string> loadDataFromCSV(string fileName) {
		vector<string> fileLoadedByLines;

		ifstream file;
		file.open(fileName);

		string line;
		while (getline(file,line)) {
			fileLoadedByLines.push_back(line);
		}

		return fileLoadedByLines;
	}

	vector<string> splitString(string data, char delimeter = ',') {
		vector<string> splitedData;

		stringstream ss(data);
		string token;
		while (getline(ss, token, delimeter)) {
			splitedData.push_back(token);
		}

		return splitedData;
	}
};