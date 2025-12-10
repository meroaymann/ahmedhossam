#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int id;
public:
    Person(const string& n, int i);
    virtual ~Person();
    virtual void display() const;
    virtual void roleinfo() const;
    string getName() const;
    int getId() const;
};

#endif