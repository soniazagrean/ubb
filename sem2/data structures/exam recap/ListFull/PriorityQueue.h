//
// Created by Sonia Zagrean on 30.05.2025.
//

#pragma once
#include "sll/ListSLL.h"

template<typename TElem>
using Relation = bool (*)(TElem, TElem);

template<typename TElem>
class PriorityQueue {
private:
    ListSLL<TElem> pq;
    Relation<TElem> r;


public:
    explicit PriorityQueue(Relation<TElem> r): r(r) {}
    ~PriorityQueue()=default;

    void enqueue(TElem elem) {
        if (pq.isEmpty()) {
            pq.push_front(elem);
            return;
        }
        if (r(elem, pq.getAt(0))) {
            pq.push_front(elem);
            return;
        }

        int i = 0;
        while (i < pq.size() && !r(elem, pq.getAt(i))) {
            i++;
        }

        if (i == pq.size())
            pq.push_back(elem);
        else
            pq.insertIndex(i, elem);

    }
    TElem dequeue() {
        if (pq.isEmpty())
            throw std::underflow_error("PriorityQueue is empty");
        return pq.pop_front();
    }
    TElem top() {
        if (pq.isEmpty())
            throw std::underflow_error("PriorityQueue is empty");
        return pq.getAt(0);
    }
    bool empty() {
        return pq.isEmpty();
    }
};


