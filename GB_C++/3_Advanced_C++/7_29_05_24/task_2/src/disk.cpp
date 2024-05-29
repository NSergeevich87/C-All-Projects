#include "D:\C-All-Projects\GB_C++\3_Advanced_C++\7_29_05_24\task_2\include\disk.h"
#include <iostream>
#include <fstream>
#include <vector>

void save(const std::string& filename, const std::vector<int>& data) {
    // Перезаписываем файл
    std::ofstream file(filename);
    file.clear();
    for (int value : data) {
        file << value << std::endl;
    }
    file.close();
}

std::vector<int> load(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> data;
    int value;
    while (file >> value) {
        data.push_back(value);
    }
    file.close();
    return data;
}