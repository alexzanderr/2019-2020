#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "exceptions.h"
#include "util.h"

using namespace std;
using namespace Util::PythonBuiltIn;
using namespace Util::PrintArrays;
using namespace Util::Memory;

class Object {

    int atr_int;
    float atr_float;
    double atr_double;
    char atr_char;
    char *atr_charp;
    string atr_string;
    int index = -1;
    unsigned int instantiation_per_scope = 0;

public:

    template <typename T>
    void InitInt(const T &arg) {
        if (type(arg) != "<class \'int\'>") {
            throw TypeError("esti bou");
        } 
        instantiation_per_scope++;
        if (instantiation_per_scope > 1) {
            throw instantiation_error;
        }
        atr_int = arg;
        index = 0;
    }

    template <typename T>
    void InitFloat(const T &arg) {
        if (type(arg) != "<class \'float\'>") {
            throw TypeError("nu te suport");
        }    
        instantiation_per_scope++;  
        if (instantiation_per_scope > 1) {
            throw instantiation_error;
        }      
        atr_float = arg;
        index = 1;
    }

    template <typename T>
    void InitDouble(const T &arg) {
        if (type(arg) != "<class \'double\'>") {
            throw TypeError("nu esti salutare");
        }      
        instantiation_per_scope++;
        if (instantiation_per_scope > 1) {
            throw instantiation_error;
        }      
        atr_double = arg;
        index = 2;
    }

    template <typename T>
    void InitChar(const T &arg) {
        if (type(arg) != "<class \'char\'>") {
            throw TypeError("esti gay");
        }      
        instantiation_per_scope++;
        if (instantiation_per_scope > 1) {
            throw instantiation_error;
        }      
        atr_char = arg;
        index = 3;
    }

    template <typename T>
    void InitCharP(const T *arg) {
        if (type(arg) != "<class \'pointer_const_char\'>") {
            throw TypeError("sa1123123123lutare");
        }    
        instantiation_per_scope++;    
        if (instantiation_per_scope > 1) {
            throw instantiation_error;
        }         
        atr_charp = new char[strlen(arg) + 1];
        strcpy(atr_charp, arg);
        index = 4;
    }

    template <typename T>
    void InitString(const T &arg) {
        if (type(arg) != "<class \'std::string\'>" and 
            type(arg) != "<class \'string_constant\'>") {
            throw TypeError("\nWrong parameter data type for std::string.\n");
        }   
        instantiation_per_scope++;   
        if (instantiation_per_scope > 1) {
            throw instantiation_error;
        }      
        atr_string = arg;
        index = 5;
    }

    int GetInt() const {
        return atr_int;
    }

    float GetFloat() const {
        return atr_float;
    }

    double GetDouble() const {
        return atr_double;
    }

    char GetChar() const {
        return atr_char;
    }

    char* GetCharP() const {
        return atr_charp;
    }

    string GetString() const {
        return atr_string;
    }
    
    string Type() const {
        if (index == 0) {
            return "int";
        }
        else if (index == 1) {
            return "float";
        }
        else if (index == 2) {
            return "double";
        }
        else if (index == 3) {
            return "char";
        }
        else if (index == 4) {
            return "char*";
        }
        else if (index == 5) {
            return "string";
        }
        return "empty";
    }

    friend ostream& operator<< (ostream& os, const Object &obj) {
        if (obj.Type() == "int" ) {
            os << obj.atr_int;
        }
        else if (obj.Type() == "float") {
            os << obj.atr_float;
        }
        else if (obj.Type() == "double") {
            os << obj.atr_double;
        }
        else if (obj.Type() == "char" ) {
            os << "\'" << obj.atr_char << "\'";
        }
        else if (obj.Type() == "char*") {
            os <<"\'" << obj.atr_charp << "\'";
        }
        else if (obj.Type() == "string") {
            os <<"\'" << obj.atr_string << "\'";
        }   
        else if (obj.Type() == "empty") {
            os << "We dont have values on Object, yet.";
        }
        else {
            os << "None";
        }
        return os;
    }

    Object& operator = (const Object &s) {
        if (this == &s) {
            return *this;
        }
        if (s.Type() == "int" ) {
            atr_int = s.GetInt();
            index = 0;
            return *this;
        }
        else if (s.Type() == "float") {
            atr_float = s.GetFloat();
            index = 1;
            return *this;
        }
        else if (s.Type() == "double") {
            atr_double = s.GetDouble();
            index = 2;
            return *this;
        }
        else if (s.Type() == "char" ) {
            atr_char = s.GetChar();
            index = 3;
            return *this;
        }
        else if (s.Type() == "char*") {
            atr_charp = s.GetCharP();
            index = 4;
            return *this;
        }
        else if (s.Type() == "string") {
            atr_string = s.GetString();
            index = 5;
            return *this;
        }   
        return *this;
    }
};

