/*
Name: Gregory Litman-Navarro
Class: CECS 282
Instructor: Minhthong Nguyen
Purpose of the program:
Last updated:
*/

#include "Complex.h"
#include <cmath>

/**
 * Default constructor for Complex number objects
 */
Complex::Complex()
{ // FIXME are these the right values to use for this
    re = 1; //real part of a complex number
    im = 1; //imaginary part of a complex number
    dem = 1; //denominator part of a complex number
}

/**
 * Constructor for Complex number objects.
 * If necessary, reformats the inputs for non-standard form.
 * @param r real part of a complex number
 * @param i imaginary part of a complex number
 * @param d denominator part of a complex number
 */
Complex::Complex(int r, int i, int d)
{
    // FIXME what if d is given in as zero???
    if (r < 0)
    {
        re = -1 * r;
        im = -1 * i;
        dem = -1 * d;
    }
    else
    {
        re = r;
        im = i;
        dem = d;
    }
}

/**
 * Generates a string representation of the Complex number object.
 * @return
 */
string Complex::toString() const
{ // TODO finish commenting
    string output; // FIXME: to_string the values, and add negative signs in the string phase
    if (im >= 0 && dem > 0)
        output = "[" + to_string(re) + " + " + to_string(im)  + "i]/" + to_string(dem);
    else if (im < 0 && dem > 0)
        output = "[" + to_string(re) + to_string(im)  + "i]/" + to_string(dem);
    else if (im >= 0 && dem < 0)
        output = "[" + to_string(re) + "+" + to_string(im)  + "i]/" + to_string(dem);
    else if (im < 0 && dem < 0)
        output = "[" + to_string(re) + to_string(im)  + "i]/" + to_string(dem);
    return output;
}

/**
 * Overloads addition operator for Complex number objects.
 * @param a - a Complex number
 * @param b - another Complex number
 * @return [(a.real + b.real) + (a.imag + b.imag)i]
 */
Complex operator+(Complex a, Complex b)
{
    Complex operandOne(a);
    Complex operandTwo(b); // TODO: be sure copy constructors work!!!
    Complex sum;
    // check if either a or b has a negative denominator
    if (a.dem < 0)
    {
        operandOne.re *= -1;
        operandOne.im *= -1;
        operandOne.dem *= -1;
    }
    else if (b.dem < 0)
    {
        operandTwo.re *= -1;
        operandTwo.im *= -1;
        operandTwo.dem *= -1;
    }

    // add components together
    if (a.dem == b.dem)
    {
        sum.re = operandOne.re + operandTwo.re;
        sum.im = operandOne.im + operandTwo.im;
    }
    else
    {
        sum.re = ( operandTwo.dem * operandOne.re + operandTwo.dem * operandOne.re );
        sum.im = ( operandTwo.dem * operandOne.im + operandTwo.dem * operandOne.im );
        sum.dem = operandOne.dem * operandTwo.dem;
    }

    // check if components can be reduced (factored down)
    int common_factors = gcd(sum.re, sum.im); // fIXME these 3 lines could be just one
    int common_factors2 = gcd(sum.im, sum.dem);
    int common_factors3 = gcd(common_factors, common_factors2);
    if (common_factors3 > 1) {
        sum.re /= common_factors3;
        sum.im /= common_factors3;
        sum.dem /= common_factors3;
    }

    return sum;
}

/**
 * Overloads the subtraction operator for Complex number objects.
 * @param a
 * @param b
 * @return
 */
Complex operator-(Complex a, Complex b)
{
    Complex operandOne(a);
    Complex operandTwo(b); // TODO: be sure copy constructors work!!!
    Complex difference;
    // check if either a or b has a negative denominator
    if (a.dem < 0) {
        operandOne.re *= -1;
        operandOne.im *= -1;
        operandOne.dem *= -1;
    }
    else if (b.dem < 0) {
        operandTwo.re *= -1;
        operandTwo.im *= -1;
        operandTwo.dem *= -1;
    }

    // add components together
    if (a.dem == b.dem)
    {
        difference.re = operandOne.re - operandTwo.re;
        difference.im = operandOne.im - operandTwo.im;
    }
    else
    {
        difference.re = ( operandTwo.dem * operandOne.re - operandTwo.dem * operandOne.re );
        difference.im = ( operandTwo.dem * operandOne.im - operandTwo.dem * operandOne.im );
        difference.dem = operandOne.dem * operandTwo.dem;
    }

    // check if components can be reduced (factored down)
    int common_factors = gcd(difference.re, difference.im); // fIXME these 3 lines could be just one
    int common_factors2 = gcd(difference.im, difference.dem);
    int common_factors3 = gcd(common_factors, common_factors2);
    if (common_factors3 > 1) {
        difference.re /= common_factors3;
        difference.im /= common_factors3;
        difference.dem /= common_factors3;
    }

    return difference;
}

