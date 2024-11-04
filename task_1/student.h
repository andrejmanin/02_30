#ifndef STUDENT_H
#define STUDENT_H


#include <map>
#include <vector>
#include <string>

using namespace std;


class Student {
    map<string, vector<int>> _students;
public:
    Student() = default;
    void add(string name, vector<int> marks);
    void updateMarks(string name, vector<int> marks);
    void showMarks(string name);
    float mediumMarks(string name);
};

void menu(int &input);

void getStudNameMarks(string &student_name, vector<int> &student_marks);

void start();


#endif //STUDENT_H