class List {
    // list from python
public:
    vector<Object> list;

    void append(const Object &obj) {
        list.push_back(obj);
    }

    void append(const int &item) {
        Object elem;
        elem.InitInt(item);
        list.push_back(elem);
    }

    void append(const float &item) {
        Object elem;
        elem.InitFloat(item);
        list.push_back(elem);
    }

    void append(const double &item) {
        Object elem;
        elem.InitDouble(item);
        list.push_back(elem);
    }

    void append(const char &item) {
        Object elem;
        elem.InitChar(item);
        list.push_back(elem);
    }

    void append(const char *item) {
        Object elem;
        elem.InitCharP(item);
        list.push_back(elem);
    }

    void append(const string &item) {
        Object elem;
        elem.InitString(item);
        list.push_back(elem);
    }

    int Len() const {
        return list.size();
    }

    friend ostream& operator<< (ostream& os, const List &obj) {
        const int size = obj.list.size() - 1;
        os << "[";
        for(size_t iter = 0; iter < size; iter++) {
            os << obj.list[iter] << ", ";
        }
        os << obj.list[size];
        os << "]";
        return os;
    }

    Object operator [] (const int &index) {
        return list[index];
    }

    List operator [] (const char *range) {
        
        if (len(range) == 1) {
            if(range[0] == ':') {
                List aux;
                aux.list = list;
                return aux;
            }
        }
        else if (len(range) == 2) {
            if (range[0] == ':' and range[1] == ':') {
                List aux;
                aux.list = list;
                return aux; 
            }
            else if(type(IntFromChar(range[0])) == "<class \'int\'>" and range[1] == ':') {
                List aux;
                const int start = IntFromChar(range[0]);
                const int stop = list.size();
                for(size_t iter = start; iter < stop; iter++) {
                    aux.append(list[iter]);
                }
                return aux;
            }
            else if(type(IntFromChar(range[1])) == "<class \'int\'>" and range[0] == ':') {
                List aux;
                const int stop = IntFromChar(range[1]);
                for(size_t iter = 0; iter < stop; iter++) {
                    aux.append(list[iter]);
                }
                return aux;
            }
        }
        else if (len(range) == 3) {
            if (range[0] == ':' and range[1] == ':' and 
                type(IntFromChar(range[2])) == "<class \'int\'>") {
                List aux;
                const int stop = list.size();
                const int step = IntFromChar(range[2]);
                for(size_t iter = 0; iter < stop; iter += step) {
                    aux.append(list[iter]);
                }
                return aux;
            }
            else if (type(IntFromChar(range[0])) == "<class \'int\'>" and range[1] == ':' and 
                type(IntFromChar(range[2])) == "<class \'int\'>") {
                List aux;
                const int start = IntFromChar(range[0]);
                const int stop = IntFromChar(range[2]);
                for(size_t iter = start; iter < stop; iter++) {
                    aux.append(list[iter]);
                }
                return aux;
            }
        }
        else if (len(range) == 4) {
            if (range[0] == ':' and range[1] == ':' and range[2] == '-' and range[3] == '1') {
                List aux;
                for(size_t iter = list.size() - 1; iter > 0; iter--) {
                    aux.append(list[iter]);
                }
                aux.append(list[0]);
                return aux;
            }
        }
        else if (len(range) == 5) {
            if (type(IntFromChar(range[0])) == "<class \'int\'>" and range[1] == ':' and
                type(IntFromChar(range[2])) == "<class \'int\'>" and range[3] == ':' and
                type(IntFromChar(range[4])) == "<class \'int\'>") {
                List aux;
                const int start = IntFromChar(range[0]);
                const int stop = IntFromChar(range[2]);
                const int step = IntFromChar(range[4]);
                for(size_t iter = start; iter < stop; iter += step) {
                    aux.append(list[iter]);
                }
                return aux;
            }
        }
    }

    List& operator = (const List &source) {
        if(this == &source) {
            return *this;
        }
        const int size = source.list.size();
        for(size_t iter = 0; iter < size; iter++) {
            list[iter] = source.list[iter];
        }
        return *this;
    }
};