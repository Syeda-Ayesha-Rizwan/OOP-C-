#include <iostream>
using namespace std;
class Student {
    private:
    int id;
    string firstname;
    string lastname ;
    int contact;
    string city;
    string dob;
    int semester;
    int numofcourses;
    public:

void getdetails(){
cout <<"Enter details: "<< endl;
cout <<"id : "<< endl;
cin>> id;
cout <<"Firstname: "<< endl;
cin>> firstname;

cout <<"lastname : "<< endl;
cin>> lastname;

cout <<"contact : "<< endl;
cin>> contact;

cout <<"city: "<< endl;
cin>>city ;

cout <<"dob: "<< endl;
cin>> dob;

cout <<"semester: "<< endl;
cin>> semester;

cout <<"numofcourses: "<< endl;
cin>> numofcourses;

}
void  display(){
cout<<" =====Student Details====\n"<<endl;
cout <<"Id : "<< id<<endl;
cout <<"Firstname: "<<firstname<< endl;
cout <<"Lastname : "<<lastname<< endl;
cout <<"Contact : "<<contact<< endl;
cout <<"City: "<< city<<endl;
cout <<"DOB: "<<dob<< endl;
cout <<"Semester: "<<semester<< endl;
cout <<"Num Of Courses: "<<numofcourses<< endl;

    }
};
int main(){
   
    Student s1;
    s1.getdetails();
    s1.display();
}
