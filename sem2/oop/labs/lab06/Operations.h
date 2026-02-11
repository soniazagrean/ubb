//
// Created by Sonia Zagrean on 01.04.2025.
//

#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "ComplexNumber.h"
#include <queue>

using Comparator = bool (*)(const ComplexNumber&, const ComplexNumber&);

ComplexNumber greatestComplexNumber(std::priority_queue<ComplexNumber, std::vector<ComplexNumber>, Comparator>& pq);
void insideDial1(std::priority_queue<ComplexNumber, std::vector<ComplexNumber>, Comparator> pq);
int longestSeq(std::priority_queue<ComplexNumber, std::vector<ComplexNumber>, Comparator> pq);

#endif //OPERATIONS_H
