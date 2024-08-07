#ifndef UTIL_H
#define UTIL_H

#include <chrono>
#include <vector>
#include "person.h"

class Util {
public:
    // Searching
    static int linearSearch(const std::vector<Person>& people, const std::string& id);
    static int binarySearch(const std::vector<Person>& people, const std::string& id);

    // Sorting
    static void bubbleSort(std::vector<Person>& people);
    static void insertionSort(std::vector<Person>& people);

    // Timing utility
    static void printDuration(const std::chrono::duration<double>& duration);
};

#endif // UTIL_H
