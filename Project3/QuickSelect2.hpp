#include <iostream>
#include <vector>

void quickSelect2(const std::string &header, std::vector<int> data);
int partition(std::vector<int> &nums, int left, int right);
void quickSelect(std::vector<int> &nums, int left, int right, std::vector<int> keys);