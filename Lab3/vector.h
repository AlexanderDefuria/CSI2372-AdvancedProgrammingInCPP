#include <string>
using namespace std;

#ifndef VECTOR_H
#define VECTOR_H

// The default size - or number of dimensions - of a vector.
#define VECTOR_SIZE 10

// Functions are described in the implementation. See comment headers.

double distanceBetweenVectors(double vector1[], double vector2[]);
double findNearestVectorPair(double vectors[][VECTOR_SIZE], int numberOfVectors, double *&vector1, double *&vector2);
string vectorToString(double vector[]);

#endif
