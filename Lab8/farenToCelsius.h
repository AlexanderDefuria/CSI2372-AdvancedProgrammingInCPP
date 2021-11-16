//
// Created by defur on 2021-11-07.
//

#ifndef LAB8_FARENTOCELSIUS_H
#define LAB8_FARENTOCELSIUS_H

#include "convertClass.h"

class farenToCelsius : public convertClass {
public:
    farenToCelsius(int x) {initial = x;}
    void compute() override {
        converted = (initial - 32) * (5.0/9.0);
    }
};


#endif //LAB8_FARENTOCELSIUS_H
