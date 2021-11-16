#include <iostream>
#include "House.h"
#include "waterHeater.h"

int main() {
    auto* a = new waterHeaterWithoutTank(1000.0f, ELECTRICAL, 8.0f, 0.55f);
    auto* firstHouse = new House();
    auto* secondHouse = firstHouse->clone();

    std::cout << "waterHeater installed in the first house." <<std::endl;
    firstHouse->install(a, true, true);

    std::cout << std::endl;
    std::cout << "waterHeater installed in the second house." << std::endl;
    secondHouse->removeWaterHeater();
    auto* b = new waterHeaterWithTank(2000.0f, GAS, 12.0f, 0.93f);
    secondHouse->install(b, false, true);
    std::cout << std::endl;

    std::cout << "Information about waterHeater in the firsat house." << std::endl;
    firstHouse->showWaterHeater();
    std::cout << std::endl;
    std::cout << "Information about waterHeater in the second house." << std::endl;
    secondHouse->showWaterHeater();
    std::cout << std::endl;

    delete firstHouse;
    delete secondHouse;



}
