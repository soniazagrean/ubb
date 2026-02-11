#include <iostream>

#include "tests.h"
#include "operations.h"
#include "Service.h"
#include "UI.h"

int main() {
    // testStudent();
    // testRepository();
    // testService();
    // int result_size = 0;
    // Student result[50];
    Repository repository("../students.txt");
    Service service(repository);
    UI ui(service);

    ui.showAll();

    return 0;
}