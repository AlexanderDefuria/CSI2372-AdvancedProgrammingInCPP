//
// Created by defur on 2021-10-25.
//

#ifndef ASSIGNMENT3_UNIVERSITY_H
#define ASSIGNMENT3_UNIVERSITY_H

class University : public Organization{
private:
    float tuition;
public:
    using Organization::Organization;
    void setTuition(float x) {tuition=x;};
    float getTuition() { return tuition; };
    virtual ~University() {

    }
};

#endif //ASSIGNMENT3_UNIVERSITY_H
