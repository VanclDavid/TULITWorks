#include <process.h>
#include "FileMachine.h"

int main() {
	FileMachine fileMachine;

	vector<User> users = fileMachine.parseCSV("file.csv");

	system("pause");
	return 0;
}