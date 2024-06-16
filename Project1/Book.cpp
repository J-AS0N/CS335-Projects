#include "Book.hpp"

    // write and document all methods in this file.
    Book::Book()
    {
        title_ = "";
        author_ = "";
        ISBN_ = 0;
        icon_ = nullptr;
        price_ = 0.00;
        keywords_;
        blurb_ = "";

    }

    Book::~Book()  // destructor 
    {
        delete[] icon_;  // only icon_ is deleted because it's deallocating the entire array
        icon_ = nullptr;
    }

    Book::Book(const Book& rhs)  // copy constructor - L value because of &
    {
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;

        if (rhs.icon_) {  // checks if it's a nullptr or not (if there is a nullptr, it goes to the else statement)
            icon_ = new int[80];
            for (int i = 0; i < 80; i++) {  // if there is no nullptr, it loops and starts copying
                icon_[i] = rhs.icon_[i];
            }
        } else {
            icon_ = nullptr;
        }
    }

    Book& Book::operator=(const Book& rhs)  // copy assignment operator
    {
        if (this != &rhs) {  // checks if the address of current object is not equal to the address of the parameter
            title_ = rhs.title_;
            author_ = rhs.author_;
            ISBN_ = rhs.ISBN_;
            price_ = rhs.price_;
            keywords_ = rhs.keywords_;
            blurb_ = rhs.blurb_;

            if (rhs.icon_) {  // checks if it's a nullptr or not (if there is a nullptr, it goes to the else statement)
                icon_ = new int[80];
                for (int i = 0; i < 80; i++) {  // if there is no nullptr, it loops and starts copying
                    icon_[i] = rhs.icon_[i];
                }
            } else {
                icon_ = nullptr;
            }
        }
        return *this;
    }

    Book::Book(Book&& rhs)  // move constructor -> takes L value and convertes to a R value
    {
        title_ = std::move(rhs.title_);
        author_ = std::move(rhs.author_);
        ISBN_ = rhs.ISBN_;  //priminitive data types don't require std::move (just do it as a copy constructor)
        //delete[] icon_;  // assume rhs.icon_ and icon_ is on top of each other and you're deleting icon_ so the leftover data isn't floating around (we don't want anything lost in memory)
        icon_ = rhs.icon_;
        rhs.icon_ = nullptr;
        price_ = rhs.price_;
        keywords_ = std::move(rhs.keywords_);
        blurb_ = std::move(rhs.blurb_);
    }

    Book& Book::operator=(Book&& rhs)  // move assignment operator
    {
        if (this != &rhs) {
            title_ = std::move(rhs.title_);
            author_ = std::move(rhs.author_);
            ISBN_ = rhs.ISBN_;
            //delete[] icon_;
            icon_ = rhs.icon_;
            rhs.icon_ = nullptr;
            price_ = rhs.price_;
            keywords_ = std::move(rhs.keywords_);
            blurb_ = std::move(rhs.blurb_);
        } 
        return *this;
    }

    const std::string& Book::getTitle() const  // returns the title
    {
        return title_;
    }

    void Book::setTitle(const std::string& title)  // set the title to the parameter 
    {
        title_ = title;
    }

    const std::string& Book::getAuthor() const  // returns the author
    {
        return author_;
    }

    void Book::setAuthor(const std::string& author)  // set the author to the parameter
    {
        author_ = author;
    }

    long long int Book::getISBN() const  // return the ISBN
    {
        return ISBN_;
    }

    void Book::setISBN(long long int ISBN)  // set the ISBN to the parameter
    {
        ISBN_ = ISBN;
    }

    const int* Book::getIcon() const  // returns the icon
    {
        return icon_;
    }

    void Book::setIcon(int* icon)  // set the icon to the parameter
    {
        icon_ = icon;
    }

    float Book::getPrice() const  // return the price 
    {
        return price_;
    }

    void Book::setPrice(float price)  // set the price to parameter
    {
        price_ = price;
    }

    const std::vector<std::string>& Book::getKeywords() const  // return the keywords
    {
        return keywords_;
    }

    void Book::setKeywords(const std::vector<std::string>& keywords)  // set the keywords to the parameter 
    {
        keywords_ = keywords;
    }

    const std::string& Book::getBlurb() const  // returns blurb
    {
        return blurb_;
    }   

    void Book::setBlurb(const std::string& blurb)  // set the blurb to the parameter
    {
        blurb_ = blurb;
    }

    void Book::print() const  // print function
    {
        std::cout << "Title: " << getTitle() << std::endl;
        std::cout << "Author: " << getAuthor() << std::endl;
        std::cout << "ISBN: " << getISBN() << std::endl;
        std::cout << "Icon: ";

        for (int i = 0; i < 80; i++) {  // loops through the icon
            std::cout << icon_[i] << " ";  // prints out each icon at each element with a space
        }
        std::cout << std::endl;

        std::cout << "Price: $" << std::fixed << std::setprecision(2) << getPrice() << std::endl;  // sets the precision to two decimal places

        std::cout << "Keywords: ";
        for (int i = 0; i < keywords_.size(); i++) {  // loops through the keyword vector
            std::cout << keywords_[i];  // prints out each keyword in the vector
            if (i < keywords_.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;

        std::cout << "Blurb: " << getBlurb() << std::endl;

        std::cout << std::endl;
    }