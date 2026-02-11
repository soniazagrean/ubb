#include <iostream>

#include "Controller.h"
#include "UI.h"
using namespace std;
#include "tests.h";

int main() {
    test_ProdusDulce();
    test_ProdusSarat();
    test_Repo_Dulce();
    test_Repo_Sarat();
    test_Repo_Mix();
    test_Service();

    cout << "Toate testele au trecut cu succes!" << endl;
    Repo repo;
    Controller service(repo);
    UI ui(service);
    ui.run();

    return 0;
}
