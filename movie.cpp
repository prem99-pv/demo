#include <iostream>
using namespace std;

class Movie {
public:
    string title, genre;
    int releaseYear;

    void display() {
        cout << title << " | " << genre << " | " << releaseYear << endl;
    }
};

class BankAccount {
private:
    int accountNumber;
    double balance;
    string ownerName;

public:
    BankAccount(int acc, string name, double bal) {
        accountNumber = acc;
        ownerName = name;
        balance = bal;
    }

    void credit(double amount) {
        balance += amount;
    }

    void debit(double amount) {
        balance -= amount;
    }

    void displayBalance() {
        cout << "Balance: " << balance << endl;
    }
};

class Vehicle {
protected:
    string model;
    double speed;

public:
    Vehicle(string m, double s) : model(m), speed(s) {}

    double timeTaken(double distance) {
        return distance / speed;
    }

    virtual void displayDetails() {
        cout << "Vehicle: " << model << endl;
    }
};

class Car : public Vehicle {
public:
    Car(string m, double s) : Vehicle(m, s) {}

    void displayDetails() override {
        cout << "Car Model: " << model << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(string m, double s) : Vehicle(m, s) {}

    void displayDetails() override {
        cout << "Bike Model: " << model << endl;
    }
};

class Shape {
public:
    virtual double calculateArea() = 0;
    virtual void draw() = 0;
};

class Circle : public Shape {
    double r;
public:
    Circle(double radius) : r(radius) {}

    double calculateArea() {
        return 3.14 * r * r;
    }

    void draw() {
        cout << "Drawing Circle\n";
    }
};

class Rectangle : public Shape {
    double l, w;
public:
    Rectangle(double len, double wid) : l(len), w(wid) {}

    double calculateArea() {
        return l * w;
    }

    void draw() {
        cout << "Drawing Rectangle\n";
    }
};

int main() {

    cout << "\n--- Movies ---\n";
    Movie movies[2] = {
        {"Inception", "Sci-Fi", 2010},
        {"Avatar", "Action", 2009}
    };

    for(int i=0;i<2;i++)
        movies[i].display();

    cout << "\n--- Bank Account ---\n";
    BankAccount acc(101, "Prem", 5000);
    acc.credit(1000);
    acc.debit(500);
    acc.displayBalance();

    cout << "\n--- Vehicles ---\n";
    Vehicle* v[2];
    v[0] = new Car("Honda", 60);
    v[1] = new Bike("Yamaha", 40);

    for(int i=0;i<2;i++) {
        v[i]->displayDetails();
        cout << "Time for 120km: " << v[i]->timeTaken(120) << " hrs\n";
    }

    cout << "\n--- Shapes ---\n";
    Shape* s[2];
    s[0] = new Circle(5);
    s[1] = new Rectangle(4,6);

    for(int i=0;i<2;i++) {
        s[i]->draw();
        cout << "Area: " << s[i]->calculateArea() << endl;
    }

    return 0;
}