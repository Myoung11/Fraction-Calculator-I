 /* Assisted by and Assisted line numbers: Dr.Su lines 55, 63, 45
 
 * Matthew Young
 
 *This program is used in the main.cpp (frac.cpp) to help perform operations and it is separate to help organize
  and simplify the code.
 
 */


#include <iostream>
using namespace std;



class Fraction
{
public:
    
    Fraction(int = 0, int = 1);     // default constructor
    
    Fraction add(const Fraction &);      // Lines 12-17 are parts for the mathmatic operations for the fractions
    Fraction subtract(const Fraction &);
    Fraction multiply(const Fraction &);
    Fraction divide(const Fraction &);
    Fraction fraction(const Fraction &);
    Fraction decimal(const Fraction &);
    
    void printFraction();       
    void printFractionAsFloat();
    
private:
    
    int numerator;
    int denominator;
    
    
    void reduce();                         // utility function, reduce to lowest terms
};
