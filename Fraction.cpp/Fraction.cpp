
#include <iostream>
#include <stdexcept>
#include "Fraction.h"

using namespace std;
    int Fraction::find_gcd (int n1, int n2){
        int gcd, remainder;
        /* Euclid's algorithm */
        remainder = n1 % n2;
            while ( remainder != 0 ){
                n1 = n2;
                n2 = remainder;
                remainder = n1 % n2;
            }
                gcd = n2;
                return (gcd);
    }
    void Fraction::reduce_fraction(int *nump, int *denomp){
        int gcd;
        gcd = find_gcd(*nump, *denomp);
        *nump = *nump / gcd;
        *denomp = *denomp / gcd;
        if (*denomp < 0) { 
            *nump = -*nump;
            *denomp = -*denomp;
        }
    }

    int Fraction::getNum() const{
            return n;
        }
    int Fraction::getDen() const{
            return d;
        }
    Fraction::Fraction(){
            n = 0;
            d = 1;
        }
    Fraction::Fraction(int num) {
        n = num;
        d = 1;
    }
    Fraction::Fraction(int num, int den) {
    if (den == 0) {
        throw invalid_argument("zero denominator");
    }
    n = num;
    d = den;
    reduce_fraction(&n, &d);
    }

    Fraction Fraction::operator-() {
        return Fraction(-n, d);
    }

    Fraction Fraction::operator+(Fraction f){
        Fraction result;
            
        if(d == f.d){
            result.n = (n + f.n);
            result.d = d;
        }
        else{
            result.n = (n * f.d) + (f.n * d);
            result.d = (d * f.d);
        } 
        result.reduce_fraction(&result.n, &result.d);      
        return result;
    }

    Fraction Fraction::operator-(Fraction f){
        Fraction result;
        
        if(d == f.d){
            result.n = (n - f.n);
            result.d = d;
        }
        else{
            result.n = (n * f.d) - (f.n * d);
            result.d = (d * f.d);
        }       
        result.reduce_fraction(&result.n, &result.d);
        return result;
    }

    Fraction Fraction::operator*(Fraction f){
        Fraction result;
        
        result.n = n * f.n;
        result.d = d * f.d;
            
        result.reduce_fraction(&result.n, &result.d);
        return result;
    }

    Fraction Fraction::operator/(Fraction f){
        Fraction result;
        
        if (f.n == 0) {
            throw invalid_argument("zero denominator");
        }
        result.n = n * f.d;
        result.d = d * f.n;
            
        result.reduce_fraction(&result.n, &result.d);
        return result;
    }

    Fraction operator+(int integer, const Fraction& f) {
        return Fraction(integer * f.d + f.n, f.d);
    }

    Fraction operator-(int integer, const Fraction& f) {
        return Fraction(integer * f.d - f.n, f.d);
    }

    Fraction operator*(int integer, const Fraction& f) {
        return Fraction(integer * f.n, f.d);
    }

    Fraction operator/(int integer, const Fraction& f) {
        if (f.d == 0) {
            throw invalid_argument("zero denominator");
        }
            return Fraction(integer * f.d, f.n);
    }

    ostream& operator<<(ostream& os, const Fraction& f){
        if (f.d == 1) {
            os << f.n; 
        } 
        else {
            os << f.n << "/" << f.d;
        }
        return os;
    }
    void Fraction::print_fraction(void){
        reduce_fraction(&n, &d);
        cout << n << "/" << d << endl;
        }   
