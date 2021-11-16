//
// Created by defur on 2021-10-27.
//

#include <iostream>
#include "Organization.h"

using namespace std;


std::string Organization::getMemberNames() {
    std::string out;

    for (int i=0; i < size; i++) {
        if (members[i].getName().empty() || members[i].getAge() == 0)
            continue;
        out.append(members[i].getName());
        out.append(", ");
    }

    return out;
}

void Organization::addPerson(Person person) {
    if (person.getName().empty() || person.getAge()==0)
        return;
    if (size >= dim) {
        return;
    }
    if (size==0) {
        members = new Person[1];
        members[0] = person;
        size++;
        return;
    }
    Person* temp = new Person[size+1];
    std::copy(members, members + std::min(size, size+1), temp);
    delete[] members;
    members = new Person[size+1];
    std::copy(temp, temp + size, members);
    members[size] = person;
    size++;
    delete [] temp;
}
