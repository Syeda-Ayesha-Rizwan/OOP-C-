#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_ROADS = 3;
const int MAX_VEHICLES = 10;
const int SIM_STEPS = 20;
const int SIGNAL_INTERVAL = 5;

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
    virtual int priority() { return 1; } // Polymorphism
};

class Car : public Vehicle {
public:
    Car(string id_) : Vehicle(id_, "Car") {}
    void move() override { cout << getId() << " (Car) moves normally.\n"; }
};

class Bus : public Vehicle {
public:
    Bus(string id_) : Vehicle(id_, "Bus") {}
    void move() override { cout << getId() << " (Bus) moves slowly.\n"; }
};

class Ambulance : public Vehicle {
public:
    Ambulance(string id_) : Vehicle(id_, "Ambulance") {}
    void move() override { cout << getId() << " (Ambulance) moves with priority!\n"; }
    int priority() override { return 10; }
};

// ---------------- Signal ----------------
class Signal {
private:
    string state; // RED / GREEN
    int timer;
public:
    Signal() { state = "RED"; timer = SIGNAL_INTERVAL; }
    void step() {
        timer--;
        if (timer <= 0) {
            if (state == "RED") state = "GREEN";
            else state = "RED";
            timer = SIGNAL_INTERVAL;
        }
    }
    string getState() { return state; }
    bool isGreen() { return state == "GREEN"; }
};

// ---------------- Road ----------------
class Road {
private:
    string name;
    Vehicle* queue[MAX_VEHICLES];
    int qCount;
public:
    Road(string n) : name(n), qCount(0) {
        for (int i=0;i<MAX_VEHICLES;i++) queue[i] = nullptr;
    }
    bool addVehicle(Vehicle* v) {
        if(qCount >= MAX_VEHICLES) return false;
        queue[qCount++] = v;
        return true;
    }
    void moveVehicles(Signal &s) {
        if(s.isGreen()) {
            for(int i=0;i<qCount;i++){
                queue[i]->move();
            }
        } else {
            for(int i=0;i<qCount;i++){
                cout << queue[i]->getId() << " stops at RED signal.\n";
            }
        }
    }
    string getName() { return name; }
};

// ---------------- Traffic Controller ----------------
class TrafficController {
private:
    Road* roads[MAX_ROADS];
    Signal signals[MAX_ROADS];
    int roadCount;
public:
    TrafficController() : roadCount(0) {}
    void addRoad(Road* r) { if(roadCount<MAX_ROADS) roads[roadCount++] = r; }
    void step() {
        for(int i=0;i<roadCount;i++){
            signals[i].step();
            cout << "Signal for " << roads[i]->getName() << " is " << signals[i].getState() << endl;
            roads[i]->moveVehicles(signals[i]);
        }
        cout << "-----------------------------\n";
    }
};

int main() {
    srand(time(0));
    
    // Create roads
    Road r1("Road-1"), r2("Road-2"), r3("Road-3");
    
    // Create vehicles
    Car c1("C1"); Car c2("C2");
    Bus b1("B1");
    Ambulance a1("A1");
    
    // Add vehicles to roads
    r1.addVehicle(&c1); r1.addVehicle(&a1);
    r2.addVehicle(&c2);
    r3.addVehicle(&b1);
    
    // Controller
    TrafficController ctrl;
    ctrl.addRoad(&r1);
    ctrl.addRoad(&r2);
    ctrl.addRoad(&r3);
    
    // Simulation loop
    for(int step=1; step<=SIM_STEPS; step++){
        cout << "=== Step " << step << " ===\n";
        ctrl.step();
    }
    
    cout << "Simulation Finished!\n";
    return 0;
}
