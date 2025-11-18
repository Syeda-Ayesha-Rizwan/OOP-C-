#include <iostream>
using namespace std;
class Employee{
    private:
    int empNumber;
    float empSalary;
    public:
    void setemployeesalary( float empSalary){
      
      this->empSalary = empSalary;
    }

    void setempNumber(int empNumber){
    this->empNumber = empNumber;
    }
   
    void display(){
        cout<< " emp number : "<< empNumber<< endl;
        cout<< " salary : "<< empSalary<< endl;
    }
};
int main ()
{
    Employee e1;
    e1.setemployeesalary(1111.1);
    e1.setempNumber(01);
    e1.display();


    Employee e2;
    e2.setemployeesalary(2222.2);
    e2.setempNumber(02);
    e2.display();

    Employee e3;
    e3.setempNumber(03);
    e3.setemployeesalary(33333.3);
    e3.display();
    
}