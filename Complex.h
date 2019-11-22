/*
Name: Gregory Litman-Navarro
Class: CECS 282
Instructor: Minhthong Nguyen
Purpose of the program:
Last updated:
*/

#ifndef ASSIGNMENT3_COMPLEX_H
#define ASSIGNMENT3_COMPLEX_H

#include <string>
using namespace std;

class Complex
{
public:
    Complex();
    Complex(int r, int i, int d);
    int re; //real part of a complex number
    int im; //imaginary part of a complex number
    int dem; //denominator part of a complex number
    // TODO: consider adding a function"reduce(int factor)"
    //      that checks if it can reduce all components by the factor,
    //      and, if so, reduces all three by that factor
    // TODO: consider adding a function that takes a complex number, or two,
    //      and multiplies each component by -1 if necessary
    string toString() const;
    //Format [re + imi]/dem

};

//Overloading operator for easy arithmetic
Complex operator+(Complex a, Complex b);
Complex operator-(Complex a, Complex b);
Complex operator*(Complex a, Complex b);
Complex operator/(Complex a, Complex b);
//ostream& operator<< (ostream& stream, Complex a); // FIXME: CLION says this is not valid for x86 architecture =>>> linker fails
//Find gcd and lcm to reduce fraction and add fraction
int gcd(int a, int b);
int lcm(int a, int b);


#endif //ASSIGNMENT3_COMPLEX_H
