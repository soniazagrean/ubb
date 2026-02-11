#include <iostream>

#include "Service.h"
#include "RepoFile.h"
#include "UI.h"
#include <unistd.h>

void checkMemoryLeaks() {
    std::cout << "\n[INFO] Checking memory leaks...\n";
    char command[64];
    sprintf(command, "leaks %d", getpid());
    system(command);
}

int main() {
    atexit(checkMemoryLeaks);
    // Repository<Product> repo;
    // Service s(repo);
    // Product p1(12, "ciocolata", 33.2);
    // Product p2(3, "paine", 6.2);
    // Product p3(9, "apa", 8.9);
    // s.add(p1);
    // s.add(p2);
    // s.add(p3);
    // auto v = s.get();
    // for (auto &i : v)
    //     std::cout << i.getCode() << ' ' << i.getName() << ' ' << i.getPrice() << '\n';
    // // s.remove(p2);
    // // v = s.get();
    // // for (auto &i : v)
    // //     std::cout << i.getCode() << ' ' << i.getName() << ' ' << i.getPrice() << '\n';
    // int uiPrice = 0;
    // double change = 0;
    // std::cout << "ui price = ";
    // std::cin >> uiPrice;
    // if (s.buyProduct(12, uiPrice, change) == 1)
    //     std::cout << change << ' ';
    // else
    //     std::cout << "none";
    RepoFile fileRepo("../products.txt");
    Service service(fileRepo);
    UI ui(service);
    ui.run();
    return 0;
}
