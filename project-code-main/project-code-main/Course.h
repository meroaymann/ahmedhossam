#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Course {
private:
    string courseName;
    string courseCode;
    int maxStudents;
    vector<Student> students;
public:
    Course(const string& name, const string& code, int max);
    void displayCourseInfo() const;
    bool addStudent(const Student& s);
    Student& operator[](size_t index);
    const Student& operator[](size_t index) const;
    Course& operator+=(const Student& s);
    bool operator==(const Course& other) const;
    string getCourseName() const;
    string getCourseCode() const;
    int getMaxStudents() const;
    int getCurrentStudents() const;
    friend ostream& operator<<(ostream& os, const Course& c);
};

#endif