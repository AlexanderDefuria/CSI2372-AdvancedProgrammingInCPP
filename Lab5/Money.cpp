//
// Created by defur on 2021-10-10.
//

#include "Money.h"

Money::Money(int dollars, int cents) {
    this->dollars = dollars;
    this->cents = cents;
}
int Money::getCents() {return cents;}
int Money::getDollars() {return cents;}
void Money::setDollars(int x) {dollars=x;}
void Money::setCents(int x) {cents=x;}
double Money::getMoney() {return dollars+(cents/100.0);}