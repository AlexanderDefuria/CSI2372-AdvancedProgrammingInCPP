#include <iostream>
#include "predictor.h"

int main() {
    int age;
    char sexS;

    std::cout << "Enter an age followed by a sex(M/F) ie '39F'. " << std::endl;
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Sex: ";
    std::cin >> sexS;

    std::cout << std::endl<< simulate(age, sexS=='M');


    return 0;
}
