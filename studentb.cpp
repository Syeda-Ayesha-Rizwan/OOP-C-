#include <iostream>
using namespace std;
class Student{
   public:
    string name;
    int rollno;
    float marks;
public:

   void setStudent(string n , int rn, float m){
    name = n;
    rollno = rn;
    marks= m;
}

    void displaystudent() {
    cout<<"name : "<< name <<endl;
    cout<<"roll no. : "<< rollno <<endl;
    cout<<"marks : "<<marks<<endl;

}
};
int main(){
    Student s1;
    string n;
    int rn;
    float m;
  cout<< "enter name , roll no , marks " << endl;
  cin>> n >>rn >>m ;
s1.setStudent(n , rn , m);
s1.displaystudent();

}