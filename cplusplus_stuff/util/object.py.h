#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include "builtins.py.h"

using namespace std;

class Object {

    int atr_int;
    float atr_float;
    double atr_double;
    char atr_char;
    char *atr_charp;
    string atr_string;
    int index = -1;
    unsigned int instantiation_per_scope = 0;
    string type_error_msg = "<Incorrect data type>";
    
    //TODO new data types
    vector<int> vec_int;
    vector<char> vec_char;
    vector<string> vec_string;
    vector<double> vec_double;


public:

    template <typename T>
    void InitInt(const T &arg) {
        if (type(arg) != "<class \'int\'>") {
            throw TypeError(type_error_msg);
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
            throw TypeError(type_error_msg);
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
            throw TypeError(type_error_msg);
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
            throw TypeError(type_error_msg);
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
            throw TypeError(type_error_msg);
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
            throw TypeError(type_error_msg);
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
            
        }
        else {
            os << "None";
        }
        return os;
    }

    Object& operator = (const int &arg) {
        atr_int = arg;
        index = 0;
        return *this;
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