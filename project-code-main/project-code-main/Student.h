#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

class Student : public Person {
private:
    string major;
    int yearLevel;
public:
    Student(const string& n, int i, const string& m, int y);
    void display() const override;
    void roleinfo() const override;
    string getMajor() const;
    int getYearLevel() const;
    friend ostream& operator<<(ostream& os, const Student& s);
};

#endif