/**
 * Overloads the multiplication operator for Complex number objects.
 * @param a
 * @param b
 * @return
 */
Complex operator*(Complex a, Complex b)
{
    Complex operandOne(a);
    Complex operandTwo(b); // TODO: be sure copy constructors work!!!
    Complex product;
    // check if either a or b has a negative denominator
    if (a.dem < 0)
    {
        operandOne.re *= -1;
        operandOne.im *= -1;
        operandOne.dem *= -1;
    }
    else if (b.dem < 0) {
        operandTwo.re *= -1;
        operandTwo.im *= -1;
        operandTwo.dem *= -1;
    }

    // multiply
    product.re = (operandOne.re * operandTwo.re) + (operandOne.im * operandTwo.im * -1);
    product.im = (operandOne.re * operandTwo.im) + (operandTwo.re * operandOne.im);
    product.dem = operandOne.dem * operandTwo.dem;

    // check if components can be reduced (factored down)
    int common_factors = gcd(product.re, product.im); // fIXME these 3 lines could be just one
    int common_factors2 = gcd(product.im, product.dem);
    int common_factors3 = gcd(common_factors, common_factors2);
    if (common_factors3 > 1) {
        product.re /= common_factors3;
        product.im /= common_factors3;
        product.dem /= common_factors3;
    }

    return product;
}

/**
 * Overloads the division operator for Complex number objects.
 * @param a
 * @param b
 * @return
 */
Complex operator/(Complex a, Complex b)
{
    Complex operandOne(a);
    Complex operandTwo(b); // TODO: be sure copy constructors work!!!
    Complex quotient;
    // check if either a or b has a negative denominator
    if (a.dem < 0)
    {
        operandOne.re *= -1;
        operandOne.im *= -1;
        operandOne.dem *= -1;
    }
    else if (b.dem < 0) {
        operandTwo.re *= -1;
        operandTwo.im *= -1;
        operandTwo.dem *= -1;
    }

    // divide
    quotient.re = (operandOne.re * operandTwo.re) + (operandOne.im * operandTwo.im);
    quotient.im = (operandOne.im * operandTwo.re) - (operandOne.re - operandTwo.im); // FIXME really?
    quotient.dem = pow(operandTwo.re, 2) + pow(operandTwo.im, 2); // FIXME we can use <cmath> right?

    // check if components can be reduced (factored down)
    int common_factors = gcd(quotient.re, quotient.im); // fIXME these 3 lines could be just one
    int common_factors2 = gcd(quotient.im, quotient.dem);
    int common_factors3 = gcd(common_factors, common_factors2);
    if (common_factors3 > 1) {
        quotient.re /= common_factors3;
        quotient.im /= common_factors3;
        quotient.dem /= common_factors3;
    }

    return quotient;
}

/**
 * Overloads the stream operator to process Complex number objects.
 * @param stream
 * @param a
 * @return
 */
//ostream& operator<< (ostream& stream, Complex a)
// {
//    stream << a.toString();
//    return stream;
//}

/**
 * TODO comment gcd
 * @param a
 * @param b
 * @return
 */
int gcd(int a, int b)
{
    int x = a;
    int y = b;

    if (x < 0)
        x *= -1;
    else if (y < 0)
        y *= -1;


    while (y > 0)
    {
        int remainder = x % y;
        x = y;
        y = remainder;
    }

    return x;
}

/**
 * TODO comment lcm
 * @param a
 * @param b
 * @return
 */
int lcm(int a, int b)
{
    // find gcd of inputs
    int greatest_common_d;
    greatest_common_d = gcd(a, b);
    // return (1/greatest_common_d) * a * b
    int lcm = (a/greatest_common_d) * b;
    return lcm;
}


