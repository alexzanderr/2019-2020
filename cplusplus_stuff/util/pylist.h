#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "exceptions.py.h"
#include "builtins.py.h"
#include "object.py.h"

using namespace std;

class List {
    // list from python
public:
    vector<Object> list;
    int standard_size = __int_limit__;

    List() {
        
    }

    List(const int &size) {
        for(size_t iter = 0; iter < size; iter++) {
             Object elem;
             list.push_back(elem);
        }
    }

    List& operator = (const List &source) {
        if(this == &source) {
            return *this;
        }
        list.clear();
        const int size = source.list.size();
        for(size_t iter = 0; iter < size; iter++) {
            list[iter] = source.list[iter];
        }
        return *this;
    }

    List& operator = (const int *source) {
        list.clear();
        const int size = len(source);
        for(size_t iter = 0; iter < size; iter++) {
            Object elem;
            elem.InitInt(source[iter]);
            list.push_back(elem);
        }
        return *this;
    }

    List& operator = (const char *source) {
        list.clear();
        const int size = len(source);
        for(size_t iter = 0; iter < size; iter++) {
            Object elem;
            elem.InitChar(source[iter]);
            list.push_back(elem);
        }
        return *this;
    }

    List& operator = (const string source) {
        list.clear();
        const int size = len(source);
        for(size_t iter = 0; iter < size; iter++) {
            Object elem;
            elem.InitChar(source[iter]);
            list.push_back(elem);
        }
        return *this;
    }


    /*
    List& operator = (const int &source) {
        list.clear();
        const int size = len(source);
        for(size_t iter = 0; iter < size; iter++) {
            Object elem;
            elem.InitChar(source[iter]);
            list.push_back(elem);
        }
        return *this;
    }
    */

    int Len() const {
        return list.size();
    }

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
        List aux;
        return aux;
    }
};

#include <deque>
#include <ctime>

class IntArray {

    deque<int> array;

public:

    IntArray() {

    }

    IntArray(const int& size) {
        for(size_t iter = 0; iter < size; iter++) {
            array.push_back(0);
        }
    }

    void append(const int &value) {
        array.push_back(value);
    }

    void appendf(const int &value) {
        array.push_front(value);
    }
    
    void Clear() {
        array.clear();
    }


    IntArray InitRandom(const int &length) {
        array.clear();
        srand(time(0));
        for(size_t iter = 0; iter < length; iter++) {
            const int random_value = rand() % 200 + 1;
            array.push_back(random_value);
        }
        IntArray result;
        result = array;
        return result;
    }

    friend ostream& operator<< (ostream& os, const IntArray &obj) {
        const int size = obj.Len() - 1;
        os << "[";
        for(size_t iter = 0; iter < size; iter++) {
            os << obj[iter] << ", ";
        }
        os << obj[size];
        os << "]";
        return os;
    }

    int operator [] (const int &index) const {
        return array[index];
    }

    IntArray& operator = (const deque<int> &source) {
        array.clear();
        const int size = source.size();
        for(size_t iter = 0; iter < size; iter++) {
            array.push_back(source[iter]);
        }
        return *this;
    }

    IntArray& operator = (const IntArray &source) {
        array.clear();
        const int size = source.array.size();
        for(size_t iter = 0; iter < size; iter++) {
            array.push_back(source[iter]);
        }
        return *this;
    }

    IntArray& operator = (const int *source) {
        array.clear();
        const int size = len(source);
        print(size);
        for(size_t iter = 0; iter < size; iter++) {
            array.push_back(source[iter]);
        }
        return *this;
    }

    bool In(const int &elem, const int *arr) {
        const int size = len(arr);
        for(size_t iter = 0; iter < size; iter++) {
            if (elem == arr[iter]) {
                return true;
            }
        }
        return false;
    }

    bool In(const int &elem, int *arr) {
        const int size = len(arr);
        for(size_t iter = 0; iter < size; iter++) {
            if (elem == arr[iter]) {
                return true;
            }
        }
        return false;
    }

    bool In(const int &elem, const deque<int> &arr) {
        const int size = arr.size();
        for(size_t iter = 0; iter < size; iter++) {
            if (elem == arr[iter]) {
                return true;
            }
        }
        return false;
    }

    bool In(const int &elem, const IntArray &arr) {
        const int size = arr.Len();
        for(size_t iter = 0; iter < size; iter++) {
            if (elem == arr[iter]) {
                return true;
            }
        }
        return false;
    }

    bool Equal(const int *arr) {
        const int size = len(arr);
        for(size_t iter = 0; iter < size; iter++) {
            if (array[iter] != arr[iter]) {
                return false;
            }
        }
        return true;
    }

    bool Equal(const deque<int> &arr) {
        const int size = arr.size();
        for(size_t iter = 0; iter < size; iter++) {
            if (array[iter] != arr[iter]) {
                return false;
            }
        }
        return true;
    }

    bool Equal(const IntArray &arr) {
        const int size = arr.Len();
        for(size_t iter = 0; iter < size; iter++) {
            if (array[iter] != arr[iter]) {
                return false;
            }
        }
        return true;
    }

    void SwapWithArray(int *arr) {
        const int size = len(arr);
        for(size_t iter = 0; iter < size; iter++) {
            int temp = arr[iter];
            arr[iter] = array[iter];
            array[iter] = temp;
        }
    }

    void SwapWithArray(deque<int> &arr) {
        const int size = arr.size();
        for(size_t iter = 0; iter < size; iter++) {
            int temp = arr[iter];
            arr[iter] = array[iter];
            array[iter] = temp;
        }
    }

    IntArray LeftPermutation() {
        const int size = array.size();
        const int first = array[0];
        for(size_t iter = 1; iter < size; iter++) {
            array[iter - 1] = array[iter];
        }
        array[size - 1] = first;
        IntArray result;
        result = array;
        return result;
    }

    IntArray RightPermutation() {
        const int size = array.size();
        const int last = array[size - 1];
        for(size_t iter = size - 1; iter > 0; iter--) {
            array[iter] = array[iter - 1]; 
        }
        array[0] = last;
        IntArray result;
        result = array;
        return result;
    }

    /* mai vedem
    void SwapWithArray(const IntArray &arr) {
        const int size = arr.Len();
        for(size_t iter = 0; iter < size; iter++) {
            int temp = arr[iter];
            arr[iter] = array[iter];
            array[iter] = temp;
        }
    }
    */

    int Len() const {
        return array.size();
    }
};