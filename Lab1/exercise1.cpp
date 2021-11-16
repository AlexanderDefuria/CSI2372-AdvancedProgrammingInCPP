#include <iostream>
#include <cctype>

int main() {
    // char is 11 as including the negative an integer can have 11 digits.
    char line[11];
    int negatives(0);

    std::cout << "Enter a series of integers. Enter a letter to stop." << std::endl;

    do {
        std::cin.getline(line, 11);
        if (line[0] == '-')
            negatives++;
    }
    while( isdigit(line[0]) || isdigit(line[1]) ) ;


    std::cout << "You entered " << negatives << " negative numbers." << std::endl;

    return 0;
}
