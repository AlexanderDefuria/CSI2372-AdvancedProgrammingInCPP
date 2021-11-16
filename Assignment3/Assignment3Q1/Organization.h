//
// Created by defur on 2021-10-25.
//

#ifndef ASSIGNMENT3_ORGANIZATION_H
#define ASSIGNMENT3_ORGANIZATION_H

#include <utility>

class Organization {
private:
    std::string name = "default";
    Person* members = nullptr;
    int size = 0;
    int dim = 100;
public:
    std::string getMemberNames();
    void addPerson(Person person);

    Organization() = default;
    Organization(std::string _name) {

    }
    ~Organization() {
        delete[] members;
    }

    // Copy
    Organization(const Organization& obj)
    {
        members = new Person[obj.size];
        for (int i = 0; i < obj.size; i++)
            members[i] = obj.members[i];
        size = obj.size;
        dim = obj.dim;
        name = obj.name;
    }


};

std::string Organization::getMemberNames() {
    std::string out;

    for (int i=0; i < size; i++) {
        if (members[i].getName().empty() && members[i].getAge() == 0)
            continue;
        out.append(members[i].getName());
        out.append(", ");
    }

    return out;
}

void Organization::addPerson(Person person) {
    if (person.getName().empty() && person.getAge()==0)
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


#endif //ASSIGNMENT3_ORGANIZATION_H
