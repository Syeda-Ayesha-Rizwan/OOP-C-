#include <iostream>
#include <string>
using namespace std;

// ==================================================
// Utility: ID Generator
// ==================================================
class IDGenerator {
    static int counter;
public:
    static int generateID() {
        return ++counter;
    }
};
int IDGenerator::counter = 0;


// ==================================================
// Abstract Display Manager (GUI Bridge)
// ==================================================
class DisplayManager {
public:
    virtual void showSignal(string road, string color) = 0;
    virtual void showVehicleAction(string vehicle, string action) = 0;
    virtual void showRoadUpdate(string road, string msg) = 0;
};

// ==================================================
// Console Display (temporary GUI)
// ==================================================
class ConsoleDisplay : public DisplayManager {
public:
    void showSignal(string road, string color) {
        cout << "[" << road << "] SIGNAL: " << color << endl;
    }

    void showVehicleAction(string vehicle, string action) {
        cout << vehicle << " -> " << action << endl;
    }

    void showRoadUpdate(string road, string msg) {
        cout << "[" << road << "] " << msg << endl;
    }
};


// ==================================================
// CLASS: Signal (State Machine)
// ==================================================
class Signal {
private:
    string state;
    int timer;
    int cycle;

public:
    Signal() {
        state = "RED";
        timer = 5;
        cycle = 0;
    }

    string getState() const { return state; }

    void update() {
        cycle++;

        if (cycle == 5) state = "GREEN";
        if (cycle == 10) state = "YELLOW";
        if (cycle == 12) {
            state = "RED";
            cycle = 0;
        }
    }
};


// ==================================================
// ABSTRACT Vehicle
// ==================================================
class Vehicle {
protected:
    string name;
    int id;

public:
    Vehicle(string n) {
        name = n;
        id = IDGenerator::generateID();
    }

    virtual void act(Signal s, DisplayManager* d) = 0;

    string getTitle() {
        return name + " #" + to_string(id);
    }
};


// ==================================================
// Car
// ==================================================
class Car : public Vehicle {
public:
    Car(string n) : Vehicle(n) {}

    void act(Signal s, DisplayManager* d) {
        if (s.getState() == "RED")
            d->showVehicleAction(getTitle(), "stopping at red light.");
        else if (s.getState() == "YELLOW")
            d->showVehicleAction(getTitle(), "slowing down.");
        else
            d->showVehicleAction(getTitle(), "moving smoothly.");
    }
};


// ==================================================
// Bus
// ==================================================
class Bus : public Vehicle {
public:
    Bus(string n) : Vehicle(n) {}

    void act(Signal s, DisplayManager* d) {
        if (s.getState() == "RED")
            d->showVehicleAction(getTitle(), "waiting at red.");
        else if (s.getState() == "YELLOW")
            d->showVehicleAction(getTitle(), "preparing to stop.");
        else
            d->showVehicleAction(getTitle(), "moving with caution.");
    }
};


// ==================================================
// Truck
// ==================================================
class Truck : public Vehicle {
public:
    Truck(string n) : Vehicle(n) {}

    void act(Signal s, DisplayManager* d) {
        if (s.getState() == "RED")
            d->showVehicleAction(getTitle(), "halting heavy load.");
        else if (s.getState() == "YELLOW")
            d->showVehicleAction(getTitle(), "braking slowly.");
        else
            d->showVehicleAction(getTitle(), "rolling forward.");
    }
};


// ==================================================
// Lane (Holds Multiple Vehicles)
// ==================================================
class Lane {
private:
    string laneName;
    Vehicle* vehicles[10];
    int count;

public:
    Lane(string name) {
        laneName = name;
        count = 0;
    }

    void addVehicle(Vehicle* v) {
        if (count < 10) vehicles[count++] = v;
    }

    void update(Signal s, DisplayManager* d) {
        for (int i = 0; i < count; i++) {
            vehicles[i]->act(s, d);
        }
    }
};


// ==================================================
// Road (Has Multiple Lanes + One Signal)
// ==================================================
class Road {
private:
    string name;
    Lane* lanes[3];
    Signal signal;
    int laneCount;
    DisplayManager* display;

public:
    Road(string n, DisplayManager* d) {
        name = n;
        laneCount = 0;
        display = d;
    }

    void addLane(Lane* lane) {
        if (laneCount < 3) lanes[laneCount++] = lane;
    }

    void update() {
        signal.update();
        display->showSignal(name, signal.getState());

        for (int i = 0; i < laneCount; i++) {
            lanes[i]->update(signal, display);
        }

        display->showRoadUpdate(name, "---------------------------");
    }
};


// ==================================================
// Traffic Controller (Controls All Roads)
// ==================================================
class TrafficController {
private:
    Road* roads[5];
    int count;

public:
    TrafficController() { count = 0; }

    void addRoad(Road* r) {
        if (count < 5) roads[count++] = r;
    }

    void start(int cycles) {
        for (int i = 1; i <= cycles; i++) {
            cout << "\n========= GLOBAL CYCLE " << i << " =========\n\n";
            for (int r = 0; r < count; r++) {
                roads[r]->update();
            }
        }
    }
};


// ==================================================
// MAIN
// ==================================================
int main() {
    ConsoleDisplay gui;

    TrafficController controller;

    Road r1("Main Road", &gui);
    Road r2("Airport Road", &gui);

    Lane L1("Lane 1"); 
    Lane L2("Lane 2");

    L1.addVehicle(new Car("Car"));
    L1.addVehicle(new Bus("Bus"));
    L2.addVehicle(new Truck("Truck"));

    r1.addLane(&L1);
    r1.addLane(&L2);

    controller.addRoad(&r1);
    controller.addRoad(&r2);

    controller.start(5);

    return 0;
}
