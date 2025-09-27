//
// Created by Sonia Zagrean on 29.05.2025.
//

#pragma once
#include <deque>
#include <vector>


template <typename TElem>
class QueueStl {
private:
    std::deque<TElem> queue;

public:
    QueueStl()=default;
    ~QueueStl()=default;

    void enqueue(TElem elem) {
        queue.push_back(elem);
    }
    TElem dequeue() {
        if (isEmpty())
            throw std::runtime_error("empty");
        TElem elem = queue.front();
        queue.pop_front();
        return elem;
    }
    TElem top() {
        return queue.front();
    }
    bool isEmpty() {
        return queue.size() == 0;
    }
};
