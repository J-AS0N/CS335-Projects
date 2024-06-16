#include "myList.hpp"

void listMedian(const std::vector<int> * instructions) {
    const auto t1_start = std::chrono::steady_clock::now();

    // initialize my variables
    std::list<int> values_list;
    std::vector<int> median_vector;

    for (auto it = instructions->begin(); it != instructions->end(); it++) {  // loops through the vector 

        if (*it == -1) {  // if the value you encounter is a -1

            if (values_list.size() % 2 == 0) {  // if the size of the list is even
                auto median = std::next(values_list.begin(), values_list.size() / 2 - 1);  // finds the median and keeps it's iterator stored in the variable "median"
                median_vector.push_back(*median);  // push the median value in a median vector

                // std::cout << *median << " ";
                values_list.erase(median);  // removes the median
            }
            else if (values_list.size() % 2 != 0) {  // if the size of the list is odd
                auto median = std::next(values_list.begin(), values_list.size() / 2);
                median_vector.push_back(*median);  // push the median value in a median vector
                
                // std::cout << *median << " ";
                values_list.erase(median);  // removes the median
            }
        }
        else {
            auto median_position = values_list.begin();  // stores the iterator pointing to the first position
            while (median_position != values_list.end() && *median_position < *it) {  // keeps looping until it reaches the end of the list and the value is less than the current value in the list
                median_position++;  // moves the position of the iterator
            }
            values_list.insert(median_position, *it);  // insert the value (*it) at the position of the iterator (median_position)
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

