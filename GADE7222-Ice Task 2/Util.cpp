#include "util.h"
#include <algorithm>
#include <chrono>
#include <iostream>

// Linear Search
int Util::linearSearch(const std::vector<Person>& people, const std::string& id) {
    for (size_t i = 0; i < people.size(); ++i) {
        if (people[i].id == id) {
            return i;
        }
    }
    return -1; // Not found
}

// Binary Search
int Util::binarySearch(const std::vector<Person>& people, const std::string& id) {
    int left = 0, right = people.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (people[mid].id == id) {
            return mid;
        }
        if (people[mid].id < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}

// Bubble Sort
void Util::bubbleSort(std::vector<Person>& people) {
    for (size_t i = 0; i < people.size(); ++i) {
        for (size_t j = 0; j < people.size() - 1; ++j) {
            if (people[j].id > people[j + 1].id) {
                std::swap(people[j], people[j + 1]);
            }
        }
    }
}

// Insertion Sort
void Util::insertionSort(std::vector<Person>& people) {
    for (size_t i = 1; i < people.size(); ++i) {
        Person key = people[i];
        int j = i - 1;
        while (j >= 0 && people[j].id > key.id) {
            people[j + 1] = people[j];
            j = j - 1;
        }
        people[j + 1] = key;
    }
}

void Util::printDuration(const std::chrono::duration<double>& duration) {
    std::cout << "Duration: " << duration.count() << " seconds" << std::endl;
}
