#include "D:\C-All-Projects\GB_C++\3_Advanced_C++\7_29_05_24\task_2\include\kbd.h"

#include <iostream>
#include <vector>

std::vector<int> input() {
    std::vector<int> temp;

    for (int i = 0; i < 8; ++i) {
        int value;
        std::cout << "Enter value " << i + 1 << ": ";
        std::cin >> value;
        temp.push_back(value);
    }

    return temp;
}