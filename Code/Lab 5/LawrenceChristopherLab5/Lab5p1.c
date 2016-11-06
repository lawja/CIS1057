/*
 * Title: Lab 5 Problem 1
 * Programmer: Christopher Lawrence      Date completed: 10/06/2016
 * Instructor: Professor Joe Jupin       Class: CIS1057
 *
 * Description of program:
 *
 *
 */

#include <stdio.h>

int divisibleByNine(int n);

int main(int argc, const char * argv[]){
    int n;
    //printf scanf pair for n
    printf("Enter a number:");
    scanf("%d", &n);
    
    // boolean representation of whether or not n is divisble by 9
    int x = divisibleByNine(n);
    
    // print clause
    if(x){
        printf("%d is divisible by 9\n", n);
    }else{
        printf("%d is not divisible by 9\n", n);
    }
    
    return 0;
}

// determines if n i divisible by 9
int divisibleByNine(int n){
    // sum represents the sum of n's digits
    int sum = 0;
    
    while(n > 0){
        // extracts last digit remaining in n and adds it to the sum
        sum += n % 10;
        
        // removes last digit from n
        n /= 10;
    }
    // if sum is divisible by 9 so is n
    return sum % 9 == 0;
}
