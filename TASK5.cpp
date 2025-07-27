// TASK 5//
// LIBRARY MANAGEMENT SYSTEM


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool available = true;
    string dueDate;

    void display() {
        cout << left << setw(20) << title
             << setw(20) << author
             << setw(15) << ISBN
             << setw(10) << (available ? "Yes" : "No") << endl;
    }
};

vector<Book> library;

void loadBooks() {
    ifstream file("books.txt");
    Book b;
    while (file >> ws && getline(file, b.title) && getline(file, b.author) && getline(file, b.ISBN)) {
        file >> b.available >> ws;
        getline(file, b.dueDate);
        library.push_back(b);
    }
    file.close();
}

void saveBooks() {
    ofstream file("books.txt");
    for (auto& b : library) {
        file << b.title << "\n" << b.author << "\n" << b.ISBN << "\n" << b.available << "\n" << b.dueDate << "\n";
    }
    file.close();
}

void addBook() {
    Book b;
    cout << "Enter title: "; getline(cin >> ws, b.title);
    cout << "Enter author: "; getline(cin, b.author);
    cout << "Enter ISBN: "; getline(cin, b.ISBN);
    b.available = true;
    b.dueDate = "N/A";
    library.push_back(b);
    saveBooks();
    cout << "Book added successfully!\n";
}

void searchBook() {
    string keyword;
    cout << "Enter title, author, or ISBN to search: ";
    getline(cin >> ws, keyword);
    bool found = false;
    for (auto& b : library) {
        if (b.title.find(keyword) != string::npos || b.author.find(keyword) != string::npos || b.ISBN.find(keyword) != string::npos) {
            b.display();
            found = true;
        }
    }
    if (!found) cout << "No book found.\n";
}

string getCurrentDatePlusDays(int days) {
    time_t now = time(0);
    now += days * 24 * 3600;
    tm* t = localtime(&now);
    char buffer[11];
    strftime(buffer, 11, "%Y-%m-%d", t);
    return string(buffer);
}

void checkoutBook() {
    string isbn;
    cout << "Enter ISBN to checkout: ";
    getline(cin >> ws, isbn);
    for (auto& b : library) {
        if (b.ISBN == isbn && b.available) {
            b.available = false;
            b.dueDate = getCurrentDatePlusDays(7);  
            saveBooks();
            cout << "Book checked out! Due on: " << b.dueDate << endl;
            return;
        }
    }
    cout << "Book not available or not found.\n";
}

int calculateFine(string dueDate) {
    tm tmDue = {};
    strptime(dueDate.c_str(), "%Y-%m-%d", &tmDue);
    time_t due = mktime(&tmDue);
    time_t now = time(0);
    double seconds = difftime(now, due);
    int daysLate = seconds / (24 * 3600);
    return (daysLate > 0) ? daysLate * 5 : 0;  // ₹5 per day fine
}

void returnBook() {
    string isbn;
    cout << "Enter ISBN to return: ";
    getline(cin >> ws, isbn);
    for (auto& b : library) {
        if (b.ISBN == isbn && !b.available) {
            b.available = true;
            int fine = calculateFine(b.dueDate);
            b.dueDate = "N/A";
            saveBooks();
            cout << "Book returned successfully.\n";
            if (fine > 0)
                cout << "Late Fine: ₹" << fine << endl;
            return;
        }
    }
    cout << "Book not found or not checked out.\n";
}

void showAllBooks() {
    cout << left << setw(20) << "Title" << setw(20) << "Author"
         << setw(15) << "ISBN" << setw(10) << "Available\n";
    cout << string(65, '-') << endl;
    for (auto& b : library) b.display();
}

void menu() {
    while (true) {
        cout << "\n=== Library Management Menu ===\n";
        cout << "1. Add Book\n2. Search Book\n3. Show All Books\n4. Checkout Book\n5. Return Book\n6. Exit\nChoose: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: showAllBooks(); break;
            case 4: checkoutBook(); break;
            case 5: returnBook(); break;
            case 6: return;
            default: cout << "Invalid choice.\n";
        }
    }
}

int main() {
    loadBooks();
    menu();
    return 0;
}
