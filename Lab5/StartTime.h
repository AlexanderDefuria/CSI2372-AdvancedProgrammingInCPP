//
// Created by defur on 2021-10-10.
//

#ifndef LAB5_STARTTIME_H
#define LAB5_STARTTIME_H

#include <iostream>

class StartTime {
private:
    char d_hour;
    char d_minutes;
public:
    inline void get(char& _hour, char& _minutes) const;
    inline void set(char _hour, char _minutes);
    inline StartTime(char _hour, char _minutes);
    inline void print() const;
};

void StartTime::print() const {
    std::cout << (int)d_hour << ":" << (int)d_minutes << std::endl;
}

void StartTime::get(char &_hour, char &_minutes) const {
    _hour = d_hour;
    _minutes = d_minutes;
}

void StartTime::set(char _hour, char _minutes) {
    d_hour = _hour;
    d_minutes = _minutes;
}

StartTime::StartTime(char _hour, char _minutes) {
    d_hour = _hour;
    d_minutes = _minutes;
}


#endif //LAB5_STARTTIME_H
