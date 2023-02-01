#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

//This defines the class "Book" which has 6 data members : ISBN, title, author, publisher, year, and description.
//All of these variables are of type string except for year which is an integer.
class Book {

public:
    string ISBN;
    string title;
    string author;
    string publisher;
    int year;
    string description;

};

//Empty vector of type Book named "books". This is where the output will be stored.
vector<Book> books;

//This function reads the "books.csv" file and stores each line of the file into a Book object.
//Each line is split into the different fields of the Book object using the "find" and "substr" string functions.
//The year field is extracted using a stringstream, which is then converted to an integer.
//Finally, the book object is added to the "books" vector.

void readBooks() {

    ifstream booksFile("books.csv");
    string line;

    while (getline(booksFile, line)) {

        int i1 = line.find(",");
        int i2 = line.find(",", i1 + 1);
        int i3 = line.find(",", i2 + 1);
        int i4 = line.find(",", i3 + 1);
        int i5 = line.find(",", i4 + 1);

        Book book;

        book.ISBN = line.substr(0, i1);
        book.title = line.substr(i1 + 1, i2 - i1 - 1);
        book.author = line.substr(i2 + 1, i3 - i2 - 1);
        book.publisher = line.substr(i3 + 1, i4 - i3 - 1);
        stringstream ss(line.substr(i4 + 1, i5 - i4 - 1));
        ss >> book.year;
        book.description = line.substr(i5 + 1);
        books.push_back(book);

    }
}

//This function takes a single parameter search, which is a string that the user inputs to search for books.
//It then uses a for-each loop to iterate through the books vector.
//For each book in the books vector, it checks if the title of the book contains the search string using the std::string::find() method.
//If it does, it prints the ISBN, title, author, publisher, publication year and description of that book using std::cout.
//It does this for every book in the vector, printing out the information for any book whose title contains the search string.

void searchBooks(string search) {

    for (Book book : books) {

        if (book.title.find(search) != string::npos) {

            cout << "ISBN: " << book.ISBN << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Publisher: " << book.publisher << endl;
            cout << "Publication Year: " << book.year << endl;
            cout << "Description: " << book.description << endl;
            cout << endl;

        }
    }
}
