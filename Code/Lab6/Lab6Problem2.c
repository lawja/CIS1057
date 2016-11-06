/*
 * Title: Lab 6 Problem 2
 * Programmer: Christopher Lawrence      Date completed: 10/20/2016
 * Instructor: Professor Joe Jupin       Class: CIS1057
 *
 * Description of program:
 * A rate conversion assistant that computes various rates base on
 * input
 */

// preprocessor directives
#include <stdio.h>

// function prototypes
// initial scan function
void get_problem(int *problem);
// data input
void get_rate_drop_factor(double *r, double *df);
void get_ml_rate(double *h);
void get_kg_rate_conc(double *mkg, double *w, double *mgml);
void get_units_conc(double *uh, double *uml);
//calculating functions
void fig_drops_min(double r, double df, int *result);
void fig_ml_hr(double h, int *result);
void by_weight(double mkg, double w, double mgml, int *result);
void by_units(double uh, double uml, int *result);


int main() {
    // simple header
    printf("INTRAVENOUS RATE ASSISTANT\n\n");
    
    // for switch statement
    int problem;
    
    // rate, drop factor, hours, mg per kg, weight, mg per ml,
    // units per hour, units per ml
    double r, df, h, mkg, w, mgml, uh, uml;
    int result;
    
    // scans for problem and then executes the process for said
    // problem through a switch statement
    do{
        // gets the problem number
        get_problem(&problem);
        
        // chooses which process to execute base on problem value
        switch (problem){
        case 1:
            // data input
            get_rate_drop_factor(&r, &df);
            fig_drops_min(r, df, &result);
            printf("The drop rate per minute is %d.\n", result);
            break;
        case 2:
            // data input
            get_ml_rate(&h);
            fig_ml_hr(h, &result);
            printf("The rate in milliliters per hour is %d.\n", result);
            break;
        case 3:
            // data input
            get_kg_rate_conc(&mkg, &w, &mgml);
            by_weight(mkg, w, mgml, &result);
            printf("The rate in milliters per hour is %d.\n", result);
            break;
        case 4:
            // data input
            get_units_conc(&uh, &uml);
            by_units(uh, uml, &result);
            printf("The rate in milliters per hour is %d.\n", result);
            break;
        // quit case
        case 5:
            break;
        // invalid number entered
        default:
            printf("\nInvalid entry\n");
        }
        printf("\n");
    }while(problem < 5 && problem > 0);
}

// prints initial formatting and scans for problem number
void get_problem(int *problem){
    
    printf("Enter the number of the problem you wish to solve.\n");
    printf("    GIVEN A MEDICAL ORDER\t\t");
    printf("\t\t\t CALCULATE RATE IN\n");
    printf("(1) ml/hr & tubing drop factor\t\t\t\t drops / min\n");
    printf("(2) 1 L for n hr\t\t\t\t\t\t ml / hr \n");
    printf("(3) mg/kg/hr & concentration in mg/ml\t\t ml / hr \n");
    printf("(4) units/hr & concentration in units/ml\t\t ml / hr \n");
    printf("(5) QUIT \n");
    
    printf("Problem=> ");
    scanf("%d", &*problem);
}

// scans in rate and drop factor
void get_rate_drop_factor(double *d, double *rf){
    printf("Enter rate in ml / hr=> ");
    scanf("%lf", &*d);
    printf("Enter tubing's drop factor(drops/ml)=> ");
    scanf("%lf", &*rf);
}

// scans in hours
void get_ml_rate(double *h){
    printf("Enter number of hours=> ");
    scanf("%lf", &*h);
}

// scans in rate, weight, and concentration
void get_kg_rate_conc(double *mkg, double *w, double *mgml){
    printf("Enter rate in mg/kg/hr=> ");
    scanf("%lf", &*mkg);
    printf("Enter patient weight in kg=> ");
    scanf("%lf", &*w);
    printf("Enter concentration in mg/ml=> ");
    scanf("%lf", &*mgml);
}

// scans in rate and concentration
void get_units_conc(double *uh, double *uml){
    printf("Enter rate in units/hr=> ");
    scanf("%lf", &*uh);
    printf("Enter concentration in units/ml=> ");
    scanf("%lf", &*uml);
    
}

// calculates the drops per minute
void fig_drops_min(double r, double df, int *result){
    *result = (int)(((r * df) / 60) + .5);
}

// calculates the rate in milliliters per hour
void fig_ml_hr(double h, int *result){
    *result = (int)((1000/ h) + .5);
}

// calculates the rate in milliliters per hour
void by_weight(double mkg, double w, double mgml, int *result){
    *result = (int)((mkg * (w/mgml)) +.5);
}

// calculates the rate in milliliters per hour
void by_units(double uh, double uml, int *result){
    *result = (int)((uh / uml) + .5);
}

