//
// Created by Sonia Zagrean on 19.05.2025.
//

#ifndef REPOFILE_H
#define REPOFILE_H
#include <string>

#include "Repository.h"


class RepoFile : public Repository {
private:
    std::string filename;
    void load();
    void save();

public:
    explicit RepoFile(const std::string& filename);
    void add(const Product& product) override;
    void remove(const Product& product) override;
    void update(int pos, const Product& product) override;
};



#endif //REPOFILE_H
