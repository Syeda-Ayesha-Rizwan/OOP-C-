#include <iostream>
using namespace std;
class Account{
protected:
string accountnumber ;
string accountholdername;
double balance;
public:
void setaccountnumber(string accountnumber){ 
    this -> accountnumber = accountnumber;
}
string getaccountnumber(){
    return accountnumber;
}
string accountholdername(){
    return accountholdername;
}
double balance (){
    return balance ;
}
void setaccountholdername(string accountholdername){
    this -> accountholdername = accountholdername;
}
void setbalance(double balance){
   this->  balance= balance;
}

void deposit(){
    cout <<"enter your amount : "<<endl;
    cin>> amount;
    if(amount> 0 ){
        balance += amount;
        cout<< "amount deposited : "<< amount<< endl;
        cout<< "balance : "<< balance << endl;
    }
    else{
        cout<< "invalid amount "<< endl;
    }
}

void withdraw (){
    cout<< "enter amount : "<< endl;
    cin>> amount ;
    if(amount < balance ){
        balance -= amount ;
        cout << "amount withdraw : "<< amount << endl;
        cout << "currentbalance : "<<balance<<endl;

    }
    else {
        cout << "insufficient balance "<<endl;

    }
}
void displayinfo(){
    cout <<"account number "<< accountnumber << endl;
    cout << "holder name: "<<accountholdername<< endl;
    cout<< "balance: " <<balance<< endl;
}

};