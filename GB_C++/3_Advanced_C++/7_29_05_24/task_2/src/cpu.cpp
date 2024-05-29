#include "D:\C-All-Projects\GB_C++\3_Advanced_C++\7_29_05_24\task_2\include\cpu.h"
#include <iostream>

void compute(std::vector<int> memory) {
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        sum += memory[i];
    }
    std::cout << sum << std::endl;
}