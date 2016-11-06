/*
 * Title: Lab 4 Project 7
 * Programmer: Christopher Lawrence      Date completed: 09/22/2016
 * Instructor: Professor Joe Jupin       Class: CIS1057
 *
 * Description of program: 
 * Gives the number of days into the year based upon the inputted
 * month, day, and year
 */

// preprocessor directives
#include <stdio.h>

// function prototypes
int leap(int year);
int calcNum(int day, int month, int year);

int main(){
    int month, day, year;
    // printf scanf pair for the date(month, day, year)
    printf("Enter the date mm dd yyyy: ");
    scanf("%d%d%d", &month, &day, &year);
    if((day < 1 || day > 31) || (month < 1 || month > 12) || year < 0){
        printf("Invalid date, try again\n");
        main();
    }
    else
        printf("Day Number #%d of the year\n", calcNum(day,month,year));

    return 0;

}

// determines if the given year is a leap year
int leap(int year){
   return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// calculates the numerical reprentation of the day of the year
int calcNum(int day, int month, int year){
    int l = leap(year);

    int tdays = day;

    switch (month){
        case 12:
            tdays += 30;
        case 11:
            tdays += 31;
        case 10:
            tdays += 30;
        case 9:
            tdays += 31;
        case 8:
            tdays += 31;
        case 7:
            tdays += 30;
        case 6:
            tdays += 31;
        case 5:
            tdays += 30;
        case 4:
            tdays += 31;
        case 3:
            if(l){
                tdays += 29;
            }else{
                tdays += 28;
            }   
        case 2:
            tdays += 31;
        }

        return tdays;
    }   
