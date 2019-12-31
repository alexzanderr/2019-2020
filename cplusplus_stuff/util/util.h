#pragma once

#include <iostream>
#include <typeinfo>
#include <string>
#include <cstring>
#include <cmath>
#include <sstream>
#include <cstdlib>

using namespace std;

namespace Util{

    namespace PrintArrays {
        // just printing some arrays
        template<typename T>
        void PrintArray(const T *arr, const int &len) {
            cout << "[ ";
            for(size_t iter = 0; iter < len; iter++) {
                cout << arr[iter] << ' ';
            }
            cout << "]" << endl;
        }
    }

    namespace Memory {

        // copy a std::string array to char* array
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
            string aux = arr;
            return aux;
        }

    }

    namespace PythonBuiltIn {
        // built-in functions from python <3

        using namespace Util::PrintArrays;
        using namespace Util::Memory;

        // print function from python
        // available for: int, float, double, char, string; NOT arrays or objects, yet

        void print() {
            cout << endl;
        }

        template <typename T>
        void print(T &arg, const string end="\n") {
            cout << arg << end;
        }

        template <typename T>
        void print(const T &arg, const string end="\n") {
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
            else if(arg_type == "7PointerINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE") {
                return "<class \'pointer_to_std::string\'>";
            }
            else if(arg_type == "PKc") {
                return "<class \'pointer_const_char\'>";
            }
            else if(arg_type == "6Object") {
                return "<class \'Object\' from \'util.h\'>";
            }
            else if(arg_type == "4List") {
                return "<class \'List\' from \'list.h\'>";
            }
            else {
                return "<class 'None'>";
            }
        }
        
        // len function from python

        int len(const char *arr) {
            return strlen(arr);
        }

        int len(const string &str) {
            return str.size();
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

        // str
        template <typename T>
        string str(const T &object) {
            ostringstream oss;
            oss << object;
            string result(oss.str());
            return result;
        }

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
            string arg_str = str(arg);
            if (len(arg_str) != 1) {
                return char(arg_str[0]);
            }
            return char(int(arg));
        }

        char ToChar(const double &arg) {
            string arg_str = str(arg);
            if (len(arg_str) != 1) {
                return char(arg_str[0]);
            }
            return char(int(arg));
        }
        
        //TODO: ToFloat, ToDouble
    }
}