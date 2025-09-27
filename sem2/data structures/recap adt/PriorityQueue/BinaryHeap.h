//
// Created by Sonia Zagrean on 01.06.2025.
//

#ifndef STL_H
#define STL_H
#include <vector>
/*

| Node at index i | Children      |
| --------------- | ------------- |
| left            | `2*i + 1`     |
| right           | `2*i + 2`     |
| parent          | `(i - 1) / 2` |

 */
template<typename T>
class BinaryHeap {
private:
    std::vector<T> data;

    void bubbleUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (data[index] >= data[parent])
                break;
            std::swap(data[index], data[parent]);
            index = parent;
        }
    }

    void bubbleDown(int index) {
        int size = data.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && data[left] < data[largest])
                largest = left;
            if (right < size && data[right] < data[largest])
                largest = right;

            if (largest == index)
                break;

            std::swap(data[index], data[largest]);
            index = largest;
        }
    }

public:
    BinaryHeap() = default;
    ~BinaryHeap() = default;

    void push(const T& elem) {
        data.push_back(elem);
        bubbleUp(data.size() - 1);
    }

    void pop() {
        if (empty())
            throw std::runtime_error("Heap is empty");

        data[0] = data.back();
        data.pop_back();
        if (!empty())
            bubbleDown(0);
    }

    T top() {
        if (empty())
            throw std::runtime_error("Heap is empty");
        return data[0];
    }

    bool empty() {
        return data.empty();
    }

    int size() {
        return data.size();
    }
};


#endif //STL_H
