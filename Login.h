#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//Function to check the login.csv file for accurate login credentials.
//Returning false will ensure credentials are required each time the database is to be accessed.
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
