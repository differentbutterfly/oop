#include <iostream>
#include <iomanip> // For setw
using namespace std;

class student {
    string name, Clas, b_grp, dob, address;
    int *roll, div, mobile, liscence;

public:
    // Constructor
    student() {
        roll = new int(7); // Allocate memory and initialize roll number
        name = "Default";
        div = 7;
        Clas = "SE";
        b_grp = "A+";
        dob = "1699-06 -09";
        address = "mars";
        mobile = 69696969;
        liscence = 336699;
    }

    // Copy Constructor
    student(student &s) {
        roll = new int(*s.roll); // Deep copy for roll
        name = s.name;
        div = s.div;
        Clas = s.Clas;
        b_grp = s.b_grp;
        dob = s.dob;
        address = s.address;
        mobile = s.mobile;
        liscence = s.liscence;
    }

    // Destructor
    ~student() {
        delete roll; // Free dynamically allocated memory
    }

    // Input Data
    void getdata() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter class: ";
        cin >> Clas;

        cout << "Enter blood group: ";
        cin >> b_grp;

        cout << "Enter date of birth (DD/MM/YYYY): ";
        cin.ignore();
        getline(cin, dob);

        cout << "Enter address (city): ";
        cin.ignore();
        getline(cin, address);

        cout << "Enter roll number: ";
        cin >> *roll; // Accessing the value of roll

        cout << "Enter division: ";
        cin >> div;

        cout << "Enter mobile number: ";
        cin >> mobile;

        cout << "Enter licence number: ";
        cin >> liscence;
    }

    // Static Header
    static inline void header() {
        cout << left << setw(15) << "NAME" << setw(10) << "CLASS" << setw(15)
             << "BLOOD GROUP" << setw(15) << "DATE OF BIRTH" << setw(20)
             << "ADDRESS(CITY)" << setw(10) << "ROLL.NO" << setw(10)
             << "DIVISION" << setw(15) << "MOBILE NUMBER" << setw(15)
             << "LICENCE NUMBER" << "\n";
    }

    // Display Data
    void display() {
        cout << left << setw(15) << name << setw(10) << Clas << setw(15)
             << b_grp << setw(15) << dob << setw(20) << address << setw(10)
             << *roll << setw(10) << div << setw(15) << mobile << setw(15)
             << liscence << "\n";
    }

    // Friend Class Declaration
    friend class teacher;
};

class teacher {
public:
    void show(student &s) {
        cout << "Name: " << s.name << endl;
        cout << "Roll No: " << *(s.roll) << endl; // Correctly accessing roll value
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    student s[n]; // Array of student objects
    for (int i = 0; i < n; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        s[i].getdata();
    }

    // Display Header and Student Information
    student::header();
    for (int i = 0; i < n; i++) {
        s[i].display();
    }

    // Demonstrating friend class
    student s1;
    teacher t;
    cout << "\nOutput of friend class:\n";
    t.show(s1);

    // Demonstrating default constructor
    cout << "\nOutput of default constructor:\n";
    student::header();
    s1.display();

    // Demonstrating copy constructor
    student s3(s1);
    cout << "\nOutput of copy constructor:\n";
    student::header();
    s3.display();

    return 0;
}
