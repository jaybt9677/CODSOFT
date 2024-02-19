//B001,B002-(card no.)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    bool isAvailable;

    Book(string title, string author, string ISBN) : title(title), author(author), ISBN(ISBN), isAvailable(true) {}
};

class Borrower {
public:
    string name;
    string libraryCardNumber;

    Borrower(string name, string libraryCardNumber) : name(name), libraryCardNumber(libraryCardNumber) {}
};

class Transaction {
public:
    Book* book;
    Borrower* borrower;
    string borrowDate;

    Transaction(Book* book, Borrower* borrower, string borrowDate) : book(book), borrower(borrower), borrowDate(borrowDate) {}
};

class Library {
private:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void addBorrower(const Borrower& borrower) {
        borrowers.push_back(borrower);
    }

    void checkOutBook(const string& title, const string& libraryCardNumber, const string& borrowDate) {
        auto bookIt = find_if(books.begin(), books.end(), [&title](const Book& book) { return book.title == title && book.isAvailable; });
        auto borrowerIt = find_if(borrowers.begin(), borrowers.end(), [&libraryCardNumber](const Borrower& borrower) { return borrower.libraryCardNumber == libraryCardNumber; });

        if (bookIt != books.end() && borrowerIt != borrowers.end()) {
            bookIt->isAvailable = false;
            transactions.push_back(Transaction(&(*bookIt), &(*borrowerIt), borrowDate));
            cout << "Book checked out successfully." << endl;
        } else {
            cout << "Book not found or borrower not registered or book is not available." << endl;
        }
    }

    void returnBook(const string& title) {
        auto it = find_if(transactions.begin(), transactions.end(), [&title](const Transaction& transaction) {
            return transaction.book->title == title;
        });

        if (it != transactions.end()) {
            it->book->isAvailable = true;
            transactions.erase(it);
            cout << "Book returned successfully." << endl;
        } else {
            cout << "Book not found in transactions." << endl;
        }
    }

    void displayBooks() const {
        cout << "Books available in the library:" << endl;
        for (const auto& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN << ", Available: " << (book.isAvailable ? "Yes" : "No") << endl;
        }
    }

    void displayTransactions() const {
        cout << "Transactions:" << endl;
        for (const auto& transaction : transactions) {
            cout << "Title: " << transaction.book->title << ", Borrower: " << transaction.borrower->name << ", Borrow Date: " << transaction.borrowDate << endl;
        }
    }
};

int main() {
    Library library;

    // Add some sample books
    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger", "978-0-316-76948-0"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", "978-0-06-112008-4"));

    // Add some sample borrowers
    library.addBorrower(Borrower("Jay Thorat", "B001"));
    library.addBorrower(Borrower("Intern 1", "B002"));

    int choice;
    do {
        cout << "\nLIBRARY MANAGEMENT SYSTEM\n";
        cout << "1. Check out a book\n";
        cout << "2. Return a book\n";
        cout << "3. Display available books\n";
        cout << "4. Display transactions\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, cardNumber, date;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter borrower's library card number: ";
                getline(cin, cardNumber);
                cout << "Enter borrow date (YYYY-MM-DD): ";
                getline(cin, date);
                library.checkOutBook(title, cardNumber, date);
                break;
            }
            case 2: {
                string title;
                cout << "Enter book title to return: ";
                cin.ignore();
                getline(cin, title);
                library.returnBook(title);
                break;
            }
            case 3:
                library.displayBooks();
                break;
            case 4:
                library.displayTransactions();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
