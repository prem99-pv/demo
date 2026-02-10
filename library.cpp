#include <iostream>
using namespace std;


void copyText(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}


class LibraryItem {
private:
    char title[50];
    char author[50];
    char dueDate[20];

protected:
    int isCheckedOut;

public:
    LibraryItem(const char* t, const char* a) {
        copyText(title, t);
        copyText(author, a);
        copyText(dueDate, "N/A");
        isCheckedOut = 0;
    }

    virtual ~LibraryItem() {}

    const char* getTitle() const { return title; }
    const char* getAuthor() const { return author; }
    const char* getDueDate() const { return dueDate; }

    void setDueDate(const char* d) {
        copyText(dueDate, d);
    }

    
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};


class Book : public LibraryItem {
private:
    int bookId;

public:
    Book(const char* t, const char* a, int id)
        : LibraryItem(t, a) {
        if (id <= 0)
            throw 1;
        bookId = id;
    }

    void checkOut() override {
        if (isCheckedOut)
            cout << "Book already checked out\n";
        else {
            isCheckedOut = 1;
            setDueDate("15 Days");
            cout << "Book checked out successfully\n";
        }
    }

    void returnItem() override {
        isCheckedOut = 0;
        setDueDate("N/A");
        cout << "Book returned successfully\n";
    }

    void displayDetails() const override {
        cout << "\n[Book]"
             << "\nTitle: " << getTitle()
             << "\nAuthor: " << getAuthor()
             << "\nBook ID: " << bookId
             << "\nDue Date: " << getDueDate() << endl;
    }
};


class DVD : public LibraryItem {
private:
    int duration;

public:
    DVD(const char* t, const char* a, int d)
        : LibraryItem(t, a) {
        if (d <= 0)
            throw 2;
        duration = d;
    }

    void checkOut() override {
        isCheckedOut = 1;
        setDueDate("7 Days");
        cout << "DVD checked out successfully\n";
    }

    void returnItem() override {
        isCheckedOut = 0;
        setDueDate("N/A");
        cout << "DVD returned successfully\n";
    }

    void displayDetails() const override {
        cout << "\n[DVD]"
             << "\nTitle: " << getTitle()
             << "\nAuthor: " << getAuthor()
             << "\nDuration: " << duration << " mins"
             << "\nDue Date: " << getDueDate() << endl;
    }
};


int main() {
    const int MAX_ITEMS = 5;
    LibraryItem* items[MAX_ITEMS];
    int count = 0;
    int choice;

    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Display Items\n";
        cout << "4. Check Out Item\n";
        cout << "5. Return Item\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            if (choice == 1 && count < MAX_ITEMS) {
                char t[50], a[50];
                int id;

                cout << "Enter title: ";
                cin >> t;
                cout << "Enter author: ";
                cin >> a;
                cout << "Enter book id: ";
                cin >> id;

                items[count++] = new Book(t, a, id);
            }
            else if (choice == 2 && count < MAX_ITEMS) {
                char t[50], a[50];
                int d;

                cout << "Enter title: ";
                cin >> t;
                cout << "Enter author: ";
                cin >> a;
                cout << "Enter duration: ";
                cin >> d;

                items[count++] = new DVD(t, a, d);
            }
            else if (choice == 3) {
                for (int i = 0; i < count; i++)
                    items[i]->displayDetails();
            }
            else if (choice == 4) {
                int index;
                cout << "Enter item index: ";
                cin >> index;
                items[index]->checkOut();
            }
            else if (choice == 5) {
                int index;
                cout << "Enter item index: ";
                cin >> index;
                items[index]->returnItem();
            }
        }
        catch (...) {
            cout << "Invalid input error occurred\n";
        }

    } while (choice != 0);

    for (int i = 0; i < count; i++)
        delete items[i];

    return 0;
}