/*
 * Title: Lab 6 Problem 1
 * Programmer: Christopher Lawrence      Date completed: 10/20/2016
 * Instructor: Professor Joe Jupin       Class: CIS1057
 *
 * Description of program:
 * Asks the user for an amount in dollars to withdraw. The program
 * responds with the amount of fifty, twenty, and ten dollar bills
 * that will be dispensed.
 *
 */

// preprocessor directives
#include <stdio.h>
#include <string.h>

// function prototypes
void teller(int amount, int *fi, int *tw, int *te);

int main() {
    // input variable
    int amount;
    
    // printf scanf pair for amount
    printf("Enter the amount you would like to withdraw: ");
    scanf("%d", &amount);
    
    // count variables for fifties, twenties, and tens
    int fi = 0, tw = 0, te = 0;
    
    // check if amount is divisible by 10
    if(amount % 10 != 0){
        printf("Amount must be divisble by 10, enter a different amount.\n");
        // start over
        main();
    }
    
    // passed by address
    teller(amount, &fi, &tw, &te);
    
    // results print to console
    printf("The teller dispenses: %d 50s, %d 20s, and %d 10s.\n", fi, tw,te);
    
    return 0;
}

// returns data to calling module by address
void teller(int amount, int *fi, int *tw, int *te){
    // continue if all money hasn't been taken out
    while(amount != 0){
        // if a fifty can be taken out
        if(amount >= 50){
            (*fi)++;
            amount -= 50;
        }
        // if a twenty can be taken out
        else if(amount >= 20){
            (*tw)++;
            amount -= 20;
        }
        // dispense out a ten
        else{
            (*te)++;
            amount -= 10;
        }
    }
}
