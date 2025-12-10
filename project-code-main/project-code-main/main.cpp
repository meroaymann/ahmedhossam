#include "Person.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"
#include <iostream>
using namespace std;

Person::Person(const string& n, int i) {
    name = n;
    id = i;
}
Person::~Person() {
}
void Person::display() const {
    cout << "Name: " << name << ", ID: " << id;
}
void Person::roleinfo() const {
    cout << "Person Role: Name: " << name << ", ID: " << id << endl;
}
string Person::getName() const {
    return name;
}
int Person::getId() const {
    return id;
}

Student::Student(const string& n, int i, const string& m, int y) : Person(n, i) {
    major = m;
    yearLevel = y;
}
void Student::display() const {
    cout << "Name: " << name << ", ID: " << id << ", Major: " << major << ", Year Level: " << yearLevel;
}
void Student::roleinfo() const {
    cout << "Role: Student, Name: " << name << ", Major: " << major << ", Year Level: " << yearLevel << endl;
}
string Student::getMajor() const {
    return major;
}
int Student::getYearLevel() const {
    return yearLevel;
}
ostream& operator<<(ostream& os, const Student& s) {
    os << "Student -> Name: " << s.getName() << ", ID: " << s.getId() << ", Major: " << s.major << ", Year Level: " << s.yearLevel;
    return os;
}

Instructor::Instructor(const string& n, int i, const string& d, int e) : Person(n, i) {
    department = d;
    experienceYears = e;
}
void Instructor::display() const {
    cout << "Name: " << name << ", ID: " << id << ", Department: " << department << ", Experience: " << experienceYears;
}
void Instructor::roleinfo() const {
    cout << "Role: Instructor, Name: " << name << ", Department: " << department << ", Experience: " << experienceYears << " years" << endl;
}
string Instructor::getDepartment() const {
    return department;
}
int Instructor::getExperience() const {
    return experienceYears;
}
ostream& operator<<(ostream& os, const Instructor& ins) {
    os << "Instructor -> Name: " << ins.getName() << ", ID: " << ins.getId() << ", Department: " << ins.department << ", Experience: " << ins.experienceYears;
    return os;
}

Course::Course(const string& name, const string& code, int max) {
    courseName = name;
    courseCode = code;
    maxStudents = max;
    students.clear();
}
void Course::displayCourseInfo() const {
    cout << "Course Name: " << courseName << endl;
    cout << "Course Code: " << courseCode << endl;
    cout << "Max Students: " << maxStudents << endl;
    cout << "Currently Enrolled: " << students.size() << endl;
    if (students.size() > 0) {
        cout << "Students:" << endl;
        for (size_t i = 0; i < students.size(); ++i) {
            cout << " " << (i+1) << ". " << students[i].getName() << endl;
        }
    }
}
bool Course::addStudent(const Student& s) {
    if ((int)students.size() >= maxStudents) {
        return false;
    }
    students.push_back(s);
    return true;
}
Student& Course::operator[](size_t index) {
    return students.at(index);
}
const Student& Course::operator[](size_t index) const {
    return students.at(index);
}
Course& Course::operator+=(const Student& s) {
    addStudent(s);
    return *this;
}
bool Course::operator==(const Course& other) const {
    return courseCode == other.courseCode;
}
string Course::getCourseName() const {
    return courseName;
}
string Course::getCourseCode() const {
    return courseCode;
}
int Course::getMaxStudents() const {
    return maxStudents;
}
int Course::getCurrentStudents() const {
    return (int)students.size();
}
ostream& operator<<(ostream& os, const Course& c) {
    os << "Course -> Name: " << c.courseName << ", Code: " << c.courseCode << ", Enrolled: " << c.students.size() << "/" << c.maxStudents;
    if (c.students.size() > 0) {
        os << "\nStudents:";
        for (size_t i = 0; i < c.students.size(); ++i) {
            os << "\n " << (i+1) << ". " << c.students[i].getName();
        }
    }
    return os;
}

int main() {
    Instructor ins("Dr. Khaled", 1001, "Computer Science", 5);
    Student s1("Mariam Adel", 2001, "Network", 2);
    Student s2("Omar Nabil", 2002, "Programming", 1);
    Course c1("Introduction to Programming", "CS101", 2);
    Course c2("Data Structures", "CS102", 2);

    cout << ins << endl;
    cout << s1 << endl;
    cout << c1 << endl;

    c1 += s1;
    c1 += s2;

    cout << "\nAfter adding students to course:\n";
    cout << c1 << endl;

    cout << "\nCompare courses c1 and c2:\n";
    if (c1 == c2) {
        cout << "Courses are equal" << endl;
    } else {
        cout << "Courses are not equal" << endl;
    }

    cout << "\nAccessing student at index 1 in c1:\n";
    if (c1.getCurrentStudents() > 1) {
        cout << c1[1] << endl;
    } else {
        cout << "Not enough students in course" << endl;
    }

    Person* arr[2];
    arr[0] = &s1;
    arr[1] = &ins;

    cout << "\nPolymorphism - roleinfo() calls:\n";
    arr[0]->roleinfo();
    arr[1]->roleinfo();

    return 0;
}