 /* Assisted by and Assisted line numbers: Dr.Su lines 37-51, 85-91, 93-112, 114-162(Assignment 3 driver)
 
 * Matthew Young
 
 *This program will perform mathmatical functions with fractions, including addition, subtraction, multiplication and
  Division. It will also reduce fractions and convert them to decimals.
 
 */
// a Fraction object holds one Fraction number, one fraction
#include "frac.h"

Fraction::Fraction(int n, int d) {
    numerator = (d < 0 ? -n : n);   // Will determine the sign of the numerator
    denominator = (d < 0 ? -d : d); // Will determine the sign of the numerator
    reduce();
    
}

Fraction Fraction::add(const Fraction& a) {
    Fraction t;
    t.numerator = a.numerator * denominator + a.denominator * numerator; // Equation for addition in numerator
    t.denominator = a.denominator * denominator;                         // Equation for addition in denominator
    t.reduce();                                                          // Will reduce fraction
    return t;
    
}

Fraction Fraction::subtract(const Fraction& a) {
    Fraction t;
    t.numerator = numerator * denominator - a.numerator * a.denominator; // Equation for subtraction in numerator
    t.denominator = a.denominator * denominator;                         // Equation for subtraction in denominator
    t.reduce();                                                          // Will reduce fraction
    return t;
}
Fraction Fraction::multiply(const Fraction& a) {
    Fraction t;
    t.numerator = a.numerator * numerator;                               // Equation for multiplication in numerator
    t.denominator = a.denominator * denominator;                         // Equation for multiplication in denominator
    t.reduce();                                                          // Will reduce fraction
    return t;
}

Fraction Fraction::divide(const Fraction& a) {
    Fraction t;
    t.numerator = a.numerator * numerator / a.denominator * denominator; // Equation for division in numerator
    t.denominator = a.denominator * denominator;                         // Equation for division in denominator
    t.reduce();                                                          // Will reduce fraction
    return t; 
}

void Fraction::printFraction() {
    if (denominator == 0) {
        cout << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
    }
    else {
        cout << numerator << "/" << denominator;
    }
}

void Fraction::printFractionAsFloat() {
    if (denominator == 0)
        cout << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
    else
        cout << float(numerator) / float(denominator);
    
}

void Fraction::reduce() {
    int n = numerator < 0 ? -numerator : numerator; // Determines sign of numerator
    int d = denominator;
    int largest = n > d ? n : d;
    int gcd = 0;
    
    for (int loop = largest; loop >= 2; loop--) // Loop to reduce fractions
        if (numerator % loop == 0 && denominator % loop == 0) {
            gcd = loop;
            break;
            
        }
    
    if (gcd != 0) {
        numerator /= gcd;
        denominator /= gcd;
        
    }
    
}

int main() {
    Fraction x(-3,8), y(-15,-20), z, w(5);
    x.printFraction();
    cout << " + ";
    y.printFraction();
    z = x.add(y);
    cout << " = ";
    z.printFraction();
    cout << endl;
    z.printFraction();
    cout << " = ";
    z.printFractionAsFloat();
    cout << endl << endl;
    x.printFraction();
    cout << " - ";
    y.printFraction();
    z = x.subtract(y);
    cout << " = ";
    z.printFraction();
    cout << endl;
    z.printFraction();
    cout << " = ";
    z.printFractionAsFloat();
    cout << endl << endl;
    x.printFraction();
    cout << " * ";
    y.printFraction();
    z = x.multiply(y);
    cout << " = ";
    z.printFraction();
    cout << endl;
    z.printFraction();
    cout << " = ";
    z.printFractionAsFloat();
    cout << endl << endl;
    x.printFraction();
    cout << " / ";
    y.printFraction();
    z = x.divide(y);
    cout << " = ";
    z.printFraction();
    cout << endl;
    z.printFraction();
    cout << " = ";
    z.printFractionAsFloat();
    cout << endl;
    return 0;
    
}
