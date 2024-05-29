#include "D:\C-All-Projects\GB_C++\3_Advanced_C++\7_29_05_24\task_2\include\ram.h"
#include <iostream>
#include <vector>

void write(std::vector<int> value) {
    for (int i = 0; i < value.size(); ++i) {
        buffer.push_back(value[i]);
    }
}

std::vector<int> read() {
    return buffer;
}