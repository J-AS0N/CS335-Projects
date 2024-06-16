#include "QuickSelect1.hpp"

void quickSelect1(const std::string &header, std::vector<int> data) {
    // const auto t1_start = std::chrono::steady_clock::now();

    int size = data.size();  // size of the data

    // find the median
    int median = quickSelect(data, 0, size - 1, size / 2 + 1);

    // find Q1
    int Q1 = quickSelect(data, 0, size - 1, size / 4);

    // find Q3
    int Q3 = quickSelect(data, 0, size - 1, (3 * size) / 4);

    // finding the min before the 25% mark
    int min = data[0];  // set the min to the first element in the vector
    for (int i = 0; i < size / 4; i++) {  // loops through the first 25% of the vector
        if (data[i] < min) {  // if the ith value is less than what min currently is (int min = data[0])
            min = data[i];  // set min equal to the current index
        } 
    }

    // finding the max after the 75% mark
    int max = 0;  // set the max to 0
    for (int i = (3 * size) / 4; i < size; i++) {  // loops through 75% to the end of the vector
        if (data[i] > max) {  // if the current value is greater than what max currently is (int max = 0)
            max = data[i];  // set max equal to the current index
        }
    }
    
    // find min and max some other way, u can't use quickselect 5 times
    // 25% = size / 4
    // 50% = size / 4
    // 75 = (3 * size) / 4
    
    // outputs
    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << Q1 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << Q3 << std::endl;
    std::cout << "Max: " << max << std::endl;

    // const auto t1_end = std::chrono::steady_clock::now();
    // int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
    // std::cout << "\n" << t1 << " microseconds." << std::endl;
}

int insertionSort(std::vector<int> nums, int n) {
    int i, key, j;  // variables
    for (i = 1; i < n; i++) {
        key = nums[i];
        j = i - 1; 
    }

    while (j > 0 && nums[j] > key) { // while j is greater than 0 AND nums[j] is greater than key
        nums[j + 1] = nums[j];
        j = j - 1;  // decrement j
    }
    nums[j + 1] = key;  // set nums[j + 1] to whatever key is
}

int partition(std::vector<int> &nums, int left, int right) {
    int pivot = nums[right];  // set the pivot to the far right
    int left_index = left - 1;

    for (int i = left; i < right; i++) {
        if (nums[i] <= pivot) {  // if the element is less than or equal to the pivot
            left_index++;  // increment i
            std::swap(nums[left_index], nums[i]);  // swap
        }
    }
    std::swap(nums[left_index + 1], nums[right]);
    return left_index + 1;
}

int quickSelect(std::vector<int> &nums, int left, int right, int k) {
    if (right - left + 1 <= 20) {
        insertionSort(nums, right - left + 1);
        return nums[left + k - 1];
    }

    while (left < right) {
        int pivot_index = partition(nums, left, right);  // calls the partition function and set the pivot index
        int left_array_size = pivot_index - left + 1;  // calculates the size of the left subarray

        if (k == left_array_size) {  // if position is equal to left_array_size
            return nums[pivot_index];

        } else if (k < left_array_size) {  // if the position is less than left_array_size
            right = pivot_index - 1;

        } else {
            left = pivot_index + 1;
            k -= left_array_size;
        }
    }
    return nums[left];
}