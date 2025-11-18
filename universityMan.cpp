#include <iostream>
#include <string>
using namespace std;

// ================= Base Class: HeadOfDepartment =================
class HeadOfDepartment {
private:
    string name;
    string department;
    string contact;
    string officeRoom;

public:
    // Parameterized constructor
    HeadOfDepartment(string n, string dep, string c, string office) {
        name = n;
        department = dep;
        contact = c;
        officeRoom = office;
    }

    // Display function (can be overridden)
    virtual void displayInformation() {
        cout << "\n--- Head of Department Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Contact: " << contact << endl;
        cout << "Office Room: " << officeRoom << endl;
    }
};

// ================= Derived Class: Coordinator =================
class Coordinator : public HeadOfDepartment {
private:
    string name;
    string contact;
    int assignedFaculty;
    string officeRoom;

public:
    Coordinator(string hodName, string dep, string hodContact, string hodOffice,
                string n, string c, int facultyCount, string office)
        : HeadOfDepartment(hodName, dep, hodContact, hodOffice) {
        name = n;
        contact = c;
        assignedFaculty = facultyCount;
        officeRoom = office;
    }

    void displayInformation() override {
        HeadOfDepartment::displayInformation(); // show HOD info
        cout << "\n--- Coordinator Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Contact: " << contact << endl;
        cout << "Assigned Faculty: " << assignedFaculty << endl;
        cout << "Office Room: " << officeRoom << endl;
    }
};

// ================= Derived Class: Faculty =================
class Faculty : public Coordinator {
private:
    string name;
    string contact;
    int coursesHandled;
    string officeRoom;

public:
    Faculty(string hodName, string dep, string hodContact, string hodOffice,
            string coordName, string coordContact, int facultyCount, string coordOffice,
            string n, string c, int courses, string office)
        : Coordinator(hodName, dep, hodContact, hodOffice, coordName, coordContact, facultyCount, coordOffice) {
        name = n;
        contact = c;
        coursesHandled = courses;
        officeRoom = office;
    }

    void displayInformation() override {
        Coordinator::displayInformation(); // show HOD + Coordinator info
        cout << "\n--- Faculty Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Contact: " << contact << endl;
        cout << "Courses Handled: " << coursesHandled << endl;
        cout << "Office Room: " << officeRoom << endl;
    }
};

// ================= Derived Class: Student =================
class Student : public Faculty {
private:
    string id;
    string firstName;
    string lastName;
    string contact;
    string city;
    string dob;
    int currentSemester;
    int noOfCourses;

public:
    // Constructor with default name "Unknown"
    Student(string hodName, string dep, string hodContact, string hodOffice,
            string coordName, string coordContact, int facultyCount, string coordOffice,
            string facName, string facContact, int courses, string facOffice,
            string studentId, string fName = "Unknown", string lName = "Unknown",
            string con = "", string c = "", string date = "",
            int sem = 1, int nCourses = 0)
        : Faculty(hodName, dep, hodContact, hodOffice, coordName, coordContact, facultyCount, coordOffice,
                  facName, facContact, courses, facOffice) {
        id = studentId;
        firstName = fName;
        lastName = lName;
        contact = con;
        city = c;
        dob = date;
        currentSemester = sem;
        noOfCourses = nCourses;
    }

    void displayInformation() override {
        Faculty::displayInformation(); // show HOD + Coordinator + Faculty info
        cout << "\n--- Student Details ---\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Contact: " << contact << endl;
        cout << "City: " << city << endl;
        cout << "DOB: " << dob << endl;
        cout << "Current Semester: " << currentSemester << endl;
        cout << "Number of Courses: " << noOfCourses << endl;
    }
};

// ================= Derived Class: Transcript =================
class Transcript : public Student {
private:
    float semesterGPA[8];  // assume max 8 semesters
    float cumulativeGPA;
    int totalSemesters;

public:
    Transcript(string hodName, string dep, string hodContact, string hodOffice,
               string coordName, string coordContact, int facultyCount, string coordOffice,
               string facName, string facContact, int courses, string facOffice,
               string studentId, string fName, string lName,
               string con, string c, string date, int sem, int nCourses,
               float gpas[], int semCount)
        : Student(hodName, dep, hodContact, hodOffice,
                  coordName, coordContact, facultyCount, coordOffice,
                  facName, facContact, courses, facOffice,
                  studentId, fName, lName, con, c, date, sem, nCourses) {
        totalSemesters = semCount;
        cumulativeGPA = 0;
        for (int i = 0; i < totalSemesters; i++) {
            semesterGPA[i] = gpas[i];
            cumulativeGPA += gpas[i];
        }
        cumulativeGPA /= totalSemesters; // calculate cumulative
    }

    void displayTranscript() {
        displayInformation(); // student info
        cout << "\n--- Transcript ---\n";
        for (int i = 0; i < totalSemesters; i++) {
            cout << "Semester " << (i + 1) << " GPA: " << semesterGPA[i] << endl;
        }
        cout << "Cumulative GPA: " << cumulativeGPA << endl;
    }
};

// ================= Main Function =================
int main() {
    // Example GPA array
    float gpas[4] = {3.5, 3.7, 3.8, 3.9};

    // Create Transcript object (all details passed)
    Transcript student1("Dr. Ahmed", "Computer Science", "HOD123", "H101",
                        "Mr. Bilal", "Coord456", 5, "C102",
                        "Dr. Sara", "Fac789", 3, "F201",
                        "S001", "Ayesha", "Khan", "0300123456", "Karachi",
                        "01-01-2005", 4, 5, gpas, 4);

    // Display full university system info + transcript
    student1.displayTranscript();

    return 0;
}

