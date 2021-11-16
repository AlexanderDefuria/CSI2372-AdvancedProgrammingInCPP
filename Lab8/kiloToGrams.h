//
// Created by defur on 2021-11-07.
//

#ifndef LAB8_KILOTOGRAMS_H
#define LAB8_KILOTOGRAMS_H

#include "convertClass.h"

class kiloToGrams : public convertClass {
public:
    kiloToGrams(int x) {initial = x;}
    void compute() override {
        converted = initial * 1000;
    };
};


#endif //LAB8_KILOTOGRAMS_H
