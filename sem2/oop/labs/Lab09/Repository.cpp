//
// Created by Sonia Zagrean on 03.05.2025.
//
#pragma once
#include "Repository.h"

void Repository::addItem(const Product &item) {
    items.push_back(item);
}

void Repository::removeItem(const Product &item) {
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

void Repository::update(int position, const Product& itemOther) {
    items.at(position) = itemOther;
}

int Repository::getSize() {
    return items.size();
}

std::vector<Product> Repository::getAll() {
    return items;
}
