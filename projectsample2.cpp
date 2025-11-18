#include <iostream>
#include <string>
using namespace std;

// ================================
// Abstract Class (Abstraction)
// ================================
class Vehicle {
protected:
    string name;
public:
    Vehicle(string n) { name = n; }
    virtual void move(string state) = 0; // polymorphism
};

// ================================
// Inheritance + Polymorphism
// ================================
class Car : public Vehicle {
public:
    Car(string n) : Vehicle(n) {}
    void move(string state) {
        if(state == "RED") cout << name << " (Car) stops.\n";
        else cout << name << " (Car) moves.\n";
    }
};

class Bus : public Vehicle {
public:
    Bus(string n) : Vehicle(n) {}
    void move(string state) {
        if(state == "RED") cout << name << " (Bus) stops.\n";
        else cout << name << " (Bus) moves.\n";
    }
};

class Bike : public Vehicle {
public:
    Bike(string n) : Vehicle(n) {}
    void move(string state) {
        if(state == "RED") cout << name << " (Bike) stops.\n";
        else cout << name << " (Bike) moves.\n";
    }
};

// ================================
// Encapsulation: SIGNAL CLASS
// ================================
class Signal {
private:
    string state;
public:
    Signal() { state = "RED"; }

    void setState(string s) { state = s; }
    string getState() { return state; }
    void show() { cout << "\nSignal: " << state << endl; }
};

// ================================
// ROAD CLASS
// ================================
class Road {
private:
    Vehicle* v[5];
    int count;
    string name;
    Signal signal;

public:
    Road(string n) {
        name = n;
        count = 0;
    }

    void addVehicle(Vehicle* x) {
        v[count] = x;
        count++;
    }

    void changeSignal(string s) {
        signal.setState(s);
        signal.show();
        cout << "Traffic on " << name << ":\n";
        for(int i=0; i<count; i++)
            v[i]->move(signal.getState());
    }
};

// ================================
// MAIN PROGRAM (No infinite loop)
// ================================
int main() {

    Road r("Main Road");

    Car c1("Car A");
    Bus b1("Bus B");
    Bike bk1("Bike C");

    r.addVehicle(&c1);
    r.addVehicle(&b1);
    r.addVehicle(&bk1);

    cout << "===== TRAFFIC CONTROL SIMULATION START =====\n";

    r.changeSignal("GREEN");
    cout << "\n(5 seconds passed...)\n";

    r.changeSignal("YELLOW");
    cout << "\n(2 seconds passed...)\n";

    r.changeSignal("RED");
    cout << "\n(5 seconds passed...)\n";

    cout << "\nSimulation Ended.\n";

    return 0;
}
