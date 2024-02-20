//// PROGRAMMING II LABS : P0
//AUTHOR 1: ISMAEL BREA ARIAS    LOGIN 1: ismael.brea
//AUTHOR 2: DIEGO ROMÁN POSE     LOGIN 1: diego.roman
//GROUP: 4.3    DATE: 06/02/2024

#ifndef RATIONAL_RATIONAL_STRUCT_H
#define RATIONAL_RATIONAL_STRUCT_
typedef struct Data Rational;
struct Data{
    int num;
    int den;
};
Rational createRational(int n, int d );
int numerator(Rational r);
int denominator(Rational r);
Rational sum(Rational r1, Rational r2);

#endif //RATIONAL_RATIONAL_STRUCT_H
