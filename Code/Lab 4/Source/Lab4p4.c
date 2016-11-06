/*
 * Title: Lab 4 Project 4
 * Programmer: Christopher Lawrence      Date completed: 09/22/2016
 * Instructor: Professor Joe Jupin       Class: CIS1057
 *
 * Description of program: 
 * Prints to the console the contents of the cylinder based on the
 * input of the first letter of the color of the cylinder
 */

// preprocessor directives
 #include <stdio.h>

// function prototypes
 void identify(char sample);

 int main(){
     char s;

     // printf and scanf pair for the variable s
     printf("Enter a singular character representation for the color of the cylinder: ");
     scanf("%c", &s);

     identify(s);

     return 0;
 }

// prints out the corresponding contents based on the character representation of the color
 void identify(char sample){
     // uses swutch because comparing constant to variable
     switch (sample){
         case 'o':
         case 'O':
            printf("Ammonia");
            break;
         case 'b' :
         case 'B':
            printf("Carbon Monoxide");
            break;
         case 'y' :
         case 'Y':
            printf("Hydrogen");
            break;
         case 'g' :
         case 'G':
            printf("Oxygen");
            break;
        default:
            printf("Contents Unknown");
        }
        printf("\n");
    }