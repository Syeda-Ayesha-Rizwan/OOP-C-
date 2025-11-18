#include <iostream>
using namespace std;
class CEO{
    private:
    string name ;
    int age;
    string company ;
    double salary;
    public:
    CEO(string name , int age , string company , float salary){
        this -> name = name;
        this -> age = age;
        this-> company = company ;
        this-> salary = salary ;

    }
   virtual void display(){
        cout <<"name: "<< name<<endl;
        cout <<"age : "<<age <<endl;
        cout <<"company : "<< company <<endl;
        cout <<"salary : "<<salary  <<endl;
    }

};
class Manager: public CEO{
private:
    int leavesallowed ;
    string team;
public:
Manager(int leavesallowed , string team , string name , int age , string company , double salary ): CEO(name , age , company , salary){
    this -> leavesallowed = leavesallowed;
    this -> team = team;

}
void display ()override{
    CEO::display();
    cout<<" leaves allowed  : "<< leavesallowed << endl;
    cout <<"team : "<< team <<endl;

}
};
class Employee: public CEO{
    private:
    string qualification;
    int workinghours;
    public:
    Employee(string qualification , int workinghours , string name , int age  , string company ,double salary): CEO(name , age , company , salary ){
        this-> qualification = qualification;
        this-> workinghours = workinghours;

    }
    void display(){
        CEO::display();
        cout<< "qualification : " << qualification << endl;
        cout<< "working hours : "<<workinghours <<endl;

    }

};


int main(){
CEO s1("ayesha " , 20 , "shu " , 100000);
s1.display();
Manager m1(1 , "team1", "wareesha " , 21, "bhu" , 22222.2);
m1.display();
Employee e1("software Engineering " , 2 , "Ayesha " , 20, " innolytics " , 10000000);
e1.display();

}