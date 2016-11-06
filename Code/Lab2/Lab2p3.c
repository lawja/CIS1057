/*
 * Title: Lab 2 Project 3
 * Author: Christopher Lawrence      Date completed: Sun Sep 11 14:43:47 2016
 * Instructor: Professor Joe Jupin   Class: CIS 1057
 *
 * Description of program: 
 * Estimates the temperature of a freezer in celsius from the point of time in
 * which a power outtage occured
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // input values of hours and minutes elapsed since power outtage
    int hours, minutes;

    // output values
    double completeTime, temperature;

    // printf and scanf pair for values hours and minutes
    printf("Enter how long ago the power outtage was in whole hours and minutes: ");
    scanf("%d %d", &hours, &minutes);

    // combines the given seperate hours and minutes representation into a singular
    // double value for the hours elapsed
    completeTime = hours + ((double) minutes / 60);

    // computes the estimated temperature based upon the computed time elapsed value
    temperature = ((4 * (completeTime * completeTime))/(completeTime + 2)) - 20;

    // final output of the simplified time elapsed and the estiamted resuting temperature
    // of the freezer
    printf("The temperature in your freezer after %.2lf hours is %.1lf°C\n", completeTime, temperature);

    return 0;
}
