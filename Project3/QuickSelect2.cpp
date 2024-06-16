#include "QuickSelect2.hpp"

void quickSelect2(const std::string &header, std::vector<int> data) {
    // const auto t1_start = std::chrono::steady_clock::now();

    int size = data.size();  // size of the data

    // find the index of each percentile and push it in a vector, then pass the vector of indexes in quickSelect as "keys"
    std::vector<int> key_position;

    /*
    Finding the index of each percentiles:
    25% = size / 4
    50% = size / 2
    75 = (3 * size) / 4
    */

    // calculate the indices for the 5 number summary
    int min = 0;
    int Q1 = (size / 4) - 1;
    int median = (size / 2) - 1;
    int Q3 = 3 * (size / 4) - 1;
    int max = data.size() - 1;

    // pushes them into a vector
    key_position.push_back(min);
    key_position.push_back(Q1);
    key_position.push_back(median);
    key_position.push_back(Q3);
    key_position.push_back(max);

    quickSelect(data, 0, size - 1, key_position);
    
    // outputs
    std::cout << header << std::endl;
    std::cout << "Min: " << data[0] << std::endl;
    std::cout << "P25: " << data[Q1] << std::endl;
    std::cout << "P50: " << data[median] << std::endl;
    std::cout << "P75: " << data[Q3] << std::endl;
    std::cout << "Max: " << data[data.size() - 1] << std::endl;

    // const auto t1_end = std::chrono::steady_clock::now();
    // int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
    // std::cout << "\n" << t1 << " microseconds." << std::endl;
}

void insertionSort(std::vector<int>& nums, int left, int right){
    for(int i = left + 1; i <= right; i++){
        int key = nums[i];
        int j = i - 1;
        while (j >= left && nums[j] > key){
            nums[j + 1] = nums[j]; //move index over
            j--; //decrement the index
        }

        nums[j + 1] = key;
    }
}

int partition(std::vector<int>& nums, int left, int right){
    int pivot = nums[right];  // set the pivot as "right"
    int i = left;  // set i as "left"

    for (int j = left; j < right; j++) {
        if (nums[j] <= pivot) {
            std::swap(nums[i], nums[j]);
            i++;
        }
    }

    std::swap(nums[i], nums[right]);  // swapping the two values at index i and right in the vector data
    return i;  // returns the index of the pivot after partitioning
}

void quickSelect(std::vector<int> &nums, int left, int right, std::vector<int> keys) {
    if (right - left + 1 <= 20) {  // after reaching a size of 20, default to insertionSort
        insertionSort(nums, left, right);
    }

    if (left < right) {
        int pivot_index = partition(nums, left, right);

        // creating two int vectors
        std::vector<int> left_keys;
        std::vector<int> right_keys;

        // loops through the keys vector
        for (int key : keys) {
            if (key < pivot_index) {  // if the key is less than the pivot_index
                left_keys.push_back(key);  // push the key to the left_key vector
            } else if (key > pivot_index) {  // if the key is greater than the pivot_index
                right_keys.push_back(key);  // push the key to the right_key vector
            }
        }
        // checks if the left_key and right_key are NOT empty
        if (!left_keys.empty()) {
            quickSelect(nums, left, pivot_index - 1, left_keys);  // recursive call
        }
        if (!right_keys.empty()) {
            quickSelect(nums, pivot_index + 1, right, right_keys);  // recursive call
        }

    }
}