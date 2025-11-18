#include <iostream>
using namespace std;

class Tollbooth {
private:
    unsigned int totalCars;
    double totalAmount;

public:
    Tollbooth() {
        totalCars = 0;
        totalAmount = 0;
    }

    void payingCar() {
        totalCars++;
        totalAmount += 0.50;
    }

    void noPayCar() {
        totalCars++;
    }

    void display() {
        cout << "\nTotal cars passed: " << totalCars << endl;
        cout << "Total amount collected: $" << totalAmount << endl;
    }
};

int main() {
    Tollbooth booth;
    char choice;

    cout << "Press 'p' for paying car\n";
    cout << "Press 'n' for non-paying car\n";
    cout << "Press 'e' to exit\n";

    while (true) {
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 'p') {
            booth.payingCar();
        }
        else if (choice == 'n') {
            booth.noPayCar();
        }
        else if (choice == 'e') {
            booth.display();
            break;
        }
        else {
            cout << "Invalid input! Try again.";
        }
    }
}
