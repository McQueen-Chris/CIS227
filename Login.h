#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//This function reads the "login.csv" file and checks if the entered username and password match any of the usernames and passwords in the file.
//The file is read line by line and each line is split into the username and password using the "find" and "substr" string functions.
//If a match is found, the function returns true, otherwise it returns false.
bool userLogin(string username, string password) {

	ifstream loginFile("login.csv");
	string line;

	while (getline(loginFile, line)) {

		int i = line.find(",");
		string user = line.substr(0, i);
		string pass = line.substr(i + 1);

		if (user == username && pass == password) {
			return true;
		}
	}
	return false;
}
