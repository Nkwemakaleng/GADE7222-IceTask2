#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    std::string name;
    std::string surname;
    int age;
    std::string id;
    double height; // in cm
    double weight; // in kg
    double bmi;

    Person(std::string n, std::string s, int a, std::string i, double h, double w);
    void calculateBMI();
    std::string getBMICategory() const;
    void printInfo() const;
};

#endif // PERSON_H

