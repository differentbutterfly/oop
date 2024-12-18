#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int img;

public:
    // Default constructor
    Complex() {
        real = 0;
        img = 0;
    }

    // Overload + operator
    Complex operator+(Complex &c) {
        Complex result;
        result.real = real + c.real;
        result.img = img + c.img;
        return result;
    }

    // Overload * operator
    Complex operator*(Complex &c) {
        Complex result;
        result.real = (real * c.real) - (img * c.img);
        result.img = (real * c.img) + (img * c.real);
        return result;
    }

    // Overload >> operator
    friend istream &operator>>(istream &in, Complex &c1) {
        cout << "Enter real part: ";
        in >> c1.real;
        cout << "Enter imaginary part: ";
        in >> c1.img;
        return in;
    }

    // Overload << operator
    friend ostream &operator<<(ostream &out, const Complex &c1) {
        out << c1.real << " + " << c1.img << "i";
        return out;
    }
};

int main() {
    Complex c1, c2, c3;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1) Default constructor\n";
        cout << "2) Input complex numbers\n";
        cout << "3) Display complex numbers\n";
        cout << "4) Addition of complex numbers\n";
        cout << "5) Product of complex numbers\n";
        cout << "6) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Default complex number: " << c1 << endl;
                break;

            case 2:
                cout << "Enter 1st complex number:\n";
                cin >> c1;
                cout << "Enter 2nd complex number:\n";
                cin >> c2;
                break;

            case 3:
                cout << "1st complex number: " << c1 << endl;
                cout << "2nd complex number: " << c2 << endl;
                break;

            case 4:
                c3 = c1 + c2;
                cout << "Addition of complex numbers: " << c3 << endl;
                break;

            case 5:
                c3 = c1 * c2;
                cout << "Product of complex numbers: " << c3 << endl;
                break;

            case 6:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
