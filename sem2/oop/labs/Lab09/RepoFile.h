//
// Created by Sonia Zagrean on 03.05.2025.
//

#ifndef REPOFILE_H
#define REPOFILE_H

#include <string>
#include "Product.h"
#include "Repository.h"

class RepoFile : public Repository {
private:
    std::string filename;
    void loadFromFile();
    void saveToFile();

public:
    explicit RepoFile(const std::string &filename);
    void addItem(const Product& item) override;
    void removeItem(const Product& item) override;
};




#endif //REPOFILE_H
