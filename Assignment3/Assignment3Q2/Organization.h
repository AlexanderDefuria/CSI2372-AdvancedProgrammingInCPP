//
// Created by defur on 2021-10-25.
//

#ifndef ASSIGNMENT3_ORGANIZATION_H
#define ASSIGNMENT3_ORGANIZATION_H

#include <utility>
#include "Person.h"

class Organization {
private:
    std::string name = "default";
    Person* members = nullptr;
    int size = 0;
    int dim = 100;
public:
    std::string getMemberNames();
    void addPerson(Person person);
    virtual std::string getOrgName() { return name;};

    Organization() = default;
    Organization(std::string _name) {
        name = _name;
    }
    ~Organization() {
        delete[] members;
    }

    // Copy
    Organization(const Organization& obj)
    {
        members = new Person[obj.size];
        std::copy(obj.members, obj.members + size, members);
        size = obj.size;
        dim = obj.dim;
        name = obj.name;
    }


};



#endif //ASSIGNMENT3_ORGANIZATION_H
