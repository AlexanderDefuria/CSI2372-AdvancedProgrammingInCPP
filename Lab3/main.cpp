#include <iostream>
#include "vector.h"

int main() {
    double a[5][VECTOR_SIZE] = {
            { 0.595500, 0.652927, 0.606763, 0.162761, 0.980752, 0.964772, 0.319322, 0.611325, 0.012422, 0.393489 },
            { 0.416132, 0.778858, 0.909609, 0.094812, 0.380586, 0.512309, 0.638184, 0.753504, 0.465674, 0.674607 },
            { 0.183963, 0.933146, 0.476773, 0.086125, 0.566566, 0.728107, 0.837345, 0.885175, 0.600559, 0.142238 },
            { 0.086523, 0.025236, 0.252289, 0.089437, 0.382081, 0.420934, 0.038498, 0.626125, 0.468158, 0.247754 },
            { 0.969345, 0.127753, 0.736213, 0.264992, 0.518971, 0.216767, 0.390992, 0.242241, 0.516135, 0.990155 }
    };

    double* out_a{ &a[0][0] };
    double* out_b{ &a[0][0] };

    std::cout << "Testing distanceBetweenVectors with index 0 and 1." << std::endl;
    std::cout << vectorToString(a[0]) << std::endl;
    std::cout << vectorToString(a[1]) << std::endl;
    std::cout << distanceBetweenVectors(a[0], a[1]) << std::endl << std::endl;


    std::cout << "Testing findNearestVectorPair." << std::endl;
    std::cout << "Nearest pair of vectors is: ";
    std::cout << findNearestVectorPair(a, sizeof(a)/(sizeof(double)*VECTOR_SIZE), out_a, out_b) << std::endl;

    std::cout << "Vector Pointers Passed to findNearestVectorPair:" << std::endl << vectorToString(out_a) << std::endl;
    std::cout << vectorToString(out_b) << std::endl;

    return 0;
}
