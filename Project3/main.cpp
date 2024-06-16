#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"

int main() {

    std::string filename = "test_input1.txt";
    std::ifstream temp (filename);

    if (!temp.is_open()) {
        std::cout << "Error!" << filename << std::endl;
    }

    // helper variables for reading the file
    std::string title;
    std::string realnum;
    std::vector<int> nums;

    // read / print the header "Male elephant seal weights"
    std::getline(temp, title);
    std::cout << title << std::endl;

    while(temp >> realnum) {
        std::stringstream temp2(realnum);
        int number;
        if (temp2 >> number) {
            nums.push_back(number);
        }
    }


    // for (int i = 0; i < nums.size(); i++) {
    //     std::cout << nums[i] << " ";
    // }

    // function testing
    //stdSort("Male elephant seal weights", nums);
    quickSelect1("Male elephant seal weights", nums);
    //quickSelect2("Male elephant seal weights", nums);
    //countingSort("Male elephant seal weights", nums);
}