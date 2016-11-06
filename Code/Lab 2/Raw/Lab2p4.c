/*
 * Title: Lab 2 Project 4
 * Author: Christopher Lawrence      Date completed: Sun Sep 11 14:50:08 2016
 * Instructor: Professor Joe Jupin   Class: CIS 1057
 *
 * Description of program: 
 * Prompts the user to enter a value in degrees farenheit and then the program
 * converts the value to degrees in celsius
 */

#include <stdio.h>

int main(){
    // input variable that will be converted
    int fahrenheit;

    // output variable of converted temperature
    double celsius;

    // scanf and printf pair for value farenheit
    printf("Enter the temperature you wish to convert in degrees fahrenheit: ");
    scanf("%d", &fahrenheit);

    // computation of celsius value, note the double division by changing
    // 5 to 5.0
    celsius = (5.0 / 9) * (fahrenheit - 32);

    // final output of converted value, prints one decimal point for celsius value
    printf("%d degrees in fahrenheit is equal to %.1lf degrees in celsius\n", fahrenheit, celsius);  

    return 0;
}