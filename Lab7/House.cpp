//
// Created by defur on 2021-11-01.
//

#include <iostream>
#include "House.h"

House::House() {

}

void House::install(waterHeater *const _waterHeater, bool wiring, bool _vent) {
    if (heater != nullptr)
        removeWaterHeater();

    heater = _waterHeater;


    // Display installation price;
    std::cout << "Installation Price : " << heater->priceOfInstallation(wiring, _vent) << "$" << std::endl;
}

waterHeater *House::removeWaterHeater() {
    delete heater;
    return nullptr;
}

void House::showWaterHeater() const {
    if (heater != nullptr)
        heater->display();
}

House *House::clone() {
    return new House(*this);
}

House::~House() {
    delete heater;
}


