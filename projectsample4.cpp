#include <iostream>
#include <string>
#include <windows.h> // For Sleep(ms)
using namespace std;

// ---------------- Vehicles ----------------
class Vehicle {
private:
    string id;
protected:
    string type;
public:
    Vehicle(string _id, string _type) : id(_id), type(_type) {}
    virtual void move() = 0; // Abstraction
    string getId() { return id; } // Encapsulation
    string getType() { return type; }
};

class Car : public Vehicle {
public:
    Car(string id_) : Vehicle(id_, "Car") {}
    void move() override { cout << getId() << "(Car)→ "; }
};

class Bus : public Vehicle {
public:
    Bus(string id_) : Vehicle(id_, "Bus") {}
    void move() override { cout << getId() << "(Bus)→ "; }
};

class Ambulance : public Vehicle {
public:
    Ambulance(string id_) : Vehicle(id_, "Ambulance") {}
    void move() override { cout << getId() << "(Amb)→ "; }
};

// ---------------- Signal ----------------
class Signal {
private:
    string state;
    int timer;
public:
    Signal() { state = "RED"; timer = 5; } // 5 steps
    void step() {
        timer--;
        if(timer <= 0){
            if(state == "RED") state = "GREEN";
            else state = "RED";
            timer = 5;
        }
    }
    string getState() { return state; }
    bool isGreen() { return state == "GREEN"; }
};

// ---------------- Road ----------------
class Road {
private:
    string name;
    Vehicle* vehicles[5]; // max 5 vehicles per road
    int vCount;
public:
    Road(string n) : name(n), vCount(0) {
        for(int i=0;i<5;i++) vehicles[i]=nullptr;
    }
    bool addVehicle(Vehicle* v){
        if(vCount >=5) return false;
        vehicles[vCount++] = v;
        return true;
    }
    void moveVehicles(Signal &s){
        if(s.isGreen()){
            for(int i=0;i<vCount;i++) vehicles[i]->move();
            cout << endl;
        } else {
            cout << "[RED] ";
            for(int i=0;i<vCount;i++) cout << vehicles[i]->getId() << " stops ";
            cout << endl;
        }
    }
    string getName() { return name; }
};

// ---------------- Traffic Controller ----------------
class TrafficController {
private:
    Road* roads[3];
    Signal signals[3];
    int roadCount;
public:
    TrafficController() : roadCount(0) {}
    void addRoad(Road* r) { if(roadCount<3) roads[roadCount++] = r; }
    void step(){
        for(int i=0;i<roadCount;i++){
            signals[i].step();
            cout << "Signal for " << roads[i]->getName() << " is " << signals[i].getState() << endl;
            roads[i]->moveVehicles(signals[i]);
        }
        cout << "-----------------------------\n";
    }
};

int main(){
    // Create Roads
    Road r1("Road-1"), r2("Road-2"), r3("Road-3");

    // Create Vehicles
    Car c1("C1"), c2("C2");
    Bus b1("B1");
    Ambulance a1("A1");

    // Add Vehicles to Roads
    r1.addVehicle(&c1); r1.addVehicle(&a1);
    r2.addVehicle(&c2);
    r3.addVehicle(&b1);

    // Traffic Controller
    TrafficController ctrl;
    ctrl.addRoad(&r1);
    ctrl.addRoad(&r2);
    ctrl.addRoad(&r3);

    // Simulation Loop
    for(int step=1; step<=20; step++){
        cout << "=== Step " << step << " ===\n";
        ctrl.step();
        Sleep(1000); // 1 sec delay
    }

    cout << "Simulation Finished!\n";
    return 0;
}
