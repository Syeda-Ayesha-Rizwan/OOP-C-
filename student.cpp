#include <iostream>
using namespace std;
class Student{
   public:
    int roll_no;
    string name;
public:
    void display(){
        cout<<roll_no;
        cout<<name; 
}

};
int main(){
    Student s1;
    s1.name = "John";
    s1.roll_no = 101;
    s1.display();
    return 0;
}