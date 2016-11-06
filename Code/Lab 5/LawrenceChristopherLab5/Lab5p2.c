/*
 * Title: Lab 5 Problem 2
 * Programmer: Christopher Lawrence      Date completed: 10/06/2016
 * Instructor: Professor Joe Jupin       Class: CIS1057
 *
 * Description of program:
 *
 *
 */

// preprocessor directives
#include <stdio.h>

void divisibleByNine();

int main(int argc, const char * argv[]){
    
    // call to divisible by nie
    divisibleByNine();
    
    return 0;
}

// determines if a given number is divisible by nine
void divisibleByNine(){
    // sum represents the sum of all the enterd digits
    int sum = 0;
    char digit;
    do{
        // printf scanf pair for dgits
        printf("Enter a digit (enter alpha to quit): ");
        scanf(" %c",&digit);
        
        // if alpha break
        if(digit < '0' || digit > '9')
            break;
        
        // conversion from char to int
        int n = (int) digit - (int) '0';
        
        // adds the entered digit to sum
        sum += n;
        
    }while(1);
    
    printf("The sum is %d and ", sum);
    
    // print clause for sum being divisble by 9
    if(sum % 9 != 0)
        printf("not ");
    printf("divisible by 9\n");
}
