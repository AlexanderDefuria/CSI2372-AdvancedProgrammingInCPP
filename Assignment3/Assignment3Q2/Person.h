//
// Created by defur on 2021-10-25.
//

#ifndef ASSIGNMENT3_PERSON_H
#define ASSIGNMENT3_PERSON_H

#include <iostream>
#include <utility>

using namespace std;

class Organization;

class Person {
private:
    std::string name;
    int age;
    Organization** organizations;
    int size;
public:
    int getAge() { return age; };
    int getSize() { return size; };
    std::string getOrgNames();
    std::string getName() { return name; };
    std::string printSchools();
    float getTotalTuition();
    void addOrganization(Organization* organization);
    Person(std::string _name) {
        organizations = new Organization*[5];
        name = std::move(_name);
        age = 0;
    };
    Person() {
        organizations = new Organization*[5];
        name = "";
        age = 0;
    };
    ~Person() {
        delete[] organizations;
    };

    Person(const Person& obj) {
        organizations = new Organization*[5];
        std::copy(obj.organizations, obj.organizations + 5, organizations);
        size = obj.size;
        age = obj.age;
        name = obj.name;
    }

};



#endif //ASSIGNMENT3_PERSON_H
