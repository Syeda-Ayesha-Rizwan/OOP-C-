#include <iostream>
using namespace std;
class Person{
    private:
    string name ;
    int age;
    string country;
    public:
  void  setname(string n){
        name = n;

    }
    void setage(int a){
        age = a;
    }
    void setcountry(string c){
        country = c;
    }
    string getname(){
        return name;
    }
    int getage(){
        return age;
    }
    string getcountry(){
        return country;
    }
};
int main(){
    Person p1;
    p1.setname("ayesha");
    p1.setage(20);
    p1.setcountry("pakistan");
cout<< "name"<<p1.getname()<<endl;
cout<<p1.getage()<<endl;
cout<<p1.getcountry()<<endl;
    return 0;
}