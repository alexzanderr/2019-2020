#pragma once

#include <iostream>
#include "util.h"
#include "exceptions.h"
#include <cctype>

using namespace std;
using namespace Util::PrintArrays;

class Range {
    // class range from python

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