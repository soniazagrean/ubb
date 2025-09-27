#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename TElem>
class Bag {
private:
    std::vector<TElem> heap;

public:
    Bag() = default;
    
    Bag(const Bag& other) : heap(other.heap) {}
    
    Bag& operator=(const Bag& other) {
        if (this != &other) {
            heap = other.heap;
        }
        return *this;
    }
    
    ~Bag() = default;
    
    void add(TElem elem) {
        heap.push_back(elem);
        std::push_heap(heap.begin(), heap.end());
    }
    
    bool remove(TElem elem) {
        auto it = std::find(heap.begin(), heap.end(), elem);
        if (it == heap.end()) return false;

        std::iter_swap(it, heap.end() - 1);
        heap.pop_back();
        std::make_heap(heap.begin(), heap.end());
        return true;
    }
    
    bool search(TElem elem) const {
        return std::find(heap.begin(), heap.end(), elem) != heap.end();
    }
    
    int size() const {
        return heap.size();
    }
    
    int nrOccurrences(TElem elem) const {
        return std::count(heap.begin(), heap.end(), elem);
    }
    
    TElem getAt(int position) const {
        if (position < 0 || position >= heap.size())
            throw std::runtime_error("invalid position");
        return heap[position];
    }
    
    void printCollection() const {
        std::vector<TElem> seen;
        for (const auto& elem : heap) {
            if (std::find(seen.begin(), seen.end(), elem) == seen.end()) {
                std::cout << elem << " x " << nrOccurrences(elem) << '\n';
                seen.push_back(elem);
            }
        }
    }
};

