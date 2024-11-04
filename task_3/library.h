#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Library {
    map<string, vector<string>> _data;

public:
    Library() = default;
    ~Library() = default;

    void add(string key, vector<string> values);
    void getAuthor(string key);
    void showAll() const;
    [[nodiscard]] bool isEmpty() const;
};

void startLibrary();

#endif LIBRARY_H