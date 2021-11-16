//
// Created by defur on 2021-11-07.
//

#ifndef LAB8_CONVERTCLASS_H
#define LAB8_CONVERTCLASS_H


class convertClass {
public:
    int initial, converted;
    virtual void compute() = 0;
    virtual int getInitial() {
        return initial;
    }
    virtual int getConverted() {
        return converted;
    }
};


#endif //LAB8_CONVERTCLASS_H
