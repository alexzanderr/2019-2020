#pragma once
// built-in functions from python <3
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <typeinfo>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "exceptions.py.h"

using namespace std;

#define __int_limit__ 1000000
#define __char_limit__ 100000

const double PI = 3.14159265358979323846; // 1 + 20 digits of PI
const double EulerNumber = 2.71828182845904523536; // 1 + 20 digits of Euler constant


// string conversions
char* CharArrayFromString(const string &str) {
    const int str_size = str.size();
    char *copy = new char[str_size - 1];
    for(int iter = 0; iter < str_size; iter++) {
        copy[iter] = str[iter];
    }
    copy[str_size] = 0;
    return copy;
}

char* CharArrayFromString(const char *arr) {
    const int arr_size = strlen(arr); 
    char *copy = new char[arr_size + 1];
    for(int iter = 0; iter < arr_size; iter++) {
        copy[iter] = arr[iter];
    }
    copy[arr_size] = 0;
    return copy;
}

// reverse of the previous one
string StringFromCharArray(const char *arr) {
    string result = "";
    const int arr_size = strlen(arr);
    for(size_t iter = 0; iter < arr_size; iter++) {
        result += arr[iter];
    }
    return result;
}

string StringFromCharArray(const string &arr) {
    return arr;
}


int TotalDigits(const int &number) {
    return floor(log10(number)) + 1;
}

int* IterableFromInt(const int &number) {
    int cn = number;
    const int size = TotalDigits(number);
    int *iterable = new int[size];
    for(size_t counter = size - 1; counter > 0; counter--) {
        iterable[counter] = cn % 10;
        cn /= 10;
    }
    iterable[0] = cn % 10;
    return iterable;
}

// len function from python
int len(const char *arr) {
    return strlen(arr);
}

int len(const string &str) {
    return str.size();
}


int len(const int *arr) {
    int length = 0;
    for(size_t iter = 0; ; iter++) {
        if(arr[iter] >= __int_limit__ or arr[iter] == 0) {
            break;
        }
        length++;
    }
    return length;
}

int lenfre(const int *arr) {
    int length = 0;
    for(size_t iter = 0; ; iter++) {
        if(arr[iter] != 0) {
            break;
        }
        length++;
    }
    return length;
}

int lenfre(int *arr) {
    int length = 0;
    for(size_t iter = 0; ; iter++) {
        if(arr[iter] != 0) {
            break;
        }
        length++;
    }
    return length;
}

void printarr(const int *arr) {
    const int size = len(arr) - 1;
    cout << "[";
    for(size_t iter = 0; iter < size; iter++) {
        cout << arr[iter] << ", ";
    }
    cout << arr[size] << "]" << endl;
}

void printarr(int *arr, const int &dim = -1) {
    int size;
    if (dim != -1) {
        size = dim - 1;
    }
    else {
        size = len(arr) - 1;
    }
    cout << "[";
    for(size_t iter = 0; iter < size; iter++) {
        cout << arr[iter] << ", ";
    }
    cout << arr[size] << "]" << endl;
}

void printarr(const char *arr) {
    const int size = len(arr) - 1;
    cout << "[";
    for(size_t iter = 0; iter < size; iter++) {
        cout << arr[iter] << ", ";
    }
    cout << arr[size] << "]" << endl;
}

void printarr(const string &arr) {
    const int size = len(arr) - 1;
    cout << "[";
    for(size_t iter = 0; iter < size; iter++) {
        cout << arr[iter] << ", ";
    }
    cout << arr[size] << "]" << endl;
}

void printarr(int **matrix) {
    const int size = len(matrix[0]);
    for(size_t iter = 0; iter < size; iter++) {
        cout << "[";
        for(size_t jiter = 0; jiter < size - 1; jiter++) {
            cout << matrix[iter][jiter] << ", ";
        }
        cout << matrix[iter][size - 1] << "]\n";
    }
    cout << endl;
}

void printarr(const int **matrix) {
    const int size = len(matrix[0]);
    for(size_t iter = 0; iter < size; iter++) {
        cout << "[";
        for(size_t jiter = 0; jiter < size - 1; jiter++) {
            cout << matrix[iter][jiter] << ", ";
        }
        cout << matrix[iter][size - 1] << "]\n";
    }
    cout << endl;
}

