#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Student {
private:
    T id;
    string name;

public:
    Student(T i, string n) {
        id = i;
        name = n;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    T getId() {
        return id;
    }
};

int main() {
    vector<Student<int>> students;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;

            students.push_back(Student<int>(id, name));
            cout << "Student Added Successfully!\n";
        }

        else if (choice == 2) {
            cout << "\n--- Student List ---\n";
            for (int i = 0; i < students.size(); i++) {
                students[i].display();
            }
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID to remove: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getId() == id) {
                    students.erase(students.begin() + i);
                    cout << "Student Removed Successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student Not Found!\n";
            }
        }

        else if (choice == 4) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getId() == id) {
                    cout << "Student Found:\n";
                    students[i].display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student Not Found!\n";
            }
        }

    } while (choice != 5);

    return 0;
}