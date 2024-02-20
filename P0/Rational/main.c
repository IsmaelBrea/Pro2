//// PROGRAMMING II LABS : P0
//AUTHOR 1: ISMAEL BREA ARIAS    LOGIN 1: ismael.brea
//AUTHOR 2: DIEGO ROMÁN POSE     LOGIN 1: diego.roman
//GROUP: 4.3    DATE: 06/02/2024

#include <stdio.h>
//#include "rational_struct.h"
#include "rational_pointer.h"

int main() {
    Rational r1,r2,r3,r4,s;
    r1= createRational(2,3);
    r2= createRational(5,7);
    r3= createRational(7,3);
    r4= createRational(5,4);
    s=sum(r1,r2);
    printf( "The sum is %d/%d\n",numerator(s),denominator(s));
    s=sum(r3,r4);
    printf("The sum is %d/%d\n", numerator(s),denominator(s));

    return 0;
}
