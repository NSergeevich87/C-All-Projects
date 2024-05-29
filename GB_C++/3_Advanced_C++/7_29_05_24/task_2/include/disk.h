#pragma once

#include <fstream>
#include <vector>

void save(const std::string& filename, const std::vector<int>& data);
std::vector<int> load(const std::string& filename);