//
// Created by andrewmanin on 11/4/24.
//

#ifndef SCHOOL_H
#define SCHOOL_H

#include <map>
#include <string>
#include <vector>

using namespace std;

class School {
    map<string, vector<string>> school;
public:
    School() = default;
    void insert(string group, vector<string> students);
    void addStudent(string group, string student);
    void pop(string group);
    void showGroupStudents(string group);
};

void startSchool();


#endif //SCHOOL_H
