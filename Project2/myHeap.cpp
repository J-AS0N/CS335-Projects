#include "myHeap.hpp"

void heapMedian(const std::vector<int> * instructions) {
    const auto t1_start = std::chrono::steady_clock::now();

    // max heap (default comparator = std::less)   ->   if you want a min heap: use std::greater as the comparator 
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
    std::vector<int> median_vector;

    for (auto it = instructions->begin(); it != instructions->end(); it++) {  // iterate through each element in instructions
        if (*it == -1) {  // if it encounters a -1

            if (!max_heap.empty() || !min_heap.empty()) {  // both heaps are not empty
                int median1 = max_heap.top();  // grabs the median for max_heap
                int median2 = min_heap.top();  // grabs the median for min_heap
                median_vector.push_back(std::min(median1, median2));  // compares which median is smaller and pushes it into the vector

                max_heap.pop();  // pop 
                
                // rebalance the heap
                if (max_heap.size() > min_heap.size() + 1) {
                    min_heap.push(max_heap.top());
                    max_heap.pop();

                } else if (min_heap.size() > max_heap.size()) {
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }
            }
        }
        else {
            if (max_heap.empty() || *it <= max_heap.top()) {  // checks if the max_heap is empty or if the current value is <= top element of max_heap
                max_heap.push(*it);  // if it's less then it should be on the left so it gets pushed into max_heap
            } else {  // if it's greater
                min_heap.push(*it);  // value gets pushed into min_heap
            }

            // rebalance the heap

            if (max_heap.size() > min_heap.size() + 1) {  
                min_heap.push(max_heap.top());
                max_heap.pop();

            } else if (min_heap.size() > max_heap.size()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
    }

    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
    // std::cout << "\n" << t1 << " microseconds." << std::endl;

    for (int i = 0; i < median_vector.size(); i++) {
        std::cout << median_vector[i] << " ";
    }
}