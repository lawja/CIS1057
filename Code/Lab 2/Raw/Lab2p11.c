/*
 * Title: Lab 2 Project 11
 * Author: Christopher Lawrence      Date completed: Sun Sep 11 14:59:56 2016
 * Instructor: Professor Joe Jupin   Class: CIS 1057
 *
 * Description of program: 
 * Prompts the user to enter two positive integers and then creates a 
 * pythagorean triplet with said values
 */

#include <stdio.h>

int main(int argc, const char * argv[]){
    // values of input for pythagorean triplet
    int m, n;

    // scanf and printf pair for value m
    printf("Enter a positive integer for m: ");
    scanf("%d", &m);

    // scanf and printf pair for value m
    printf("Enter a positive integer for n: ");
    scanf("%d", &n);

    // computation of the triplet values
    int side1 = (m * m) - (n * n);
    int side2 = 2 * m * n;
    int hypotenuse = (m * m) + (n * n);

    // output of results
    printf("side1 = %d, side2 = %d, and hypotenuse = %d\n", side1, side2, hypotenuse);

    return 0;
}