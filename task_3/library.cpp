#include "library.h"
#include <iostream>

void Library::add(string key, vector<string> values) {
    if(key[0] != '\0') {
        _data.insert(make_pair(key, values));
    }
}

void Library::getAuthor(string key) {
    if(key[0] != '\0') {
        cout << key << " authors: ";
        for(int i = 0; i < _data[key].size(); i++) {
            cout << _data[key][i] << " ";
        }
        cout << endl;
    }
}

void Library::showAll() const {
    if(!_data.empty()) {
        for(auto el : _data) {
            cout << el.first << " authors: ";
            for(int i = 0; i < el.second.size(); i++) {
                cout << el.second[i] << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

bool Library::isEmpty() const {
    return _data.empty();
}


void libraryMenu(int &input) {
    cout << "--------------------- Menu ---------------------" << endl;
    cout << "\t1. Add new book and authors" << endl;
    cout << "\t2. Find authors" << endl;
    cout << "\t3. Show all books and authors" << endl;
    cout << "\t0. Exit" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Enter your choice: ";
    cin >> input;
    cout << endl;
}

void startLibrary() {
    Library library;
    int input;
    do {
        libraryMenu(input);
        switch (input) {
            case 0: {
                return;
            }
            case 1: {
                string bookName, bookAuthor;
                vector<string> bookAuthors;
                cout << "Enter book name: ";
                cin.ignore();
                getline(cin, bookName);
                do {
                    cout << "Enter book authors (if it last author enter 0): ";
                    getline(cin, bookAuthor);
                    bookAuthors.push_back(bookAuthor);
                }while(bookAuthor[0] != '0');
                bookAuthors.pop_back();
                library.add(bookName, bookAuthors);
                break;
            }
            case 2: {
                string bookName;
                cout << "Enter book name: ";
                cin.ignore();
                getline(cin, bookName);
                library.getAuthor(bookName);
                break;
            }
            case 3: {
                if(library.isEmpty()) {
                    cout << "There is no book yet." << endl;
                    break;
                }
                library.showAll();
                break;
            }
            default: {
                cout << "Invalid input." << endl;
                break;
            }
        }
    }while(input != 0);
}