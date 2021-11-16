//
// Created by defur on 2021-11-01.
//

#ifndef LAB7_WATERHEATER_H
#define LAB7_WATERHEATER_H


enum FUEL { GAS, ELECTRICAL };

class waterHeater {
protected:
    float price;
    FUEL energySource;
    float maxGPM;
    float energyFactor;
    bool energyStar;
public:
    waterHeater(float _price, FUEL _energySource, float _maxGPM, float _energyFactor, bool _energyStar);
    float getPrice() const;
    void display();
    virtual waterHeater* clone() = 0; // Completely separate clone;
    virtual float priceOfInstallation( bool _wiring, bool _vent) = 0;
};

class waterHeaterWithTank : public waterHeater {
public:
    waterHeaterWithTank(float _price, FUEL _energySource, float _maxGPM, float _energyFactor, bool _energyStar=true) : waterHeater(_price, _energySource, _maxGPM, _energyFactor, _energyStar) {}
    waterHeaterWithTank* clone();
    float priceOfInstallation(bool _wiring, bool _vent) override;
};


class waterHeaterWithoutTank : public waterHeater {
public:
    waterHeaterWithoutTank(float _price, FUEL _energySource, float _maxGPM, float _energyFactor, bool _energyStar=false) : waterHeater(_price, _energySource, _maxGPM, _energyFactor, _energyStar) {

    }
    waterHeaterWithoutTank* clone();
    float priceOfInstallation(bool _wiring, bool _vent) override;
};

#endif //LAB7_WATERHEATER_H