// type from python
template <typename T>
string type(const T &arg) {
    string arg_type = typeid(arg).name();
    if (arg_type == "i") {
        return "<class \'int\'>";
    }
    else if (arg_type == "d") {
        return "<class \'double\'>";
    }
    else if (arg_type == "f") {
        return "<class \'float\'>";
    }
    else if (arg_type == "c") {
        return "<class \'char\'>";
    }
    else if (arg_type == "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE") {
        return "<class \'std::string\'>";
    }
    else if (arg_type[0] == 'A' and arg_type[arg_type.size() - 1] == 'c') {
        return "<class \'string_constant\'>";
    }
    else if (arg_type == "Pc") {
        return "<class \'pointer_char\'>";
    }
    else if (arg_type == "Pi") {
        return "<class \'pointer_int\'>";
    }
    else if (arg_type == "PPc") {
        return "<class \'pointer_to_pointer_char\'>";
    }
    else if (arg_type == "PPi") {
        return "<class \'pointer_to_pointer_int\'>";
    }
    else if (arg_type == "7PointerINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE") {
        return "<class \'pointer_to_std::string\'>";
    }
    else if (arg_type == "PKc") {
        return "<class \'pointer_const_char\'>";
    }
    else if (arg_type == "6Object") {
        return "<class \'Object\' from \'util.h\'>";
    }
    else if (arg_type == "4List") {
        return "<class \'List\' from \'list.h\'>";
    }
    else if (arg_type == "b") {
        return "<class \'bool\'>";
    }
    else if (arg_type == "6String") {
        return "<class \'String\' from \'builtins.py.h\'>";
    }
    return "<class 'None'>";
}

// str
template <typename T>
string ToString(const T &object) {
    ostringstream oss;
    oss << object;
    string result(oss.str());
    return result;
}

// print function from python
void print() {
    cout << endl;
}

template <typename T>
void print(T &arg, const string end="\n") {
    cout << arg << end;
}

template <typename T>
void print(const T &arg, const string end="\n") {
    if (type(arg) == "<class \'bool\'>") {
        string val = ToString(arg);
        if (val == "1") {
            cout << "True" << end;
        }
        else if (val == "0") {
            cout << "False" << end;
        }
        return;
    }
    else if (type(arg) == "<class \'std::string\'>" or 
                type(arg) == "<class \'char\'>" or 
                type(arg) == "<class \'string_constant\'>" or
                type(arg) == "<class \'pointer_char\'>") {
        cout << "\'" << arg << "\'" << end;
        return;
    }
    cout << arg << end;
}

template <typename T1, typename T2>
void print(T1 &arg1, 
        T2 &arg2, 
        const string sep=" ", 
        const string end="\n") {
    cout << arg1 << sep << arg2 << end;
}

template <typename T1, typename T2>
void print(const T1 &arg1, 
        const T2 &arg2, 
        const string sep=" ", 
        const string end="\n") {
    cout << arg1 << sep << arg2 << end;
}

template <typename T1, typename T2, typename T3>
void print(T1 &arg1, 
        T2 &arg2, 
        const T3 &arg3,
        const string sep=" ", 
        const string end="\n") {
    cout << arg1 << sep << arg2 << sep << arg3 << end;
}

