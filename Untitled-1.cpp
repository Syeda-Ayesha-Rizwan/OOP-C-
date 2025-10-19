#include <iostream>
using namespace std;

class Car{
    public:
    string brand;
    int model;
    float price;


public :
 Car(string brand , int model , float price ){
    this-> brand = brand ;
    this-> model = model ;
    this-> price = price ;

}
void display(){
cout << "brand : " <<brand  << "model :" << model <<"price : " << price <<endl;
}
};

int main(){
    Car c1("honda " , 2022 , 44.4 );
    c1.display();

}