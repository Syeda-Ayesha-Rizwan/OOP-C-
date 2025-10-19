#include <iostream>
using namespace std;
class Student{
    public:
string name ;
int rollno;
Student(){
    name= "unknown";
    rollno = 0;
}
Student(string name ){
  this -> name = name;
}
Student(string name  , int rollno){
   this->name  = name;
   this-> rollno = rollno;
}
  void display(){
    cout<< name <<  endl;
    cout << rollno << endl;


  
}
};
int main(){
    Student s1;
    Student s2("zara" , 22);
    s1.display();
    s2.display();
}
