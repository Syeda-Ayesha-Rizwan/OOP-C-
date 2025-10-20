#include <iostream>
using namespace std;
class Student{
public:
string name;
void display(){
    cout << "name : "<< name << endl;

}
Student(){
    name = "unknown";

}
Student(string name ){
    this-> name = name ;

}
};
int main(){
    Student s1("ayesha ");
    Student s2;
    s1.display();
    s2.display();
}
