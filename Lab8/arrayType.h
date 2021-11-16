//
// Created by defur on 2021-11-07.
//

#ifndef LAB8_ARRAYTYPE_H
#define LAB8_ARRAYTYPE_H

template <typename T, int S>
class arrayType{
private:
    T array[S];
public:
    arrayType(){}
    ~arrayType() {}

    T& operator[] (const int index) {
        return array[index - 1];
    }
};
#endif //LAB8_ARRAYTYPE_H
