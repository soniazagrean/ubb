#pragma once
#include <map>
#include <set>
#include <stdexcept>

template <typename K, typename V>
class Map {
private:
    std::map<K, V> map;

public:
    Map() {}

    void put(const K& key, const V& value) {
        map[key] = value;
    }

    V get(const K& key) const {
        if (!has_key(key))
            throw std::runtime_error("key does not exist");
        return map.at(key);
    }

    bool has_key(const K& key) const {
        return map.find(key) != map.end();
    }

    std::set<K> get_keys() const {
        std::set<K> keys;
        for (const auto& pair : map)
            keys.insert(pair.first);
        return keys;
    }
};
