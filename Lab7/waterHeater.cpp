//
// Created by defur on 2021-11-01.
//

#include <iostream>
#include "waterHeater.h"


void waterHeater::display() {

    std::cout << "Price: " << price << "$" << std::endl;
    std::cout << "Energy Source: " << (bool(energySource) ? "ELECTRICAL" : "GAS") << std::endl;
    std::cout << "Max GPM: " << maxGPM << std::endl;
    std::cout << "Energy Factor: " << energyFactor << std::endl;
    std::cout << "Energy Star: " << (energyStar ? "Yes" : "No" ) << std::endl;
}

float waterHeater::getPrice() const {
    return this->price;
}

waterHeater::waterHeater(float _price, FUEL _energySource, float _maxGPM, float _energyFactor, bool _energyStar) {
    price = _price;
    energySource = _energySource;
    maxGPM = _maxGPM;
    energyFactor = _energyFactor;
    energyStar = _energyStar;
}


waterHeaterWithTank *waterHeaterWithTank::clone() {
    return new waterHeaterWithTank(*this);
}

float waterHeaterWithTank::priceOfInstallation(bool _wiring, bool _vent) {
    return price*2.0f + (_wiring ? 1000.0f : 0) + (_vent ? 500.0f : 0);
}

waterHeaterWithoutTank *waterHeaterWithoutTank::clone() {
    return new waterHeaterWithoutTank(*this);
}

float waterHeaterWithoutTank::priceOfInstallation(bool _wiring, bool _vent) {
    return price*1.5f + (_wiring ? 500.0f : 0) + (_vent ? 300.0f : 0);
}
