//
// Created by Sonia Zagrean on 19.05.2025.
//

#include "RepoFile.h"

#include <fstream>
#include <iostream>

void RepoFile::load() {
    std::ifstream fin(filename);
    std::string name;
    int code, price;
    products.clear();
    while (fin >> code >> name >> price) {
        Product p = Product(code, name, price);
        products.push_back(p);
    }
    fin.close();
}

void RepoFile::save() {
    std::ofstream fout(filename);
    for (auto& i : products)
        fout << i.getCode() << ' ' << i.getName() << ' ' << i.getPrice() << '\n';
}


RepoFile::RepoFile(const std::string& filename) : filename(filename) {
    load();
}

void RepoFile::add(const Product &product) {
    Repository::add(product);
    this->save();
}

void RepoFile::remove(const Product &product) {
    Repository::remove(product);
    this->save();
}

void RepoFile::update(int pos, const Product &product) {
    Repository::update(pos, product);
    this->save();
}
