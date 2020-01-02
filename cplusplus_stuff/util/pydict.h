#pragma once

#include <iostream>
#include <map>
#include "builtins.py.h"

using namespace std;


template <class Key, class Value>
class Dict {

public:
    map<Key, Value> dict;

    pair<Key, Value> p(const Key &key, const Value &value) {
        return pair<Key, Value>(key, value);
    }

    void add(const Key &key, const Value &value) {
        dict.insert(p(key, value));
    }

    string operator [] (const Key &key) {
        // ????
        return dict[key];
    }
 
};