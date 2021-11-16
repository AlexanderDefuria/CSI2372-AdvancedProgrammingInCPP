//
// Created by defur on 2021-10-10.
//

#ifndef LAB5_ACTIVITY_H
#define LAB5_ACTIVITY_H

#include "StartTime.h"

class CourseActivity {
private:
    StartTime* d_start;
    double duration;
    std::string location;
public:
    CourseActivity(const StartTime* _start, double _duration, std::string  _location);
    void reschedule ( StartTime* _newStart);
    void print() const;
};

class Lecture : public CourseActivity {
    std::string topic;
public:
    Lecture(const StartTime *start, double duration, std::string location, const std::string& _topic);
    Lecture(const  CourseActivity& _oActivity, const std::string& _topic);
    void print() const;
};

class Laboratory : public CourseActivity {
    std::string assignment;
public:
    Laboratory( const StartTime& _start, double _duration, const std::string _location, const std::string& _assignment );
    void print() const;
};

class Tutorial : public CourseActivity {
    std::string exercise;
public:
    Tutorial( const StartTime& _start, double _duration, const std::string _location, const std::string& _exercise );
    void print() const;
};

#endif //LAB5_ACTIVITY_H
