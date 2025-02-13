//Noah Im ID:923109389

#ifndef FRACTION_H
#define FRACTION_H

#include <stdexcept>
#include <iostream>
using namespace std;

class Fraction
{
    private:
        int n;
        int d;
        int find_gcd (int n1, int n2);
        void reduce_fraction(int *nump,  int *denomp);

    public:
        Fraction();
        Fraction(int num);
        Fraction(int num, int den);

        int getNum() const;
        int getDen() const;

        Fraction operator+(Fraction f);
        Fraction operator-(Fraction f);
        Fraction operator*(Fraction f);
        Fraction operator/(Fraction f);

        Fraction operator-();
        friend Fraction operator+(int integer, const Fraction& f);
        friend Fraction operator-(int integer, const Fraction& f);
        friend Fraction operator*(int integer, const Fraction& f);
        friend Fraction operator/(int integer, const Fraction& f);

        friend ostream& operator<<(ostream& os, const Fraction& f);
        
        void print_fraction(void);

};
#endif