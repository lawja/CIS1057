/*
 * Title: Lab 6 Problem 10
 * Programmer: Christopher Lawrence      Date completed: 10/19/2016
 * Instructor: Professor Joe Jupin       Class: CIS1057
 *
 * Description of program:
 * A calculator that has the ability to do +, -, /, *, ^. q to quit
 *
 */

// preprocessor directives
#include <stdio.h>
#include <math.h>

// function prototypes
void scan_data(char *operator, double *operand);
void do_next_op(char input, double operand, double *total);

int main() {
    // input values
    char operator = 0;
    double operand = 0;
    // stored value
    double total;
    
    // repeatedly scans data
    do{
        // scans for operator and operand
        scan_data(&operator, &operand);
        
        // break operator
        if(operator == 'q'){
            break;
        }
        // processes input and mutates result value based upon operator
        do_next_op(operator, operand, &total);
        // result update to console
        printf("result so far is %.2lf\n", total);
    }while(1);
    
    return 0;
}

// takes input
void scan_data(char *operator, double *operand){
    char g;
    scanf("%c%lf%c", &*operator, &*operand, &g);
}

// processes input
void do_next_op(char input, double operand, double *total){
    // determines what to do with the values inputted
    switch (input) {
        case '+':
            *total += operand;
            break;
        case '-':
            *total -= operand;
            break;
        case '*':
            *total *= operand;
            break;
        case '/':
            *total /= operand;
            break;
        case '^':
            *total = pow(*total, operand);;
            break;
        default:
            printf("Invalid operator; try again\n");
    }
}
    
    
