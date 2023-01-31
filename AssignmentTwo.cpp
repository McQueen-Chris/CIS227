#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Login.h"
#include "Books.h"
using namespace std;


int main() {

    string username;
    string password;
    string tryAgain;

    cout << "Welcome to the CIS 227 Bookstore. Please enter your login information." << endl;

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;
    
    //If the username and/or password do not match what is stored in the login.csv file, the user will be asked if they would like to try again.
    //No access is granted until successful login happens (credentials are correct).
    if (userLogin(username, password)) {
        cout << "Login successful. Preparing the database now..." << endl;

        readBooks();
        string search;

        cout << "Search for a book: ";
        cin >> search;

        searchBooks(search);
        
        //Conditional structure that asks the user if they would like to search for another book or exit the program.
        while (true) {

            string choice;
            cout << "Would you like to search for another book? Y/N" << endl;
            cin >> choice;

            if (choice == "Y") {

                cout << "Search: ";
                cin >> search;

                searchBooks(search);

            }

            else {

                break;
            }
        }

    }

    else {

        cout << "Invalid username or password. Would you like to try again? Y/N" << endl;
        cin >> tryAgain;

        if (tryAgain == "Y") {
            main();
        }

        else {
            return 0;
        }

    }

}
