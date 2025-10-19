#include <iostream> 
using namespace std;
class Employee{


    string empname;
    float basicsalary ;
    float allowance ;
    float totalsalary;

    public :
    void getdata() {
        cout<< "enter your salary : "<< endl;
        cin >>basicsalary;
        cout<< "enter your allowance" << endl;
        cin >> allowance;
    }
    void caltotalsalary(){
     totalsalary  = allowance + basicsalary ;

    }
    void display(){
    cout << "your total salary is : " <<totalsalary<< endl;
    cout << "basic salary : "<< basicsalary;
    cout<<"allowance : "<< allowance ;
   // cout<< totalsalary << endl;
    }
    };
    int main (){
        Employee p1;
        p1.getdata();
        p1.caltotalsalary();
        p1.display();

    }
