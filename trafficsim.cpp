#include <iostream>
using namespace std;

#define MAX_CARS 10   // Maximum cars per road
#define MAX_ROADS 5   // Maximum roads in system

// ==================== Signal Class ====================
class Signal {
private:
    string state; // RED, YELLOW, GREEN
    int duration; // Time for which signal stays in this state
public:
    Signal() { state = "RED"; duration = 0; }
    Signal(string s, int d) { state = s; duration = d; }

    void changeState(string s) { state = s; }
    string getState() { return state; }
    int getDuration() { return duration; }
};

// ==================== Car Class ====================
class Car {
private:
    string name;
public:
    Car() { name = "Unnamed"; }
    Car(string n) { name = n; }

    void move(Signal &signal) {
        if(signal.getState() == "RED")
            cout << name << " stopped.\n";
        else if(signal.getState() == "YELLOW")
            cout << name << " slows down.\n";
        else
            cout << name << " moves.\n";
    }

    string getName() { return name; }
};

// ==================== Road Class ====================
class Road {
private:
    string name;
    Car cars[MAX_CARS];
    int carCount;
    Signal signal;
public:
    Road() { carCount = 0; name = "Unnamed Road"; }
    Road(string n, Signal s) {
        name = n;
        signal = s;
        carCount = 0;
    }

    void addCar(Car c) {
        if(carCount < MAX_CARS)
            cars[carCount++] = c;
        else
            cout << "Road is full! Cannot add more cars.\n";
    }

    void updateTraffic() {
        cout << "Road: " << name << " | Signal: " << signal.getState() << endl;
        for(int i = 0; i < carCount; i++) {
            cars[i].move(signal);
        }
        cout << endl;
    }

    void changeSignal(string newState) {
        signal.changeState(newState);
    }

    Signal& getSignal() { return signal; }
};

// ==================== TrafficSystem Class ====================
class TrafficSystem {
private:
    Road roads[MAX_ROADS];
    int roadCount;
public:
    TrafficSystem() { roadCount = 0; }

    void addRoad(Road r) {
        if(roadCount < MAX_ROADS)
            roads[roadCount++] = r;
        else
            cout << "Maximum roads reached!\n";
    }

    void updateAll() {
        for(int i = 0; i < roadCount; i++)
            roads[i].updateTraffic();
    }

    void changeRoadSignal(int roadIndex, string state) {
        if(roadIndex >= 0 && roadIndex < roadCount)
            roads[roadIndex].changeSignal(state);
        else
            cout << "Invalid road index!\n";
    }
};

// ==================== Main Function ====================
int main() {
    // Create signals
    Signal s1("RED", 10);
    Signal s2("GREEN", 15);

    // Create roads
    Road road1("Main Street", s1);
    Road road2("2nd Avenue", s2);

    // Add cars to roads
    road1.addCar(Car("Car1"));
    road1.addCar(Car("Car2"));
    road2.addCar(Car("Car3"));
    road2.addCar(Car("Car4"));

    // Create traffic system
    TrafficSystem ts;
    ts.addRoad(road1);
    ts.addRoad(road2);

    // Initial traffic
    cout << "Initial Traffic Status:\n";
    ts.updateAll();

    // Change signals
    ts.changeRoadSignal(0, "GREEN");
    ts.changeRoadSignal(1, "RED");
    cout << "Signals updated...\n\n";

    // Update traffic after signal change
    ts.updateAll();

    return 0;
}
