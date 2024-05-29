#include "D:\C-All-Projects\GB_C++\3_Advanced_C++\7_29_05_24\task_2\include\gpu.h"
#include <iostream>
#include <vector>

void display(std::vector<int> memory) {
    for (int i = 0; i < 8; i++) {
        std::cout << memory[i] << " ";
    }
    std::cout << std::endl;
}