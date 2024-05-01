
#include <iostream>
#include <string>

using namespace std;

class Book {
public:
  // Default constructor (optional)
  Book() {
    title = "";
    author = "";
    pages = 0;
  }

  // Constructor with parameters
  Book(string title, string author, int pages) {
    this->title = title; // Use 'this' pointer to avoid shadowing
    this->author = author;
    this->pages = pages;
  }

  // Copy constructor
  Book(const Book& other) {
    // Deep copy to avoid copying pointers
    title = other.title;
    author = other.author;
    pages = other.pages;
  }

  // Member functions (optional)
  void printInfo() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Pages: " << pages << endl;
  }

private:
  string title;
  string author;
  int pages;
};

int main() {
  // Create a Book object
  Book book1("The Lord of the Rings", "J.R.R. Tolkien", 1178);

  // Print book1 info
  cout << "Book 1 info:" << endl;
  book1.printInfo();
  cout << endl;

  // Create a copy of book1 using the copy constructor
  Book book2(book1);

  // Print book2 info (should be the same as book1)
  cout << "Book 2 info:" << endl;
  book2.printInfo();

  return 0;
}