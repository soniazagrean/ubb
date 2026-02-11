//
// Created by Sonia Zagrean on 19.05.2025.
//

#include "Service.h"

void Service::addProduct(const Product &product) {
    try {
        ProductValidator::validateStatic(product);
        repo.add(product);
    }
    catch (const ValidationException& e) {
        throw;
    }
}

void Service::removeProduct(const Product &product) {
    try {
        ProductValidator::validateStatic(product);
        repo.remove(product);
    }
    catch (const ValidationException& e) {
        throw;
    }
}

void Service::updateProduct(int pos, const Product &product) {
    try {
        ProductValidator::validateStatic(product);
        repo.update(pos, product);
    }
    catch (const ValidationException& e) {
        throw;
    }
    catch (const std::runtime_error& e) {
        throw;
    }
}

std::vector<Product> Service::getAll() {
    return repo.get();
}

std::vector<Money> Service::buyProduct(int code, int money) {
    int price = -1;

    for (const auto& i : repo.get()) {
        if (i.getCode() == code) {
            price = i.getPrice();
            break;
        }
    }

    if (code < 0)
        throw std::runtime_error("product not found");


    if (money < price)
        throw std::runtime_error("insufficient funds");


    int change = money - price;
    std::vector<Money> result;
    std::vector<int> denoms = {100, 50, 10, 5, 1};
    int original_change = change;

    for (int d : denoms) {
        for (auto& m : stock) {
            if (m.val == d) {
                int canGive = std::min(change / d, m.freq);
                if (canGive > 0) {
                    result.push_back({d, canGive});
                    m.freq -= canGive;
                    change -= canGive * d;
                }
                break;
            }
        }
    }

    if (change > 0) {
        throw std::runtime_error("cannot provide exact change");
        // for (const auto& m : result) {
        //     for (auto& s : stock) {
        //         if (s.val == m.val) {
        //             s.freq += m.freq;
        //             break;
        //         }
        //     }
        // }
    }

    return result;
}
