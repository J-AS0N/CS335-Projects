#include "MoveAll.hpp"
#include "Book.hpp"

// Moves all Books in "source" with the specified keyword to "dest".
// A Book is moved if any of its keywords match the one specified in this function.
// Use iterators whenever appropriate.
// Hint: you need a const iterator for a const vector, but this will be automatically handled using "auto".

void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest){
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved = 0; // counts books moved
  // DO NOT ALTER ABOVE HERE

  // erase this comment and write your code here
  for (std::vector<Book>::iterator it = source.begin(); it != source.end(); ++it) {  // looping through the source (vector of books)
    const auto &book = *it;
    bool found = false;
    for (int i = 0; i < book.getKeywords().size(); i++) {  // loops through the first book in source's keywords
      if (book.getKeywords()[i] == keyword) {  // if there is a matched keyword
        found = true;  // set the boolean to true
      }
    }
    if (found) {  // if a matched keyword is found
      dest.push_back(std::move(*it));  // move the book to "dest"
      it = source.erase(it);
      it--;
      books_moved++;
    }
  }


  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}