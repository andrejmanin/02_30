#include "student.h"
#include <iostream>

void Student::add(string name, vector<int> marks) {
  if(name[0] != '\0') {
    _students.insert(make_pair(name, marks));
  }
}

void Student::updateMarks(string name, vector<int> marks) {
  if(name[0] != '\0') {
    _students[name] = marks;
  }
}

void Student::showMarks(string name) {
  if(name[0] != '\0') {
    cout << name << ": "<< endl;
    for(int i = 0; i < _students[name].size(); i++) {
      cout << _students[name][i] << " ";
    }
  }
  cout << endl;
}

float Student::mediumMarks(string name) {
  float medium = 0;
  int i = 0;
  for(; i < _students[name].size(); i++) {
    medium += _students[name][i];
  }
  return medium / i;
}

void menu(int &input) {
  cout << "--------------------- Menu ---------------------" << endl;
  cout << "\t1. Add student" << endl;
  cout << "\t2. Update student marks" << endl;
  cout << "\t3. Show student marks" << endl;
  cout << "\t4. Show student medium marks" << endl;
  cout << "\t0. Exit" << endl;
  cout << "------------------------------------------------" << endl;
  cout << "Enter your choice: ";
  cin >> input;
  cout << endl;
}

void getStudNameMarks(string &student_name, vector<int> &student_marks) {
  cout << "Enter student name: ";
  cin >> student_name;
  int mark;
  cout << "Enter student marks (0 to end input): ";
  do {
    cin >> mark;
    student_marks.push_back(mark);
  }while (mark != 0);
  student_marks.pop_back();
  cout << endl;
}

void start() {
  Student students;
  int input;
  do {
    menu(input);
    string student_name;
    vector<int> student_marks;
    switch(input) {
      case 0: {
        break;
      }
      case 1: {
        getStudNameMarks(student_name, student_marks);
        students.add(student_name, student_marks);
        break;
      }
      case 2: {
        getStudNameMarks(student_name, student_marks);
        students.updateMarks(student_name, student_marks);
        break;
      }
      case 3: {
        cout << "Enter student name: ";
        cin >> student_name;
        students.showMarks(student_name);
        cout << endl;
        break;
      }
      case 4: {
        cout << "Enter student name: ";
        cin >> student_name;
        cout << student_name << ": " << students.mediumMarks(student_name) << endl << endl;
        break;
      }
      default: {
        cout << "Invalid input!" << endl << endl;
      }
    }
  }while(input != 0);
}