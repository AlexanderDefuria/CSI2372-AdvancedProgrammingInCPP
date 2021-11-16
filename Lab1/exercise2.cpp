#include <iostream>
#include <math.h>

int main() {
    int number(0);

    while (true) {
        std::cout << "Give a positive number: ";
        std::cin >> number;
        if (number < 0) {
            std::cout << "Positive Please." << std::endl;
            continue;
        } else if (number == 0)
            return 0;
        else {
            std::cout << "Its square root is: " << sqrt(number) <<std::endl;
        }
    }


}