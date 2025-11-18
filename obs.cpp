#include <iostream>
using namespace std;
class Account {
    private:
    string accnum;
    string accholname;
    double balance;
    public:
    Account(string accnum , string accholname , double balance){
        this ->accnum = accnum;
        this->accholname= accholname;
        this->balance= balance;
    }
   string getaccnum(){
    return accnum;
   }
   string getaccholname(){
    return accholname;
   }
   double getbalance(){
    return balance;
   }
    virtual void deposit(double amount){
if (amount > 0 )
{
    balance += amount;
}
else{
    cout<< "invalid amount "<<endl;
}
    }
    virtual void withdraw(double amount){
if (amount <= balance && amount> 0 )
{
    balance -= amount;
}
else{
    cout<< "invalid amount "<<endl;
}
    }

    void display(){
       cout<<"accnum: "<<accnum <<endl;
     cout<<"accholname: "<<accholname<<endl;
   cout<<"balance: "<<balance<<endl;
    }
};
class SavingsAccount : public Account{
private:
double interestRate;
public:
SavingsAccount(double interestRate ,string accnum ,string accholname , double balance): Account (accnum , accnum , balance){
    this-> interestRate = interestRate;
}

 void addInterest() {
    double interest = getbalance() * interestRate / 100;
    deposit(interest);  
}

};
/* Create another derived class with the following attributes and behavior:
•	Additional Data Member:
o	transactionLimit (double)
•	Overridden Functionality:
o	withdraw(double amount) → Override the base class method to restrict withdrawals that exceed the defined transaction limit.
o	displayInfo() → Override to include transaction limit information in the output.
*/
class CurrentAccount{
    private:
    double transactionlimit ;
public:

};
int main(){
    Account a1("001" , "ayesha" , 100);
    a1.deposit(0);
    a1.withdraw(1220);
    a1.display();

}
