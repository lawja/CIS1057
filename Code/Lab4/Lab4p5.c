/*
 * Title: Lab 4 Project 5
 * Programmer: Christopher Lawrence      Date completed: 09/22/2016
 * Instructor: Professor Joe Jupin       Class: CIS1057
 *
 * Description of program: 
 * Determines the damage inflicted on an effected area based on the
 * entered magnitude from a richter scale numerical representation
 */

 /* 
  * This problem could not be handled with a switch statement because
  * switch statements only compare objects with an equals operators
  * and to solve this problem the < operator is necessary
  */

// preprocessor directives
 #include <stdio.h>

// function prototypes
void richterIdentify(double rn);

 int main(){
     double rn;

     // printf scanf pair for variable rn
     printf("Enter the numerical classification of the earthquake in accordance to the richter scale: ");
     scanf("%lf", &rn);

     richterIdentify(rn);

     return 0;
 }

// prints the damage based upon the magnitude of rn
 void richterIdentify(double rn){
     // cannot use switch because comparisons aren't made with ==
     if(rn < 5.0){
         printf("Little or no damage");
     }else if (rn < 5.5){
         printf("Some damage");
     }else if (rn < 6.5){
         printf("Serious damage: walls may crack or fall");
     }else if (rn < 7.5){
         printf("Disaster: Houses and buildings may collapse");
     }else{
         printf("Catastrophe: most buildings destroyed");
     }
     printf("\n");
 }
 