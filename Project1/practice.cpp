#include <iostream>
#include <list>


// practice

// Example 1) Complete the following function that prints out all multiples of x from a list, in reverse order:
void ReversePrintMultiples (std::list<int> &nums, const int x) {
   for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
    if (*it % x == 0) {
        std::cout << *it << " ";
    }
   }
}

int main() {
    std::list<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(8);

    ReversePrintMultiples(nums, 2);
    return 0;
}

class Student {
    public:

    private:
        std::string syllabus_;
        std::vector<Student> roster_;
        int courseNumber_;
        int* gradeData_;

};


AlgorithmsCourse::AlgorithmsCourse(AlgorithmsCourse&& temp) {
    syllabus_ = std::move(temp.syllabus_);
    roster_ = std::move(temp.roster_);
    courseNumber_ = std::move(temp.courseNumber_);
    gradeData_ = std::move(temp.gradeData);
    temp.gradeData = nullptr;
}

// copy constructor
Book::Book (const Book& rhs) {}

// copy assignment operator
Book& Book::operator= (Book& rhs) {}

// move constructor
Book::Book (const Book&& rhs) {}

// move assignment operator
Book& Book::operator=(const Book&& rhs) {}

// operator assignment
if (this != &rhs) {
    // .....
} return *this;

//  Example 1) Complete the following function that prints out all multiples of x from a list, in reverse order:
void ReversePrintMultiples (std::list<int> &nums, const int x) {
    for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
        if (*it % x == 0) {
            std::cout << *it << " ";
        }
    }
}