template <typename T1, typename T2, typename T3, typename T4>
void print(T1 &arg1, 
        T2 &arg2, 
        T3 &arg3,
        T4 &arg4,
        const string sep=" ", 
        const string end="\n") {
    cout << arg1 << sep << arg2 << sep << arg3 << sep << arg4 << end;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
void print(const T1 &arg1, 
        const T2 &arg2, 
        const T3 &arg3,
        const T4 &arg4,
        const T4 &arg5,
        const string sep=" ", 
        const string end="\n") {
    cout << arg1 << sep << arg2 << sep << arg3 << sep << arg4 << sep
        << arg5 << end;
}

template <typename T1, 
        typename T2, 
        typename T3, 
        typename T4, 
        typename T5,
        typename T6>
void print(const T1 &arg1, 
        const T2 &arg2, 
        const T3 &arg3,
        const T4 &arg4,
        const T5 &arg5,
        const T6 &arg6,
        const string sep=" ", 
        const string end="\n") {
    cout << arg1 << sep << arg2 << sep << arg3 << sep << arg4 << sep
        << arg5 << sep << arg6 << end;
}

// prints a character multiple times
template <typename T>
void printt(const T &arg, const int &times) {
    for(size_t iter = 0; iter < times; iter++) {
        cout << arg;
    }
    cout << endl;
}

// id from python
template <typename T>
T* id(T &arg) {
    return &arg;
}

// input from python
string input(const string &text="") {
    string inputt;
    print(text);
    getline(cin, inputt);
    return inputt;
}

// conversions from python
char CharFromDigit(const int &digit) {
    switch (digit) {
        case 0: 
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default:
            return '\0';
    }
}

// conversions to integer
int IntFromChar(const char &ch) {
    return ch - '0';
}

int IntFromString(const string &str) {
    char *result = CharArrayFromString(str);
    return atoi(result);
}

int IntFromCharPointer(const char *charr) {
    char *result = CharArrayFromString(charr);
    return atoi(result);
}

// to chars because we need to predict the data type
char ToChar(const string &arr) {
    return char(arr[0]);
}

char ToChar(const char *arr) {
    return char(arr[0]);
}

char ToChar(const int &arg) {
    return char(arg);
}

char ToChar(const float &arg) {
    string arg_str = ToString(arg);
    if (len(arg_str) != 1) {
        return char(arg_str[0]);
    }
    return char(int(arg));
}

char ToChar(const double &arg) {
    string arg_str = ToString(arg);
    if (len(arg_str) != 1) {
        return char(arg_str[0]);
    }
    return char(int(arg));
}

//TODO: ToFloat, ToDouble

// swaps
template <typename T>
void swapp(T *arg1, T *arg2) {
    T aux = *arg1;
    *arg1 = *arg2;
    *arg2 = aux; 
}

template <typename T>
void swapr(T &arg1, T &arg2) {
    T aux = arg1;
    arg1 = arg2;
    arg2 = aux;
}




#include "pylist.h"



int len(const IntArray &arr) {
    return arr.Len();
}

List ListFromInteger(const int &number) {
    int *arr = IterableFromInt(number);
    const int size = len(arr);
    List iterable;
    for(size_t iter = 0; iter < size; iter++) {
        iterable.append(arr[iter]);
    }
    return iterable;
}

List ListFromCharArr(const char *arr) {
    const int size = len(arr);
    List iterable;
    for(size_t iter = 0; iter < size; iter++) {
        iterable.append(arr[iter]);
    }
    return iterable;
}

List ListFromString(const string &arr) {
    const int size = len(arr);
    List iterable;
    for(size_t iter = 0; iter < size; iter++) {
        iterable.append(arr[iter]);
    }
    return iterable;
}

// sum from python
int sum(const List &arr) {
    int result = 0;
    List aux;
    aux = arr;
    const int stop = aux.Len();
    for(size_t iter = 0; iter < stop; iter++) {
        result += aux[iter].GetInt();
    }
    return result;
}

int sum(const int *arr) {
    int result = 0;
    const int stop = len(arr);
    for(size_t iter = 0; iter < stop; iter++) {
        result += arr[iter];
    }
    return result;
}

int max(const int &arg1, const int &arg2) {
    int result = arg1 > arg2 ? arg1 : arg2;
    return result;
}

int max(const IntArray &arr) {
    int maxx = 0;
    const int size = arr.Len();
    for(size_t iter = 0; iter < size; iter++) {
        maxx = arr[iter] > maxx ? arr[iter] : maxx;
    }
    return maxx;
}


#include <climits>

void AsciiTable() {
    for (unsigned char iter = 0; iter != UCHAR_MAX; iter++) {
        cout << char(iter) << " = " << iter << '\n';
    }
    cout << endl;
}

#include "pyalgo.h"

int* sorted(int *arr) {
    int *result = arr;
    QuickSort(result, 0, len(arr) - 1);
    return result;
}

class String {

    string str;

public:

    String():
        str(""){}

    String(const char *arr) {
        str = StringFromCharArray(arr);
    }

    String(const string &arg) {
        str = arg;
    }

    int Len() const {
        return str.size();
    }

    string GetContent() const {
        return str;
    }

    bool Vowel(const char &ch) {
        char chc = toupper(ch);
        switch(chc)
        {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
        }
        return false;
    }

    bool HasOnlyVowel(const char *arr) {
        const int size = len(arr);
        for(size_t iter = 0; iter < size; iter++) {
            if(not Vowel(arr[iter])) {
                return false;
            }
        }
        return true;
    }

    bool HasOnlyVowel(const string &arr) {
        const int size = arr.size();
        for(size_t iter = 0; iter < size; iter++) {
            if(not Vowel(arr[iter])) {
                return false;
            }
        }
        return true;
    }

    char operator [] (const int &index) const {
        return str[index];
    }

    bool HasOnlyVowel(const String &str) {
        const int size = str.Len();
        for(size_t iter = 0; iter < size; iter++) {
            if(not Vowel(str[iter])) {
                return false;
            }
        }
        return true;
    }

    bool PalindromeWord(const char *arr) {
        int start = 0;
        int stop = len(arr) - 1;
        bool result = true;
        while (start < stop) {
            if (arr[start] != arr[stop]) {
                return false;
            }
            start++;
            stop--;
        }
        return true;
    }

    bool PalindromeWord(const string &arr) {
        int start = 0;
        int stop = arr.size() - 1;
        bool result = true;
        while (start < stop) {
            if (arr[start] != arr[stop]) {
                return false;
            }
            start++;
            stop--;
        }
        return true;
    }

    bool PalindromeWord(const String &str) {
        int start = 0;
        int stop = str.Len() - 1;
        bool result = true;
        while (start < stop) {
            if (str[start] != str[stop]) {
                return false;
            }
            start++;
            stop--;
        }
        return true;
    }

    List split(const char *sep=" ") {
        if (str == "") {
            throw ValueError("Class atribute is void string");
        }
        List result;
        char *arr = CharArrayFromString(str);
        char *word = new char[__char_limit__];
        word = strtok(arr, sep);
        while (word) {
            result.append(word);
            word = strtok(NULL, sep);
        }
        return result;
    }

    String format(const string &structure, const string &arg) {
        string left = "";
        int index;
        for(size_t iter = 0; ; iter++) {
            if (structure[iter] == '{') {
                index = iter;
                break;
            }
            left += structure[iter];
        }
        left += arg;
        const int size = structure.size();
        int pass = 2;
        if (structure[index + 1] == '0') {
            pass = 3;
        }
        for(size_t iter = index + pass; iter < size; iter++) {
            left += structure[iter];
        }
        String result = left;
        return result;
    }

    String format(const string &structure, const int &arg) {
        string left = "";
        string argt = ToString(arg);
        int index;
        for(size_t iter = 0; ; iter++) {
            if (structure[iter] == '{') {
                index = iter;
                break;
            }
            left += structure[iter];
        }
        left += argt;
        const int size = structure.size();
        int pass = 2;
        if (structure[index + 1] == '0') {
            pass = 3;
        }
        for(size_t iter = index + pass; iter < size; iter++) {
            left += structure[iter];
        }
        String result = left;
        return result;
    }

    String format(const string &structure, const string &arg1, const string &arg2) {
        string test = "asdad asd {0} asdasd asd {1} asdasdas";
        string left = "";
        int index;
        for(size_t iter = 0; ; iter++) {
            if (structure[iter] == '{') {
                index = iter;
                break;
            }
            left += structure[iter];
        }
        
        int pass = 2;
        if (structure[index + 1] == '0') {
            pass = 3;
            left += arg1;
        }
        else if (structure[index + 1] == '1') {
            left += arg2;
            pass = 3;
        }
        else {
            left += arg1;
        }

        for(size_t iter = index + pass; ; iter++) {
            if (structure[iter] == '{') {
                index = iter;
                break;
            }
            left += structure[iter];
        }

        pass = 2;
        if (structure[index + 1] == '0') {
            pass = 3;
            left += arg1;
        }
        else if (structure[index + 1] == '1') {
            left += arg2;
            pass = 3;
        }
        else {
            left += arg2;
        }

        const int size = structure.size();
        for(size_t iter = index + pass; iter < size; iter++) {
            left += structure[iter];
        }

        String result = left;
        return result;
    }

    String& operator = (const string &source) {
        str = source;
        return *this;
    }

    String& operator = (const char *source) {
        str = StringFromCharArray(source);
        return *this;
    }

    friend ostream& operator<< (ostream& os, const String &obj) {
        os << obj.str;
        return os;
    }
};

class Range {
    // class range from python
    // range function overloaded +2 times
    // get size func
    // generate sequence

    int _start = INT32_MIN;
    int _stop = INT32_MIN;
    int _step = INT32_MIN;
    int _size = INT32_MIN;

public:
    int* range(const int &stop) {
        if (stop < 0) {
            throw parameter_error;
        }
        _start = 0;
        _stop = stop;
        _step = 1;
        int *sequence = new int[_stop];
        for(size_t iter = 0; iter < _stop; iter++) {
            sequence[iter] = iter;
        }
        _size = _stop;
        return sequence;
    }

    int* range(const int &start, const int &stop) {
        if (stop < start) {
            throw parameter_error;
        }
        _start = start;
        _stop = stop;
        _step = 1;
        const int size = abs(stop - start);
        int *sequence = new int[size];
        int index = 0;
        int dim = 0;
        for(size_t iter = _start; iter < _stop; iter++) {
            sequence[index++] = iter;
            dim++;
        }
        _size = dim;
        return sequence;
    }

    int* range(const int &start, const int &stop, const int &step) {
        if (start > 0 and stop > 0) {
            if (start < stop and step < 1) {
                throw parameter_error;
            }
            else if (stop < start and step > -1) {
                throw parameter_error;
            }
        }
        else if (start < 0 and stop < 0) {
            if (start > stop and step > - 1) {
                throw parameter_error;
            }
            else if (start < stop and step < -1) {
                throw parameter_error;
            }
        }
        else if (start < 0 and stop > 0) {
            if(start < stop and step < -1) {
                throw parameter_error;
            }
        }
        else if (start > 0 and stop < 0) {
            if (start > stop and step > 1) {
                throw parameter_error;
            }
        }
        _start = start;
        _stop = stop;
        _step = step;
        const int size = abs(stop - start);
        int *sequence = new int[size];
        int index = 0;
        int dim = 0;
        for(size_t iter = _start; iter < _stop; iter += step) {
            sequence[index++] = iter;
            dim++;
        }
        _size = dim;
        return sequence;
    }

    int GetSize() const {
        return _size;
    }
};