//
// Created by Sonia Zagrean on 01.06.2025.
//

#ifndef MAPSTL_H
#define MAPSTL_H
#include <vector>

template <typename K, typename V>
class MapStl {
private:
    std::vector<std::pair<K, V>> map;
public:
    void insert(const K& key, const V& value) {
        map.push_back({key, value});
    }
    void remove(const K& key) {
        for (auto it = map.begin(); it != map.end(); ++it)
            if (it->first == key) {
                map.erase(it);
                return;
            }
    }
    V get(const K& key) {
        if (empty())
            throw std::runtime_error("empty");
        for (auto& i : map)
            if (i.first == key)
                return i.second;
        return -1;
    }
    bool contains(const K& key) {
        if (empty())
            throw std::runtime_error("empty");
        for (auto& i : map)
            if (i.first == key)
                return true;
        return false;
    }
    bool empty() {
        return map.size() == 0;
    }
    int size() {
        return map.size();
    }
};



#endif //MAPSTL_H
