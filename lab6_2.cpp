#include <iostream> 
using namespace std;
/* Consider classes: Head of Department Co-ordinator Faculties Students Perform Multilevel In
heritance in which information is passed on from the Head of Department to the next class.
 You can assume any scenario as per your wish. Each class must contain atleast 4 fields, a pa
rameterized constructor for information input from the user and a DisplayInformation func
tion*/
class HOD{
    private:
    string name ;
    string qualification;
    string department;
    int age ;
    public:
    HOD(string name , string qualification , string department , int age ){
        this-> name = name ;
        this-> qualification = qualification ;
        this-> department = department ;
        this-> age = age ;
    }
    void display(){
        cout<< "=====HOD====="<<endl;
        cout <<"name : "<< name << endl;
        cout << "qualification : "<< qualification <<endl;
        cout << " department : "<< department <<endl;
        cout << "age: "<< age <<endl;
     }

};

class Cordinator: public HOD{
private :
 string name ;
 string degree ;
 string specialization;
 public:
Cordinator(string name , string degree , string specialization , string hodname , string qualification , string department , int age ):HOD(hodname , qualification , department , age ) {
    this->name = name;
    this->degree= degree ;
    this->specialization = specialization;
}
void display(){
    cout <<"=====Co-ordinator====="<<endl;
    cout<< "name : " << name   <<endl;
    cout<< "degree : " << degree <<endl;
    cout<< "specialization" << specialization <<endl;

}
};
/*
class Faculty: public cordinator{

};
class Student: public cordinator{

};
*/
int main(){
HOD h1("Razia" , "computer science" , "phd" ,30  );
h1.display();
Cordinator c1("meerub  " , "comp eng" , "IT " , "Razia" , "computer science" , "phd" ,30  );
c1.display();
}