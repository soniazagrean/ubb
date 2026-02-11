#include <iostream>

#include "Tests.h"
#include "UI.h"


int main() {
    runTests();
    Repository r;
    Service s(r);
    UI ui(s);
    ui.run();
}
