#include <iostream>
#include "activity.h"
#include "StartTime.h"
#include "Money.h"

/*
int main() {
    Money *x = new Money(1,1);
    Money *y = new Money();
    x->setCents(0);
    x->setDollars(45);
    std::cout << x->getMoney() <<std::endl;
    std::cout << y->getMoney() <<std::endl;
    return 0;
}
 */

int main() {
    const StartTime a( 11,30);
    const StartTime b( 13,00);
    const StartTime c( 16,00);

    Lecture lecA(&a, 90, "Hall 1", "Topic A");
    Laboratory lab(b, 90, "Hall 2", "A1");
    Tutorial tut(c, 90, "Hall 3", "Exercise 1");

    Lecture lecB(lab, "Topic B");
    Lecture lecC(tut, "Topic C");

    lecA.print();
    lecB.print();
    lecC.print();
    lab.print();
    tut.print();

    lecB.reschedule(new StartTime(19,0));
    lecC.reschedule(new StartTime(7,0));

    lecB.print();
    lecC.print();
}

