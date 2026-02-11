#include "Operations.h"
#include <queue>
#include <iostream>

ComplexNumber greatestComplexNumber(std::priority_queue<ComplexNumber, std::vector<ComplexNumber>, Comparator>& pq) {
    return pq.top();
}

void insideDial1(std::priority_queue<ComplexNumber, std::vector<ComplexNumber>, Comparator> pq) {
    std::priority_queue<ComplexNumber, std::vector<ComplexNumber>, Comparator> pqc = pq;
    while (!pqc.empty()) {
        ComplexNumber cn = pqc.top();
        if (cn.absoluteValue() < 1 && cn.getReal() > 0 && cn.getImag() > 0) {
            std::cout << cn << '\n';
        }
        pqc.pop();
    }
}

int longestSeq(std::priority_queue<ComplexNumber, std::vector<ComplexNumber>, Comparator> pq) {
    if (pq.empty()) {
        return 0;
    }

    std::priority_queue<ComplexNumber, std::vector<ComplexNumber>, Comparator> pqc = pq;
    ComplexNumber prev = pqc.top();
    pqc.pop();

    int len = 1, maxLen = 1;
    while (!pqc.empty()) {
        ComplexNumber curr = pqc.top();
        pqc.pop();

        if (curr.getReal() == prev.getReal() && curr.getImag() == prev.getImag())
            len++;
        else {
            maxLen = std::max(maxLen, len);
            len = 1;
        }

        prev = curr;
    }

    maxLen = std::max(maxLen, len);

    return maxLen;
}
