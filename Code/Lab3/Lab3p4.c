/*
 * Title: Lab 3 Project 4
 * Programmer: Christopher Lawrence      Date completed: 09/18/2016
 * Instructor: Professor Joe Jupin       Class: CIS1057
 *
 * Description of program: 
 *
 *
 */

// preprocessor directives
 #include <stdio.h>
 #include <math.h>
//function declarations
 double gosper(int n);
 double gosper_pow(int n);
 double gosper_sqrt(int n);

 int main(){
     // number for which the approximation is being made
     int n;
     // approximation of n!
     double nFact;

     // printf and scanf pair for n
     printf("Enter an integer n: ");
     scanf("%d", &n);
     // cmputing of the approximation of n!
     nFact = gosper(n);
     //printing of result to console
     printf("%d! equals approximately %.5lf\n", n, nFact); 

     return 0;
 }
 // returns gosper's approximation of n!
 double gosper(int n){
    // calls to other functions to simplify the operations
     return gosper_pow(n) * gosper_sqrt(n);
 }
// returns the first half of the gosper approximation
 double gosper_pow(int n){
     // M_E is the math.h constant for e
     return pow(n,n) * pow(M_E, -n);
 }
// returns the second half of the gosper approximation
 double gosper_sqrt(int n){
     // M_PI is the math.h constant for pi
     return sqrt((2 * n + (1.0/3)) * M_PI);
 }