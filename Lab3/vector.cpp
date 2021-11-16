//
// Created by defur on 2021-09-28.
//

#include "vector.h"
#include <iostream>
#include <math.h>

double distanceBetweenVectors(double *vector1, double *vector2) {


    double total = 0;
    for (int i = 0; i < VECTOR_SIZE; i++)
        total += pow(( vector2[i] - vector1[i]), 2);

    return sqrt(total);
}

double findNearestVectorPair(double (*vectors)[10], int numberOfVectors, double *&vector1, double *&vector2) {
    double max = 0;
    for (int i = 0; i < numberOfVectors; i++) {
        for (int j = i; j < numberOfVectors; j++) {
            if (i == j)
                continue;
            double temp = distanceBetweenVectors(vectors[i], vectors[j]);
            if (max < temp) {
                max = temp;
                vector1 = vectors[i];
                vector2 = vectors[j];
            }
        }
    }
    return max;
}

string vectorToString(double *vector) {

    string out = std::string();
    for (int i = 0; i < VECTOR_SIZE; i++){
        out += std::to_string(vector[i]) += ", ";
    }
    return out;
}

