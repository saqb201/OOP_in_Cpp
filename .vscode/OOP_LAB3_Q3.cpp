#include <iostream>
#include <string>

using namespace std;

const int MAX_AUTHORS = 4;
const int MAX_BOOKS = 100;

class bookType {
private:
    string title;
    string authors[MAX_AUTHORS];
    string publisher;
    string ISBN;
    double price;
    int numCopiesInStock;
    int numAuthors;
    int publicationYear;

public:
    // Constructors
    bookType() : title(""), publisher(""), ISBN(""), price(0.0), numCopiesInStock(0), numAuthors(0), publicationYear(0) {}
    bookType(string t, string pub, string isbn, double p, int copies, int numAuth, int pubYear)
        : title(t), publisher(pub), ISBN(isbn), price(p), numCopiesInStock(copies), numAuthors(numAuth), publicationYear(pubYear) {
        for (int i = 0; i < numAuthors; ++i) {
            authors[i] = ""; // Initialize all authors to empty strings
        }
    }

    // Getters and setters for various properties
    void setTitle(string t) { title = t; }
    string getTitle() const { return title; }

    void setPublicationYear(int y) { publicationYear = y; }
    int getPublicationYear() const { return publicationYear; }

    void setNumAuthors(int n) { numAuthors = n; }

    void setAuthor(int index, string author) {
        if (index >= 0 && index < MAX_AUTHORS)
            authors[index] = author;
    }
    string getAuthor(int index) const {
        if (index >= 0 && index < numAuthors)
            return authors[index];
        else
            return "";
    }

    void setPublisher(string pub) { publisher = pub; }
    string getPublisher() const { return publisher; }

    void setISBN(string isbn) { ISBN = isbn; }
    string getISBN() const { return ISBN; }

    void setPrice(double p) { price = p; }
    double getPrice() const { return price; }

    void setNumCopiesInStock(int copies) { numCopiesInStock = copies; }
    int getNumCopiesInStock() const { return numCopiesInStock; }

    // Other member functions
    void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Authors: ";
        for (int i = 0; i < numAuthors; ++i) {
            cout << authors[i];
            if (i < numAuthors - 1)
                cout << ", ";
        }
        cout << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Publication Year: " << publicationYear << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Price: Rs." << price << endl;
        cout << "Number of copies in stock: " << numCopiesInStock << endl;
    }

    // Search book by title
    bool searchByTitle(string searchTitle) const {
        return (title == searchTitle);
    }

    // Search book by ISBN
    bool searchByISBN(string searchISBN) const {
        return (ISBN == searchISBN);
    }

    // Update number of copies
    void updateCopies(int newCopies) {
        numCopiesInStock = newCopies;
    }
};

int main() {
    // Creating sample books
    bookType books[MAX_BOOKS] = {
        bookType("home", "SCOT ALEN ", "1-2-3-4", 50.99, 100, 1, 2009),
        bookType("ALEXZENDER", "ROBERT WILLIAMSON", "5-6-7-8", 207.99, 300, 1, 1990)
    };
    books[0].setAuthor(0, "SM SAQIB FAHEEM");
    books[1].setAuthor(0, "RATHER FORD ");

    // User input for title
    string searchTitle;
    cout << "Enter the title of the book you want to search: ";
    getline(cin, searchTitle);

    // Attempt to search for a book by title
    bool foundByTitle = false;
    for (const auto &book : books) {
        if (book.searchByTitle(searchTitle)) {
            cout << "Book found by title: " << book.getTitle() << endl << endl;
            book.displayInfo();
            foundByTitle = true;
            break;
        }
    }
    if (!foundByTitle) {
        cout << "Book not found by title: " << searchTitle << endl;
    }

    // User input for ISBN
    string searchISBN;
    cout << endl << "Enter the ISBN of the book you want to search: ";
    getline(cin, searchISBN);

    // Attempt to search for a book by ISBN
    bool foundByISBN = false;
    for (const auto &book : books) {
        if (book.searchByISBN(searchISBN)) {
            cout << "Book found by ISBN: " << book.getISBN() << endl << endl;
            book.displayInfo();
            foundByISBN = true;
            break;
        }
    }
    if (!foundByISBN) {
        cout << "Book not found by ISBN: " << searchISBN << endl;
    }

    // Update number of copies
    string updateTitle;
    cout << endl << "Enter the title of the book you want to update the number of copies for: ";
    getline(cin, updateTitle);
    int newCopies;
    cout << "Enter the new number of copies: ";
    cin >> newCopies;
    cin.ignore(); // Clear newline character from input buffer
    bool updated = false;
    for (int i = 0; i < 2; ++i) { // Assuming there are only two books for now
        if (books[i].searchByTitle(updateTitle)) {
            books[i].updateCopies(newCopies);
            cout << "Updated number of copies for '" << updateTitle << "': " << books[i].getNumCopiesInStock() << endl << endl;
            books[i].displayInfo();
            updated = true;
            break; // Break loop once updated
        }
    }
    if (!updated)
        cout << "Book not found to update the number of copies." << endl;

    return 0;
}