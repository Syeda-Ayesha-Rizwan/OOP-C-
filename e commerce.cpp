#include <iostream>
using namespace std;

class Product{
    string name;
    int id;
    double price;
public:
   
    Product(string n, int i, double p) { 
	 name=n;
	 id=i;
	 price=p; 
	 
 }
    void displayProduct() {
        cout << "Product ID: " << productID << endl;
        cout << "Name: " << productName << endl;
        cout << "Price: Rs. " << price <<endl;
}
    };

class Order {
    int orderID;
    double total;
    Product p1, p2, p3;
public:
    Order(int id, Product a, Product b, Product c) {
        orderID = id;
        p1=a; 
		p2=b; 
		p3=c;
        total = p1.getPrice() + p2.getPrice() + p3.getPrice();
    }
    void show() {
        cout<<"Order #"<<orderID<<"\n";
        cout<<p1.getName()<<" Rs."<<p1.getPrice()<<"\n";
        cout<<p2.getName()<<" Rs."<<p2.getPrice()<<"\n";
        cout<<p3.getName()<<" Rs."<<p3.getPrice()<<"\n";
        cout<<"Total Rs."<<total<<"\n";
    }
};

class ShoppingCart {
    Product a,b,c;
    int count;
public:
    ShoppingCart() {
	 count=0; 
	 }
    void addItem(Product p) {
        if(count==0) a=p;
        else if(count==1) b=p;
        else if(count==2) c=p;
        count++;
    }
    Order checkout(int id) {
	 return Order(id,a,b,c);
	  }
};

class Customer {
    string name;
    int id;
    ShoppingCart cart;
public:
    Customer(string n,int i) {
	 name=n; id=i; 
	 }
    ShoppingCart& getCart() {
	 return cart; 
	 }
};

int main() {
    Product p1("chocolates",1,2000);
    Product p2("jellies",2,1000);
    Product p3("juices",3,500);

    Customer c1("Ayesha",1);

    c1.getCart().addItem(p1);
    c1.getCart().addItem(p2);
    c1.getCart().addItem(p3);

    Order o1 = c1.getCart().checkout(1001);
    o1.show();

    return 0;
}

