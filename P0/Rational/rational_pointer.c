//// PROGRAMMING II LABS : P0
//AUTHOR 1: ISMAEL BREA ARIAS    LOGIN 1: ismael.brea
//AUTHOR 2: DIEGO ROMÁN POSE     LOGIN 1: diego.roman
//GROUP: 4.3    DATE: 06/02/2024


#include <stdlib.h>
#include "rational_pointer.h"
//Operation to create a rational number
Rational createRational(int n, int d){
    Rational temp;
    temp= malloc(sizeof(*temp));
    temp->num= n;
    temp->den= d;
    return temp;

}
//Operation that returns the numerator of a rational
int numerator(Rational r){
    return r->num;
}
//Operation that returns the denominator of a rational
int denominator(Rational r){
    return r->den;
}
//operation that returns the sum of rationals
Rational sum(Rational r1, Rational r2){
    Rational s;
    s=malloc(sizeof(*s));
    s->num= r1->num * r2->den + r2->num * r1->den;
    s->den= r1-> den * r2->den;
    return s;
}