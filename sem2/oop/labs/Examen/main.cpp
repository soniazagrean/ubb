#include <cassert>
#include <iostream>

#include "Repository.h"
#include "Service.h"
#include "Tests.h"
#include "UI.h"



int main() {
    runTests();
    std::cout << "[Tests passed]\n";

    Repository r;
    Validator v;
    Service s(r, v);
    UI ui(s);
    ui.run();
    return 0;
}
