//
// Created by defur on 2021-09-30.
//
#include <iostream>
#include <fstream>
#include "predictor.h"

int simulate(int age, bool male) {
    int a[MAX_AGE];
    load(a, male);
    srand( (unsigned)time(NULL));
    int i = age;
    while (i < MAX_AGE) {
        if (a[i] > rand()%(1000001))
            return  i;
        i++;
    }
    return i;

}

void load(int * dest, bool male) {
    int currentAge = 0;
    std::ifstream inFile;
    std::string line;

    inFile.open("../LifeDeathProbability.txt");
    if (!inFile.is_open()) {
        return ;
    }

    // male, female
    int column = male ? 0 : 1;
    int val;

    for (int i = 0; inFile; i++) {
        std::getline(inFile, line, '.');
        if ((i % 2)==column || i == 0)
            continue;
        val = std::stoi(line);
        //std::cout << val <<std::endl;
        dest[currentAge] = val;
        currentAge++;

    }

    inFile.close();
}
