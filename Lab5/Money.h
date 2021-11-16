//
// Created by defur on 2021-10-10.
//

#ifndef LAB5_MONEY_H
#define LAB5_MONEY_H

class Money {
private:
    int dollars = 0;
    int cents = 0;
public:
    Money() = default;
    Money(int dollars, int cents);
    int getDollars();
    int getCents();
    void setDollars(int x);
    void setCents(int x);
    double getMoney();
};

#endif //LAB5_MONEY_H
