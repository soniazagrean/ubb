//
// Created by Sonia Zagrean on 19.05.2025.
//

#include "Tests.h"

#include <cassert>
#include <fstream>
#include <iostream>

#include "Product.h"
#include "RepoFile.h"
#include "Repository.h"
#include "Service.h"

void testProduct() {
    Product p1(2, "prajitura", 10);
    Product p2(1, "caramea", 5);
    Product p3(3, "briosa", 15);
    Product p4(3, "briosa", 15);
    assert(p1.getCode() == 2 && p1.getName() == "prajitura" && p1.getPrice() == 10);
    p2.setCode(4);
    p2.setName("bomboana");
    p2.setPrice(2);
    assert(p2.getCode() == 4 && p2.getName() == "bomboana" && p2.getPrice() == 2);
    assert(p3 == p4);
    p2 = Product(p3);
    assert(p2 == p3);
    p2 = Product(p2);
    assert(p2 == p2);
}

void testRepo() {
    Repository repo;
    Product p1(2, "prajitura", 10);
    Product p2(1, "caramea", 5);
    Product p3(3, "briosa", 15);
    Product p4(3, "briosa", 15);
    repo.add(p1);
    repo.add(p2);
    repo.add(p3);
    repo.add(p4);
    std::vector<Product> res = repo.get();
    assert(res[0] == p1 && res[1] == p2 && res[2] == p3 && res[3] == p4);
    repo.remove(p2);
    res = repo.get();
    assert(res[0] == p1 && res[1] == p3 && res[2] == p4);
    repo.update(1, Product(4, "caramea", 3));
    res = repo.get();
    assert(res[1] == Product(4, "caramea", 3));
    try {
        repo.update(-1, Product(4, "caramea", 3));
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }

}

void resetTestFile() {
    std::ofstream fout("../test.txt");
    fout << "6 briosa 15\n9 prajitura 8\n1 caramea 5\n10 ciocolata 20\n";
    fout.close();
}

void testRepoFile() {
    resetTestFile();
    RepoFile repoF("../test.txt");
    std::vector<Product> result = repoF.get();
    assert(result[0] == Product(6, "briosa", 15));
    assert(result[1] == Product(9, "prajitura", 8));
    assert(result[2] == Product(1, "caramea", 5));
    assert(result[3] == Product(10, "ciocolata", 20));
    repoF.add(Product(20, "bomboana", 1));
    result = repoF.get();
    assert(result[4] == Product(20, "bomboana", 1));
    repoF.remove(Product(6, "briosa", 15));
    result = repoF.get();
    assert(result[0] == Product(9, "prajitura", 8));
    repoF.update(0, Product(6, "briosa", 15));
    result = repoF.get();
    assert(result[0] == Product(6, "briosa", 15));
    std::remove("../test.txt");
}

void testService() {
    Repository repo;
    Service service(repo);
    Product p1(2, "prajitura", 10);
    Product p2(1, "caramea", 5);
    Product p3(3, "briosa", 15);
    Product p4(3, "briosa", 15);
    service.addProduct(p1);
    service.addProduct(p2);
    service.addProduct(p3);
    service.addProduct(p4);
    std::vector<Product> res = service.getAll();
    assert(res[0] == p1 && res[1] == p2 && res[2] == p3 && res[3] == p4);
    service.removeProduct(p2);
    res = service.getAll();
    assert(res[0] == p1 && res[1] == p3 && res[2] == p4);
    service.updateProduct(1, Product(4, "caramea", 3));
    res = service.getAll();
    assert(res[1] == Product(4, "caramea", 3));
    try {
        service.updateProduct(-1, Product(4, "caramea", 3));
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }
    try {
        service.buyProduct(2, 30);
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }
    try {
        service.buyProduct(2, 5);
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }
    try {
        service.buyProduct(-1, 30);
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }
    try {
        service.buyProduct(2, 307);
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }
}

void testValidator() {
    try {
        Product p1(-2, "prajitura", 10);
        ProductValidator::validateStatic(p1);
        assert(false);
    }
    catch (const ValidationException& e) {
        assert(e.what() == "Code must be positive.");
    }

    try {
        Product p2(1, "caramea", -5);
        ProductValidator::validateStatic(p2);
        assert(false);
    }
    catch (const ValidationException& e) {
        assert(e.what() == "Price must be positive.");
    }

    try {
        Product p3(3, "", 15);
        ProductValidator::validateStatic(p3);
        assert(false);
    }
    catch (const ValidationException& e) {
        assert(e.what() == "Name cannot be empty.");
    }

    try {
        Product p4(-1, "", -10);
        ProductValidator::validateStatic(p4);
        assert(false);
    }
    catch (const ValidationErrorsException& e) {
        std::cout << e.what() << '\n';
    }

    try {
        Product p5(10, "bomboana", 5);
        ProductValidator::validateStatic(p5);
    }
    catch (...) {
        assert(false);
    }
}


void testAll() {
    testProduct();
    testRepo();
    testRepoFile();
    testService();
    std::cout << "all tests passed..\n";
}
