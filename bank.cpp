#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;   
    float balance;      

public:

    void setAccount(int accNo, float initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
    }

   
    void deposit(float amount) {
        if (amount > 0) {
            balance = balance + amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }


    void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance = balance - amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

 
    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc;

    acc.setAccount(1234, 1000);  
    acc.display();

    acc.deposit(500);   
    acc.withdraw(200);  
    acc.withdraw(2000); 
    acc.display();     

    return 0;
}
