#include <iostream>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor to initialize the account
    Account(string accNum, string name, double bal) {
        accountNumber = accNum;
        accountHolderName = name;
        balance = bal;
    }

    // Deposit money
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }


    
    // Withdraw money
    virtual void withdraw(double amount) { // virtual for polymorphism
        if(amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    // Display account info
    virtual void displayInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    // Getter for balance (encapsulation)
    double getBalance() { return balance; }
};
class CurrentAccount : public Account {
private:
    double transactionLimit;

public:
    CurrentAccount(string accNum, string name, double bal, double limit)
        : Account(accNum, name, bal) {
        transactionLimit = limit;
    }

    void withdraw(double amount) override {
        if(amount > transactionLimit) {
            cout << "Cannot withdraw more than transaction limit!" << endl;
        } else {
            Account::withdraw(amount); // call base withdraw
        }
    }

    void displayInfo() override {
        Account::displayInfo();
        cout << "Transaction Limit: " << transactionLimit << endl;
    }
};
int main() {
    SavingsAccount sa("SA123", "Ayesha", 1000.0, 5.0);
    CurrentAccount ca("CA456", "Ayesha", 2000.0, 500.0);

    cout << "\n--- Savings Account ---\n";
    sa.displayInfo();
    sa.deposit(500);
    sa.withdraw(200);
    sa.addInterest();
    sa.displayInfo();

    cout << "\n--- Current Account ---\n";
    ca.displayInfo();
    ca.deposit(1000);
    ca.withdraw(600); // exceeds limit
    ca.withdraw(400); // allowed
    ca.displayInfo();

    return 0;
}
