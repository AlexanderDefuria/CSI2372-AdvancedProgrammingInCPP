//
// Created by defur on 2021-10-25.
//

#ifndef ASSIGNMENT3_PERSON_H
#define ASSIGNMENT3_PERSON_H

class Person {
private:
    std::string name;
    int age;
public:

    int getAge() { return  age; };
    std::string getName() { return name; };
    Person(std::string _name, int _age) {
        name = _name;
        age = _age;
    };
    Person() {
        name = "Default";
        age = 0;
    };
    ~Person() {

    };
    Person(const Person& obj) {
        name = obj.name;
        age = obj.age;
    };

};

#endif //ASSIGNMENT3_PERSON_H
