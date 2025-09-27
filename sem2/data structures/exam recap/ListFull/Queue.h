//
// Created by Sonia Zagrean on 30.05.2025.
//

#pragma once
#include "sll/ListSLL.h"


template<typename TElem>
class Queue {
private:
    ListSLL<TElem> queue;

public:
    Queue() = default;
    ~Queue() = default;
    void enqueue(TElem elem) {
        queue.push_back(elem);
    }
    void dequeue() {
        if (empty())
            throw std::underflow_error("Queue is empty");
        queue.pop_front();
    }
    TElem top() {
        return queue.front();
    }
    bool empty() {
        return queue.isEmpty();
    }
};


