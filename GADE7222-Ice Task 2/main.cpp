#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include "person.h"
#include "util.h"

void menu() {
    std::vector<Person> people;
    people.reserve(30);

    // Populate with sample data
    for (int i = 0; i < 30; ++i) {
        people.emplace_back("Name" + std::to_string(i), "Surname" + std::to_string(i), 20 + i, "ID" + std::to_string(1000 + i), 170.0 + i, 70.0 + i);
        people.back().calculateBMI();
    }

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Search\n";
        std::cout << "2. Sort\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter ID to search: ";
            std::string id;
            std::cin >> id;

            auto start = std::chrono::high_resolution_clock::now();
            int index = Util::linearSearch(people, id);
            auto end = std::chrono::high_resolution_clock::now();

            if (index != -1) {
                std::cout << "Person found:\n";
                people[index].printInfo();
            } else {
                std::cout << "Person not found\n";
            }

            auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
            std::cout << "Linear Search ";
            Util::printDuration(duration);

            std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) { return a.id < b.id; });

            start = std::chrono::high_resolution_clock::now();
            index = Util::binarySearch(people, id);
            end = std::chrono::high_resolution_clock::now();

            if (index != -1) {
                std::cout << "Person found:\n";
                people[index].printInfo();
            } else {
                std::cout << "Person not found\n";
            }

            duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
            std::cout << "Binary Search ";
            Util::printDuration(duration);

        } else if (choice == 2) {
            std::cout << "Choose sorting algorithm:\n";
            std::cout << "1. Bubble Sort\n";
            std::cout << "2. Insertion Sort\n";
            std::cout << "Enter your choice: ";
            int sortChoice;
            std::cin >> sortChoice;

            auto start = std::chrono::high_resolution_clock::now();

            if (sortChoice == 1) {
                Util::bubbleSort(people);
            } else if (sortChoice == 2) {
                Util::insertionSort(people);
            } else {
                std::cout << "Invalid choice\n";
                continue;
            }

            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
            std::cout << "Sorting ";
            Util::printDuration(duration);

            std::cout << "Sorted list:\n";
            for (const auto& person : people) {
                person.printInfo();
            }

        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid choice\n";
        }
    }
}

int main() {
    menu();
    return 0;
}
#include "Main.h"
