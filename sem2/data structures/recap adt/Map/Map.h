//
// Created by Sonia Zagrean on 14.05.2025.
//
#pragma once
#include <string>

struct TElem{
    int key;
    std::string value;
};

class Map {
private:
    TElem* elems;
    int capacity;
    int len;

    void resize();

public:
    Map();
    ~Map();

    void add(int key, const std::string& value);
    bool remove(int key);
    bool search(int key) const;
    std::string getAt(int key) const;
    int size() const ;
    void printMap(int pos)const;
};
