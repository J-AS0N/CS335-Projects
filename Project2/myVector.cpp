#include "myVector.hpp"
#include <iostream>
#include <vector>
#include <chrono>

void vectorMedian(const std::vector<int> * instructions) {  // instructions = original vector of integers
    const auto t1_start = std::chrono::steady_clock::now();

    // initialize my variables
    std::vector<int> values;  // vector I'm pushing into
    std::vector<int> median_vector;  // vector that holds all the medians
        for (auto it = instructions->begin(); it < instructions->end(); it++) {  // iterates through the vector passed in the parameter

            if (*it == -1) {  // if the value in the vector is -1
                if (values.size() % 2 == 0) {  // if the vector size is even
                    auto med = (values.begin() + values.size() / 2 - 1);  // finds the lesser of the two values
                    median_vector.push_back(*med);

                    //std::cout << *med << " ";
                    values.erase(med);  // deleting the median 
                }

                else if (values.size() % 2 != 0) {  // if the vector is odd
                    auto med = (values.begin() + values.size() / 2);  // removes the median value
                    median_vector.push_back(*med);
                    
                    //std::cout << *med << " ";
                    values.erase(med);
                }
            }
            else {
                auto temp = std::lower_bound(values.begin(), values.end(), *it);  // keeps it sorted
                values.insert(temp, *it);
        }
    }

    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
    // std::cout << "\n" << t1 << " microseconds." << std::endl;

    // printing the median's vector
    for (int i = 0; i < median_vector.size(); i++) {
        std::cout << median_vector[i] << " ";
    }
}