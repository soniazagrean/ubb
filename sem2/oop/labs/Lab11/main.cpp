#include <iostream>

#include "RepoFile.h"
#include "Repository.h"
#include "Service.h"
#include "Tests.h"
#include "UI.h"

int main() {
    testAll();
    RepoFile repo("../products.txt");
    Repository& repoRef = repo;
    Service service(repoRef);
    UI ui(service);
    ui.run();
    return 0;
}

