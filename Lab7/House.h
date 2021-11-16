//
// Created by defur on 2021-11-01.
//

#ifndef LAB7_HOUSE_H
#define LAB7_HOUSE_H

#include "waterHeater.h"

class House {
private:
    waterHeater* heater = nullptr;
public:
    House();
    House* clone();
    ~House();

    void install (waterHeater * const _waterHeater, bool wiring, bool _vent ) ;
    waterHeater* removeWaterHeater ();
    void showWaterHeater () const;
};


#endif //LAB7_HOUSE_H
