#include <iostream>
using namespace std;

class Product {
private:
    string productName;
    int productID;
    double price;

public:
    Product() {
        productName = "";
        productID = 0;
        price = 0.0;
    }

    Product(string name, int id, double p) {
        productName = name;
        productID = id;
        price = p;
    }

    void setProduct(string name, int id, double p) {
        productName = name;
        productID = id;
        price = p;
    }

    string getName() { return productName; }
    int getID() { return productID; }
    double getPrice() { return price; }

    void displayProduct() {
        cout << "Product Name: " << productName << endl;
        cout << "Product ID: " << productID << endl;
        cout << "Price: " << price << endl;
    }
};

class ShoppingCart {
private:
    Product products[10]; // Max 10 products allowed
    int productCount;

public:
    ShoppingCart() {
        productCount = 0;
    }

    void addProduct(Product p) {
        if (productCount < 10) {
            products[productCount] = p;
            productCount++;
            cout << "Product added to cart.\n";
        } else {
            cout << "Cart is full!" << endl;
        }
    }

    void viewCart() {
        if (productCount == 0) {
            cout << "Cart is empty.\n";
        } else {
            for (int i = 0; i < productCount; i++) {
                cout << "Product " << i + 1 << ":\n";
                products[i].displayProduct();
                cout << endl;
            }
        }
    }

    double calculateTotal() {
        double total = 0;
        for (int i = 0; i < productCount; i++) {
            total += products[i].getPrice();
        }
        return total;
    }
};

class Customer {
private:
    string customerName;
    int customerID;
    ShoppingCart cart;

public:
    Customer(string name, int id) {
        customerName = name;
        customerID = id;
    }

    ShoppingCart& getCart() {
        return cart;
    }

    void displayCustomer() {
        cout << "Customer Name: " << customerName << endl;
        cout << "Customer ID: " << customerID << endl;
    }
};

class Order {
private:
    int orderID;
    Product orderProducts[10];
    int productCount;
    double totalAmount;

public:
    Order(int id) {
        orderID = id;
        productCount = 0;
        totalAmount = 0;
    }

    void addProductToOrder(Product p) {
        if (productCount < 10) {
            orderProducts[productCount] = p;
            productCount++;
        }
    }

    void calculateTotal() {
        totalAmount = 0;
        for (int i = 0; i < productCount; i++) {
            totalAmount += orderProducts[i].getPrice();
        }
    }

    void displayOrder() {
        cout << "\nOrder ID: " << orderID << endl;
        cout << "Products in Order:\n";
        for (int i = 0; i < productCount; i++) {
            orderProducts[i].displayProduct();
            cout << endl;
        }
        cout << "Total Amount: " << totalAmount << endl;
    }
};

int main() {
    Product p1("Laptop", 1, 80000);
    Product p2("Mouse", 2, 1200);

    Customer c("Ayesha", 101);
    c.getCart().addProduct(p1);
    c.getCart().addProduct(p2);

    cout << "\n--- Cart Details ---\n";
    c.getCart().viewCart();
    cout << "Cart Total: " << c.getCart().calculateTotal() << endl;

    Order o(5001);
    o.addProductToOrder(p1);
    o.addProductToOrder(p2);
    o.calculateTotal();
    o.displayOrder();

    return 0;
}
