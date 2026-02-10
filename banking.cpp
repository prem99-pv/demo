#include <iostream>
using namespace std;


class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;

private:
    double balance;   

public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    virtual ~BankAccount() {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful!\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        } else {
            cout << "Insufficient balance.\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    void setBalance(double bal) {
        balance = bal;
    }

    virtual void displayAccountInfo() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nAccount Holder: " << accountHolderName;
        cout << "\nBalance: " << balance << endl;
    }

    
    virtual void calculateInterest() = 0;
};


class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal) {
        interestRate = rate;
    }

    void calculateInterest() override {
        double interest = getBalance() * interestRate / 100;
        cout << "Savings Interest: " << interest << endl;
    }
};


class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        if (amount <= getBalance() + overdraftLimit) {
            setBalance(getBalance() - amount);
            cout << "Withdrawal successful (Overdraft applied if needed).\n";
        } else {
            cout << "Overdraft limit exceeded.\n";
        }
    }

    void calculateInterest() override {
        cout << "Checking accounts do not earn interest.\n";
    }
};


class FixedDepositAccount : public BankAccount {
private:
    int term; // in months
    double interestRate;

public:
    FixedDepositAccount(int accNo, string name, double bal, int t, double rate)
        : BankAccount(accNo, name, bal) {
        term = t;
        interestRate = rate;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal not allowed before maturity.\n";
    }

    void calculateInterest() override {
        double interest = getBalance() * interestRate * term / (12 * 100);
        cout << "Fixed Deposit Interest: " << interest << endl;
    }
};


int main() {
    BankAccount* accounts[10];  
    int accountCount = 0;
    int choice;

    do {
        cout << "\n===== Banking System Menu =====\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Create Fixed Deposit Account\n";
        cout << "4. Deposit\n";
        cout << "5. Withdraw\n";
        cout << "6. Display Account Info\n";
        cout << "7. Calculate Interest\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int index;
        double amount;

        switch (choice) {
        case 1: {
            int acc;
            string name;
            double bal, rate;

            cout << "Enter Account Number: ";
            cin >> acc;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> bal;
            cout << "Enter Interest Rate: ";
            cin >> rate;

            accounts[accountCount++] =
                new SavingsAccount(acc, name, bal, rate);

            cout << "Savings Account Created!\n";
            break;
        }
        case 2: {
            int acc;
            string name;
            double bal, limit;

            cout << "Enter Account Number: ";
            cin >> acc;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> bal;
            cout << "Enter Overdraft Limit: ";
            cin >> limit;

            accounts[accountCount++] =
                new CheckingAccount(acc, name, bal, limit);

            cout << "Checking Account Created!\n";
            break;
        }
        case 3: {
            int acc, term;
            string name;
            double bal, rate;

            cout << "Enter Account Number: ";
            cin >> acc;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> bal;
            cout << "Enter Term (months): ";
            cin >> term;
            cout << "Enter Interest Rate: ";
            cin >> rate;

            accounts[accountCount++] =
                new FixedDepositAccount(acc, name, bal, term, rate);

            cout << "Fixed Deposit Account Created!\n";
            break;
        }
        case 4:
            cout << "Enter Account Index (0 to " << accountCount - 1 << "): ";
            cin >> index;
            cout << "Enter Amount: ";
            cin >> amount;
            accounts[index]->deposit(amount);
            break;

        case 5:
            cout << "Enter Account Index (0 to " << accountCount - 1 << "): ";
            cin >> index;
            cout << "Enter Amount: ";
            cin >> amount;
            accounts[index]->withdraw(amount);
            break;

        case 6:
            cout << "Enter Account Index (0 to " << accountCount - 1 << "): ";
            cin >> index;
            accounts[index]->displayAccountInfo();
            break;

        case 7:
            cout << "Enter Account Index (0 to " << accountCount - 1 << "): ";
            cin >> index;
            accounts[index]->calculateInterest(); 
            break;

        case 0:
            cout << "Thank you for using Banking System!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    
    for (int i = 0; i < accountCount; i++) {
        delete accounts[i];
    }

    return 0;
}