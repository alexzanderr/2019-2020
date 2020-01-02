#pragma once

#include <iostream>
#include <string>
#include <cstring>

#include "builtins.py.h"
#include "exceptions.py.h"
#include "pylist.h"

using namespace std;

class Person {

    static int instances;
    string fname;
    string sname;
    int byear;

public:

    Person():
        fname(""),
        sname(""),
        byear(0)
    {
        instances++;
    }

    Person(const string &fn, const string &sn, const int &by):
        fname(fn),
        sname(sn),
        byear(by)
    {
        instances++;
    }

    // copy constructor
    Person(const Person &src):
        fname(src.fname),
        sname(src.sname),
        byear(src.byear)
    {
        instances++;
    }

    ~Person() {
        instances--;
    }

    string GetFName() const {
        return fname;
    }

    string GetSName() const {
        return sname;
    }

    int GetBYear() const {
        return byear;
    }

    static int NumberOfInstances() {
        return instances;
    }

    void Details() {
        String aux;
        print(aux.format("First name: {}.", fname));
        print(aux.format("Second name: {}.", sname));
        print(aux.format("Birth year: {}.", byear));
    }

};

int Person::instances = 0;