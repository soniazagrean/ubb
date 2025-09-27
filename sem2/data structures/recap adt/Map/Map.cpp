#include "Map.h"
#include <iostream>

void Map::resize() {
    capacity *= 2;
    TElem* newElems = new TElem[capacity];
    for (int i = 0; i < len; ++i)
        newElems[i] = elems[i];
    delete[] elems;
    elems = newElems;
}

Map::Map() {
    capacity = 2;
    len = 0;
    elems = new TElem[capacity];
}

Map::~Map() {
    delete[] elems;
}

void Map::add(int key, const std::string &value) {
    // Check if key exists — if so, update
    for (int i = 0; i < len; ++i) {
        if (elems[i].key == key) {
            elems[i].value = value;
            return;
        }
    }
    // If not found, append new element
    if (len == capacity)
        resize();
    elems[len++] = TElem{key, value};
}

bool Map::remove(int key) {
    for (int i = 0; i < len; ++i) {
        if (elems[i].key == key) {
            // Shift left
            for (int j = i; j < len - 1; ++j)
                elems[j] = elems[j + 1];
            len--;
            return true;
        }
    }
    return false;
}

bool Map::search(int key) const {
    for (int i = 0; i < len; ++i)
        if (elems[i].key == key)
            return true;
    return false;
}

std::string Map::getAt(int key) const {
    for (int i = 0; i < len; ++i)
        if (elems[i].key == key)
            return elems[i].value;
    return "";
}

int Map::size() const {
    return len;
}

void Map::printMap(int pos) const {
    if (pos >= 0 && pos < len)
        std::cout << elems[pos].key << ' ' << elems[pos].value << '\n';
    else
        std::cout << "Invalid position\n";
}
