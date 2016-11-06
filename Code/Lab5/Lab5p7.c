/*
 * Title: Lab 5 Problem 7
 * Programmer: Christopher Lawrence      Date completed: 10/12/2016
 * Instructor: Professor Joe Jupin       Class: CIS1057
 *
 * Description of program:
 *
 *
 */

// preprocessor directives
#include <stdio.h>


// input can be used through batch processing or it can be
// used through scanf continously but the escape character is '0'

void temperatures();

int main() {
    // value that breaks out of the loop
    printf("0 is the sentinel value\n\n");
    // call to temperatures
    temperatures();
    return 0;
}

void temperatures(){
    // counter, hot days, pleasant days, cold days
    int hd = 0, pd = 0, cd = 0;
    // sum of all temperatures
    double sum = 0;
    // given temperature value
    int n = 0;
    do{
        // printf scanf pair for n
        printf("Enter a temperature: ");
        scanf("%d", &n);
        
        // increase in sum of temperatures
        sum += n;
        
        // if n is a hot day
        if(n > 84){
            printf("%d -> Hot day\n", n);
            hd++;
        }
        // if n is pleasant day
        else if(n > 59){
            printf("%d -> pleasant day\n", n);
            pd++;
        }
        // if n is a cold day
        else if(n > 0 || n < 0){
            printf("%d -> cold day\n", n);
            cd++;
        }
    // 0 is the given sentinel value
    }while(n != 0);
    
    // total days
    int td = cd + hd + pd;
    
    if(td != 0){
        // statistical overview
        printf("%d hot days, %d pleasant days, %d cold days\n", hd, pd, cd);
        // average temperature for the given data
        double avg_temp = sum / (cd + pd + hd);
        printf("Average temperature of the given data set: %.2lf degrees\n", avg_temp);
    }
    // no valid temperatures entered
    else{
        printf("Sentinel value entered before any valid data\nTry again\n");
        // call to main for user to trie again
        main();
    }
    
}
