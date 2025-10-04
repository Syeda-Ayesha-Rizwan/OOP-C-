#include <iostream>
using namespace std;
class Product{
    public:
    string productname;
    int productid;
    double price;
Product(string name, int id, double pr) {
        productname = name;
        productid = id;
        price = pr;
    }

    void displayProduct() {
        cout<<"Product id: "<<productid<< endl;
        cout<<"Name: "<<productname<<endl;
        cout<<"Price: Rs. "<<price<<endl;
     }
};
class customer{
    public:
    string customername;
    int customerid;
    string cart;
    
};
class order{

};
class Shoppingcart{
void additem(Product){

}
}