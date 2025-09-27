#include <iostream>
#include "MapBst.h"
#include "MapStl.h"

int main() {
    MapStl<std::string, int> map;

    map.insert("alice", 25);
    map.insert("bob", 30);
    map.insert("carol", 20);

    std::cout << "bob: " << map.get("bob") << std::endl;

    std::cout << "Contains 'carol'? " << (map.contains("carol") ? "Yes" : "No") << std::endl;
    std::cout << "Contains 'dave'? " << (map.contains("dave") ? "Yes" : "No") << std::endl;

    std::cout << "Removing 'bob'..." << std::endl;
    map.remove("bob");

    std::cout << "Contains 'bob'? " << (map.contains("bob") ? "Yes" : "No") << std::endl;

    return 0;
}
