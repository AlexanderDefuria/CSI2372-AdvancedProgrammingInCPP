//
// Created by defur on 2021-10-27.
//

#include "Person.h"
#include "Organization.h"
#include "University.h"
#include <iostream>

using namespace std;

std::string Person::getOrgNames() {
    std::string out;
    for (int i =0; i < size; i++) {
        out.append(organizations[i]->getOrgName());
        out.append(", ");
    }
    return out;
}

void Person::addOrganization(Organization* organization) {
    organizations[size] = organization;
    size++;
}

std::string Person::printSchools() {
    std::string out;
    for (int i =0; i <size; i++) {
        if (auto* derived = dynamic_cast<University*>(organizations[i])){
            out.append(derived->getOrgName());
            out.append(", ");
            out.append(std::to_string((int)derived->getTuition()));
            out.append("; ");
        }

    }
    return out;
}

float Person::getTotalTuition() {
    float out = 0;
    for (int i = 0; i <size; i++) {
        if (auto* derived = dynamic_cast<University*>(organizations[i]))
            out += derived->getTuition();
    }
    return out;
}