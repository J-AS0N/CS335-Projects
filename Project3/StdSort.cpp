#include "StdSort.hpp"

void stdSort(const std::string &header, std::vector<int> data) {
    // const auto t1_start = std::chrono::steady_clock::now();

    std::cout << header << std::endl;
    std::sort(data.begin(), data.end());

    // for (int i = 0; i < data.size(); i++) {
    //     std::cout << data[i] << " ";
    // }

    // outputs
    std::cout << "Min: " << findMin(data) << std::endl;
    std::cout << "P25: " << Q1(data) << std::endl;
    std::cout << "P50: " << findMedian(data) << std::endl;
    std::cout << "P75: " << Q3(data) << std::endl;
    std::cout << "Max: " << findMax(data) << std::endl;

    // const auto t1_end = std::chrono::steady_clock::now();
    // int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
    // std::cout << "\n" << t1 << " microseconds." << std::endl;

}

// Helper Functions

int findMin(std::vector<int> nums) {  // finds the minimum value
    int min_value = *std::min_element(nums.begin(), nums.end());
    return min_value;
}


int findMax(std::vector<int> nums) {  // finds the maximum value
    int max_value = *std::max_element(nums.begin(), nums.end());
    return max_value;
}

int Q1(std::vector<int> nums) {
    int size = nums.size();  // size of the vector

    // if the size is EVEN
    if (size % 2 == 0) {
        return nums[size / 4 - 1];
    } else {
        // if the size is ODD
        return nums[size / 4];
    }
}

int findMedian(std::vector<int> nums) {
    int size = nums.size();  // size of the vector

    // if the size is EVEN
    if (size % 2 == 0) {
        // Average of the two medians
        int middle1 = nums[size / 2 - 1];
        int middle2 = nums[size / 2]; 
        int middle = (middle1 + middle2) / 2;
        return middle;

    } else {
        // if the size is ODD
        return nums[size / 2];
    }
}

int Q3(std::vector<int> nums) {
    int size = nums.size();

    // if the size is EVEN
    if (size % 2 == 0) {
        return nums[size * 3 / 4 - 1];
    } else {
        return nums[size * 3 / 4];
    }
}