#include<iostream>
#include "produs_dulce.h"
#include "ProdusSarat.h"
#include "Tests.h"
#include "RepositoryTests.h"
using namespace std;

int main() {
    ProdusDulce produsDulce = ProdusDulce("candy", 10);
    produsDulce.display();
    ProdusSarat produsSarat = ProdusSarat("cracker", 10 , 20);
    produsSarat.display();
    testController();
    produsDulceTests();
    produsSaratTests();
    RepositoryTests();
    RepositoryTestsGetter();
    return 0;
}
