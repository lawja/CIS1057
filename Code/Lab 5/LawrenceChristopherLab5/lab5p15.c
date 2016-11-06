/*
 * Title: Lab 5 Problem 15
 * Programmer: Christopher Lawrence      Date completed: 10/12/2016
 * Instructor: Professor Joe Jupin       Class: CIS1057
 *
 * Description of program:
 *
 *
 */


// preprocessor directives
#include <stdio.h>

double makeSomePi();

int main(int argc, const char * argv[]) {
    // approximation of pi
    double x = makeSomePi();
    // printing to 9 decimal places the approximation of pi
    printf("%.9lf\n", x);
    
    return 0;
}

double makeSomePi(){
    // alternating sign var
    int j = -1;
    // sum of fractions
    double sum = 0;
    for(int i = 1;i <= 99;i+=2){
        // alternating of sign
        j *= -1;
        // creation of fractions
        sum += (1.0 / i) * j;
    }
    
    // approximation of sign
    return sum * 4;
}
