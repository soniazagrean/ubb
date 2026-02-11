//
// Created by Sonia Zagrean on 03.05.2025.
//

#include "Service.h"

#include <utility>

Service::Service(Repository &repo) : products(repo) {
    stock = {{1, 10}, {5, 10}, {10, 10}, {50, 5}, {100, 2}};
}

void Service::add(int code, std::string name, double price) {
    products.addItem(Product(code, std::move(name), price));
}

void Service::remove(int code, std::string name, double price) {
    products.removeItem(Product(code, std::move(name), price));
}

void Service::update(int position, const Product &other) {
    products.update(position, other);
}

int Service::getSizeOf() {
    return products.getSize();
}

std::vector<Product> Service::get() {
    return products.getAll();
}

std::vector<Money> Service::buyProduct(int code, double input) {
    double price = -1;

    for (const auto& i : products.getAll()) {
        if (i.getCode() == code) {
            price = i.getPrice();
            break;
        }
    }

    if (price < 0) {
        std::cout << "product not found\n";
        return {};
    }

    if (input < price) {
        std::cout << "insufficient funds\n";
        return {};
    }

    int change = std::round((input - price) * 100);
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
        std::cout << "cannot provide exact change\n";
        for (const auto& m : result) {
            for (auto& s : stock) {
                if (s.val == m.val) {
                    s.freq += m.freq;
                    break;
                }
            }
        }
        return {};
    }

    return result;
}
