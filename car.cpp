#include <iostream>
using namespace std;
class Car{
private:
string company ;
string model ;
int year ;
public:
void setcompany(string c ){
    company = c;
}
void setmodel(string m ){
    model = m;
}
void setyear(int y ){
    year = y;     
}
string getcompany(){
    return company;
}
string getmodel(){
    return model;
}
int getyear(){
    return year;
}
};
int main() {
    Car car1;
    car1.setcompany("Toyota");
    car1.setmodel("Corolla");
    car1.setyear(2020);
    cout << "Car 1: " << car1.getcompany() << " " << car1.getmodel() << " " << car1.getyear() << endl;

    Car car2;
    car2.setcompany("Honda");
    car2.setmodel("Civic");
    car2.setyear(2019);
    cout << "Car 2: " << car2.getcompany() << " " << car2.getmodel() << " " << car2.getyear() << endl;

    return 0;
}