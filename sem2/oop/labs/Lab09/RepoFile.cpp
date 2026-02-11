//
// Created by Sonia Zagrean on 03.05.2025.
//

#include <fstream>
#include "RepoFile.h"

void RepoFile::loadFromFile() {
    items.clear();
    std::ifstream fin(filename);
    int c;
    std::string n;
    double p;
    while (fin >> c >> n >> p)
        items.emplace_back(c, n, p);
    fin.close();
}

void RepoFile::saveToFile() {
    std::ofstream fout(filename);
    for (const auto& i : items)
        fout << i.getCode() << ' ' << i.getName() << ' ' << i.getPrice() << '\n';
}

RepoFile::RepoFile(const std::string &filename) : filename(filename) { loadFromFile(); }

void RepoFile::addItem(const Product &item) {
    Repository::addItem(item);
    saveToFile();
}

void RepoFile::removeItem(const Product &item) {
    Repository::removeItem(item);
    saveToFile();
}
