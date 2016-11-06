/*
 * Title: Lab 3 Project 12
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
 double speedOfSound(int t);
 void explain(int t);

 int main(){
     //input variable
     int temp;
     // printf and scanf pait for temp
     printf("Enter the given temperature in fahrenheit: ");
     scanf("%d", &temp);
     // assigns function result to variable
     double a = speedOfSound(temp);
     // prints result
     printf("At %d degrees fahrenheit the speed of sound is %lf ft/sec\n\n", temp, a);
     // explains the process to the user
     explain(temp);

     return 0;
 }
// calculates the speed of sound from a given temperature, t
 double speedOfSound(int t){
     // simplification of the equation
     double p2 = sqrt(((double)(5 * t) + 297)/247);
     return 1086 * p2;
 }
// prints an explanation of the process to the console
 void explain(int t){
     printf("Below are the steps for how to calculate the speed of sound based on temperature\n");
     printf("1. Take the given temperature input in fahrenheit, t, and multiply it by 5\n");
     printf("2. Add 297 to 5t\n");
     printf("3. Divide the answer from step 2 by 247\n");
     printf("4. Take the square root of the answer from step 3\n");
     printf("5. Multiply the answer from step 4 by 1086; you will then have your answer in the units of ft/sec\n\n");
     printf("Below is the process of finding the speed of sound using the given variable t\n");
     int t5 = 5 * t;
     printf("1. 5 * %d = %d\n", t, t5);
     int t2 =  297 + t5;
     printf("2. %d + 297 = %d\n", t5, t2);
     double td = (double) t2 / 247;
     printf("3. %d / 247 = %lf\n", t2, td);
     double sqrt_td = sqrt(td);
     printf("4. sqrt(%lf) = %lf\n", td, sqrt_td);
     double final_a = sqrt_td * 1086;
     printf("5. %lf * 1086 = %lf\n", sqrt_td, final_a);
     printf("Answer: %lf ft/sec\n", final_a);
 }