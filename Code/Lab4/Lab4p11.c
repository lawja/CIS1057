/*
 * Title: Lab 4 Project 11
 * Programmer: Christopher Lawrence      Date completed: 09/22/2016
 * Instructor: Professor Joe Jupin       Class: CIS1057
 *
 * Description of program: 
 * Tells the user if their observed boiling point of a liquid
 * is within a certain percent of a predefined liquid's 
 * boiling point, then tells them the liquid
 */


// preprocessor directives
#include <stdio.h>

// function prototypes
int within_x_percent(int ref, int data, double x);
void identifySubstance(int data);

int main(){
    int data, ref;
    double x;

    // printf scanf pair for variabel data
    printf("Enter your observed boiling point: ");
    scanf("%d", &data);

    // results
    identifySubstance(data);

    // demonstrates the use of the function within_x_percent
    printf("Example of within_x_percent: [Is 98 within 5 percent of 100?] within_x_percent(100,98,5) [%d]\n", within_x_percent(100,98,5));
    
    return 0;
}

// prints the substance that aligns with the given boiling point, within 5 percent
void identifySubstance(int data){

    // cannot use switch because we are dealing with non-constant expressions
    if(within_x_percent(100, data, 5)){
        printf("Water");
    } else if(within_x_percent(357, data, 5)){
        printf("Mercury");
    } else if(within_x_percent(1187, data, 5)){
        printf("Copper");
    } else if(within_x_percent(2193, data, 5)){
        printf("Silver");
    } else if(within_x_percent(2660, data, 5)){
        printf("Gold");
    } else {
        printf("Unknown substance");
    }

    printf("\n");
}

// determines if data is within x percent of ref
int within_x_percent(int ref, int data, double x){
    double l = (ref - (ref * (x / 100)));
    double u = (ref + (ref * (x / 100)));
    return (data >= l)&&(data <= u);
}