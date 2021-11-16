//
// Created by defur on 2021-10-10.
//

#include "activity.h"


CourseActivity::CourseActivity(const StartTime* _start, double _duration, const std::string _location) {
    d_start = (StartTime*)_start;
    location = _location;
    duration = _duration;
}

void CourseActivity::reschedule(StartTime *_newStart) {
    d_start = _newStart;
}

void CourseActivity::print() const {
    std::cout<<std::endl << "Location:   " << location <<std::endl;
    std::cout << "Duration:   " << duration <<std::endl;
    std::cout << "Start Time: ";
    d_start->print();
}


Lecture::Lecture(const StartTime *start, double duration, std::string location, const std::string& _topic) : CourseActivity(start, duration, location) {
    topic = _topic;
}

Lecture::Lecture(const CourseActivity& _oActivity, const std::string& _topic) : CourseActivity(_oActivity) {
    topic = _topic;
}

void Lecture::print() const {
    CourseActivity::print();
    std::cout << "Topic:      " << topic <<std::endl;
}

Laboratory::Laboratory(const StartTime &_start, double _duration, const std::string _location,const std::string &_assignment) : CourseActivity(&_start, _duration, _location) {
    assignment = _assignment;
}

void Laboratory::print() const {
    CourseActivity::print();
    std::cout << "Assignment: " << assignment <<std::endl;
}

Tutorial::Tutorial(const StartTime &_start, double _duration, const std::string _location, const std::string &_exercise) : CourseActivity(&_start, _duration, _location) {
    exercise = _exercise;
}

void Tutorial::print() const {
    CourseActivity::print();
    std::cout << "Exercise:   " << exercise <<std::endl;
}
