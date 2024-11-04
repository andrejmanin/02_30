#include "school.h"

#include <iostream>
#include <ostream>

void School::insert(string group, vector<string> students) {
    if(!group.empty()) {
        school.insert({group, students});
    }
}

void School::pop(string group) {
    if(!group.empty() && school.find(group) != school.end()) {
        school.erase(group);
    } else {
        cout << "This group does not exist" << endl;
    }
}

void School::addStudent(string group, string student) {
    if(!group.empty() && school.find(group) != school.end()) {
        school.find(group)->second.push_back(student);
    } else {
        cout << "This group does not exist" << endl;
    }
}

void School::showGroupStudents(string group) {
    if(!group.empty() && school.find(group) != school.end()) {
        for(auto student : school.find(group)->second) {
            cout << student << endl;
        }
    } else {
        cout << "This group does not exist" << endl;
    }
}

void schoolMenu(int &input) {
    cout << "--------------------- Menu ---------------------" << endl;
    cout << "\t1. Add new group and students" << endl;
    cout << "\t2. Delete group" << endl;
    cout << "\t3. Show students from group" << endl;
    cout << "\t0. Exit" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Enter your choice: ";
    cin >> input;
    cout << endl;
}

void startSchool() {
    int input;
    School school;
    do {
        schoolMenu(input);
        switch (input) {
            case 0: {
                break;
            }
            case 1: {
                string group, student;
                vector<string> students;
                cout << "Enter group name: ";
                cin.ignore();
                getline(cin, group);
                do {
                    cout << "Enter student name (to stop write 0): ";
                    getline(cin, student);
                    students.push_back(student);
                } while(student[0] != '0');
                students.pop_back();
                school.insert(group, students);
                break;
            }
            case 2: {
                string group;
                cout << "Enter group name: ";
                cin.ignore();
                getline(cin, group);
                school.pop(group);
                break;
            }
            case 3: {
                string group;
                cout << "Enter group name: ";
                cin.ignore();
                getline(cin, group);
                school.showGroupStudents(group);
                break;
            }
            default: {
                cout << "Invalid input" << endl;
                break;
            }
        }
    }while (input != 0);
}