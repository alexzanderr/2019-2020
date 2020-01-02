#pragma once

#include <iostream>
#include <exception>

using namespace std;

class ParameterError : public exception {
    
    string message;

public:
    
    ParameterError() {
        message = "ParameterError cause unknown...";
    }

    ParameterError(const string &mess) {
        message = mess;
    }

    string GetMessage() {
        return message;
    }

} parameter_error;

class InstantiationError : public exception {

    string message;

public:
    
    InstantiationError() {
        message = "InstantiationError cause unknown...";
    }

    InstantiationError(const string &mess) {
        message = mess;
    }

    string GetMessage() {
        return message;
    }
} instantiation_error;

class TypeError : public exception {

    string message;

public:

    TypeError() {
        message = "TypeError cause unknown...";
    }

    TypeError(const string &mess) {
        message = mess;
    }

    string GetMessage() {
        return message;
    }

};

class ValueError : public exception {

    string message;

public:

    ValueError() {
        message = "TypeError cause unknown...";
    }

    ValueError(const string &mess) {
        message = mess;
    }

    string GetMessage() {
        return message;
    }

};