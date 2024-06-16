#include "CountingSort.hpp"

void countingSort(const std::string &header, std::vector<int> data) {
    // const auto t1_start = std::chrono::steady_clock::now();

    std::unordered_map <int, int> hashMap;


    for (int i = 0; i < data.size(); i++) {
        if (hashMap.count(data[i] == 0)) {  // if it's not in the hashMap

            hashMap[data[i]] = 1;  // puts the value into the hashmap and set it equal to 1
        } else {  // if it's already in the hash
            hashMap[data[i]] = hashMap[data[i]] + 1;  // increment the count by 1
        }
    }
    
    // vector of pairs that matches the hashMap  ->  each pair consists of a number and its count (how many times it appears)
    std::vector<std::pair<int,int> > tempVector;
    for (const auto& pair : hashMap) {
        tempVector.push_back(pair);  // pairs the key and the value and pushes it in the vector
    }

    std::sort(tempVector.begin(), tempVector.end());  // sorts the vector
    int unique_counter = tempVector.size();  // number of unique values 

    // variables
    int min, max;

    min = tempVector[0].first;
    max = tempVector[tempVector.size() - 1].first;

    int total_counter = 0;  // total_counter will represent the size of the data including duplicates
    int Q1 = -1, median = -1, Q3 = -1;  // -1 to show the variables haven't been assigned to a valid index

    for (int i = 0; i < tempVector.size(); i++) {
        total_counter += tempVector[i].second;  // adds up the total count for each unique number

        if (Q1 == -1 && total_counter >= data.size() / 4) {
            Q1 = tempVector[i].first;
        }
        if (median == -1 && total_counter >= data.size() / 2) {
            median = tempVector[i].first;
        }
        if (Q3 == -1 && total_counter >= (3 * data.size()) / 4) {
            Q3 = tempVector[i].first;
            break;
        }
    }

    // outputs
    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << Q1 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << Q3 << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Unique: " << unique_counter << std::endl;

    // const auto t1_end = std::chrono::steady_clock::now();
    // int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
    // std::cout << "\n" << t1 << " microseconds." << std::endl;
}