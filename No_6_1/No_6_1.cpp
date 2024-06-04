#include <iostream>
#include <windows.h>
// x = a + b*i

using namespace std;

class Complex {
private:
    double real; //a
    double imag; //b*i

public:
    
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }
    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real); 
        //(a,b)*(c,d)=(a*c-b*d,a*d+b*c)
    }
    void Display() {
        cout << "(" << real << ", " << imag << ")" << endl;
    }
    void Read() {
        cout << "Введіть дійсне число: ";
        cin >> real;
        cout << "Введіть уявне число: ";
        cin >> imag;
    }

};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Complex c1(3, 4);
    Complex c2(1, 2);
    cout << "Комплексні числа за замовчуванням: " << endl;
    cout << "c1: ";
    c1.Display();
    cout << "c2: ";
    c2.Display();

    Complex sum = c1 + c2;
    cout << "Сума: ";
    sum.Display();
    Complex difference = c1 - c2;
    cout << "Різниці: ";
    difference.Display();
    Complex product = c1 * c2;
    cout << "Множенння: ";
    product.Display();
    Complex c3;
    c3.Read();
    cout << "Введене комплексне число: ";
    c3.Display();
}
