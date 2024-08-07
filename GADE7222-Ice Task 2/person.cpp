#include "person.h"
#include <iostream>
#include <iomanip>

Person::Person(std::string n, std::string s, int a, std::string i, double h, double w)
    : name(n), surname(s), age(a), id(i), height(h), weight(w), bmi(0.0) {}

void Person::calculateBMI() {
    double heightInMeters = height / 100.0;
    bmi = weight / (heightInMeters * heightInMeters);
}

std::string Person::getBMICategory() const {
    if (bmi < 18.5)
        return "Underweight";
    else if (bmi < 24.9)
        return "Normal";
    else if (bmi < 29.9)
        return "Overweight";
    else
        return "Obese";
}

void Person::printInfo() const {
    std::cout << "Name: " << name << "  "
              << "Surname: " << surname << "  "
              << "Age: " << age << "  "
              << "ID: " << id << "  "
              << "Height: " << height << "cm  "
              << "Weight: " << weight << "kg  "
              << "BMI: " << std::fixed << std::setprecision(1) << bmi << "  "
              << "Category: " << getBMICategory() << std::endl;
}
#include "Person.h"
