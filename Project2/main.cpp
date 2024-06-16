#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <list>
#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include "myAVLtree.hpp"



int main() {
    std::vector<int> myVec;

    std::string filename = "testinput.txt";
    std::ifstream temp (filename);

    // helper variables for reading the file
    std::string line;
    std::string num;

    std::string newline;
    std::string num1;

    int realnum;

    while(std::getline(temp, line)) {
        std::stringstream temp2(line);
        std::getline(temp2, num, ' ');  // gets the word

        std::getline(temp2, num1, ' ');  // gets the number

        if(num == "insert") {
            realnum = stoi(num1);  // converts string to int
            myVec.push_back(realnum);
        } else {  // if the first word is anything other than "insert" (pop)
            myVec.push_back(-1);  // insert a -1
        }
    }
    // for (int i = 0; i < myVec.size(); i++) {
    //     std::cout << myVec[i] << " ";
    // }

    //vectorMedian(&myVec);
    //listMedian(&myVec);
    //heapMedian(&myVec);
    treeMedian(&myVec);

}

