#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

class Instructor : public Person {
private:
    string department;
    int experienceYears;
public:
    Instructor(const string& n, int i, const string& d, int e);
    void display() const override;
    void roleinfo() const override;
    string getDepartment() const;
    int getExperience() const;
    friend ostream& operator<<(ostream& os, const Instructor& ins);
};

#endif