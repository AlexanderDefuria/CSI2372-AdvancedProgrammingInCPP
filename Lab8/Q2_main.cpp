#include <iostream>

template <typename T>
void swapArgs(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
template <>
void swapArgs(int &a, int &b) {
    std::cout << "The inputs are of type int." << std::endl;
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    std::string x = "x";
    std::string y = "y";
    int w = 123;
    int z = 456;

    std::cout << x << " " << y <<std::endl;
    swapArgs(x,y);
    std::cout << x << " " << y <<std::endl;

    std::cout << w << " " << z <<std::endl;
    swapArgs(w,z);
    std::cout << w << " " << z <<std::endl;


    return  0;
}

