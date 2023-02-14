#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Login.h"
#include "Books.h"
#include <chrono>
#include <thread>

using namespace std;

int main() {

    // A vector to store books
    vector<Book> readingList;

    // Variables to store the username and password entered by the user
    string username;
    char password[75];

    // A variable to store the user's response when asked if they want to try again after a failed login
    string tryAgain;

    // A variable to store the user's choice when creating a list of books
    int listChoice;

    // Welcome message
    cout << "Welcome to the CIS 227 Bookstore. Please enter your login information." << endl;

    // Prompt for username
    cout << "Username: ";
    cin >> username;

    // Prompt for password
    cout << "Password: ";
    cin >> password;

    int i;
    for (i = 0; (i < 75 && password[i] != '\0'); i++) {

        password[i] = password[i] + 2;
        break;
    }
    // Check if the login information entered by the user is valid
    if (userLogin(username, password)) {

        // If the login is successful, display a message
        cout << "Login successful. Preparing the database now..." << endl;

        // Call the readBooks function to prepare the database
        // The function is inside a try-catch block to catch exceptions that may occur during its execution
        try {
            readBooks();
        }
        catch (const exception& e) {

            // If an exception occurs, display an error message with the exception's description
            cout << "An error occurred while reading books: " << e.what() << endl;

            // Exit the program with an error code
            return 1;
        }

        // A variable to store the user's main menu choice
        int choice;

        // Loop to continuously present the user with the main menu until they choose to exit
        do {

            // Main menu options
            cout << "What would you like to do?\n1. Search for a book\n2. Add a book to the database\n3. Create a list\n4. Exit\nEnter your choice: ";
            cin >> choice;

            if (choice == 0) {
                //chrono::seconds duration(5);
                //this_thread::sleep_for(duration);
                readBooks();
                //this_thread::sleep_for(duration);
            }

            // If the user chooses to search for a book
            if (choice == 1) {

                // Clear the screen
                system("CLS");

                // A variable to store the search string entered by the user
                string search;

                // Prompt for the search string. Asking for the book title!
                cout << "Search: ";
                cin >> search;

                // Call the searchBooks function with the search string as an argument
                // The function is inside a try-catch block to catch exceptions that may occur during its execution
                try {
                    searchBooks(search);
                    chrono::seconds duration(5);
                    this_thread::sleep_for(duration);
                }
                catch (const exception& e) {
                    // If an exception occurs, display an error message with the exception's description
                    cout << "An error occurred while searching books: " << e.what() << endl;
                }
            }
            // If the user chooses to add a book to the database
            else if (choice == 2) {
                // Clear the screen
                system("CLS");
                // Call the addBook function
                // The function is inside a try-catch block to catch exceptions that may occur during its execution
                try {
                    addBook();
                }
                catch (const exception& e) {
                    cout << "An error occurred while adding a book: " << e.what() << endl;
                    //This is asking the user for a choice. If the user enters 2, the program calls the function addBook().
                    //The function addBook() is inside a try-catch block which catches exceptions if any occur during the execution of the function.
                }
            }
            else if (choice == 3) {
                system("CLS");
                do {
                    cout << "What would you like to do?\n1. Add a book to the list\n2. Remove a book from the list\n3. Display the list\n4. Back to main menu\nEnter your choice: ";
                    cin >> listChoice;
                    if (listChoice == 1) {
                        addToList();
                    }
                    else if (listChoice == 2) {
                        removeFromList();
                    }
                    else if (listChoice == 3) {
                        displayList();
                    }
                    else if (listChoice == 4) {
                        break;
                    }
                    else {
                        cout << "Invalid choice. Try again." << endl;
                    }
                    readBooks();
                } while (listChoice != 4);
                //This is asking the user for a choice.
                //If the user enters 3, the program enters a loop that displays a list of choices related to the reading list.
                //The user can add books to the list, remove books from the list, display the list, or return to the main menu.
                //The functions addToList(), removeFromList(), and displayList() are called according to the user's choice.
                //After each choice, the function readBooks() is called.
            }
            else if (choice == 4) {
                return 0;
                //This is asking the user for a choice. If the user enters 4, the program returns 0, which exits the program.
                //If the user enters anything else, a message is displayed and the user is prompted to try again.
            }
            else {
                cout << "Invalid choice. Try again." << endl;
                cin.ignore();
                cin.get();
            }
        } while (choice != 4);
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

    return 0;
}