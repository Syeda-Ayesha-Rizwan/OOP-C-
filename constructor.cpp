#include <iostream>
using namespace std;
class student{
    string name;
    int rollno;
    public:
    student(string name , int rollno){
        this->name = name;
        this->rollno = rollno;

    }
    void display(){
        cout<<"name: "<< name << endl;
        cout << "roll no:" << rollno << endl;
     }

};
int main(){
    student s1("ayesha " , 123 );
s1.display();
    return 0;
}