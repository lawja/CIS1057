/*
 * Title: Lab 2 Project 1
 * Author: Christopher Lawrence      Date completed: Sun Sep 11 14:35:16 2016
 * Instructor: Professor Joe Jupin   Class: CIS 1057
 *
 * Description of program: 
 * Calculates the reimbursement of a worker that travels by a vehicle by $.35
 * per mile.
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // beginning odometer reading
    double beginOdomR;
    // ending odometer reading
    double endOdomR;
    double difference;
    double reimb = .35;
    
    
    // a stylistic header for the program
    printf("MILEAGE REIMBURSEMENT CALCULATOR\n");

    // prompts user for beginning odemeter value and assigns it accordingly
    printf("Enter beginning odometer reading=> ");
    scanf("%lf", &beginOdomR);
    // prompts user for ending odemeter value and assigns it accordingly
    printf("Enter ending odometer reading=> ");
    scanf("%lf", &endOdomR);
    
    // computes the difference between the two values
    difference = endOdomR - beginOdomR;
    
    // computes the total reimbursement based on the distance travelled
    reimb *= difference;
    
    // final output of the total distance traveled between the two readings
    printf("You traveled %.1f miles.\tAt $0.35 per mile,\nyour reimbursement is $%.2f.\n", difference, reimb);
    
    return 0;
}

    
