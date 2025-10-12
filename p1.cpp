#include <iostream>
using namespace std;
class Student {
public:
    string name;
    int rollno;
    float marks;
public:
    void display() {
       cout<<"Name : " << name << "\n "<< "rollno : " << rollno << "\n " << "marks : " << marks << endl;
    }
};
int main() {

    Student s1;
    s1.name = "ayesha";
    s1.rollno = 23;
    s1.marks = 90.2;
    s1.display();
}
