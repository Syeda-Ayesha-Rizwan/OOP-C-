#include <iostream>
using namespace std;
string universityname = "shu ";
class Course{
    private:
    string coursename;
    int coursecode;

public:
    void setcourse(string cname , int ccode){
        coursename = cname;
        coursecode = ccode;
    }
    void displaycourse(){
    cout<<"course name is : "<<coursename<<endl;
    cout<<"course code is : "<<coursecode<<endl;
}

};
class department{
   string departmentname;
   int numcourses;
    Course courses[10];
public:
    void setdepartment(string dname , int n){
    departmentname = dname;
    numcourses = n;

}
    void displaydepartment(){
    cout<<"department name is : "<<departmentname<<endl;
    cout<<"number of courses is : "<<numcourses<<endl;
    for(int i=0 ; i<numcourses ; i++){
        courses[i].displaycourse();
    }
}};
class faculty{
   string facultyname;
   int numdepartments;
    department departments[10];
public:
   void setfaculty(string fname , int n){
       facultyname = fname;
       numdepartments = n;
    }
    void displayfaculty(){
        cout<<"faculty name is : "<<facultyname<<endl;
        cout<<"number of departments is : "<<numdepartments<<endl;
        for(int i=0 ; i<numdepartments ; i++){
            departments[i].displaydepartment();
        }
    }
};
int main(){
    
}