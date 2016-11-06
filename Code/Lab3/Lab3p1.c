/*
 * Title: Lab 3 Project 1
 * Programmer: Christopher Lawrence      Date completed: 09/18/2016
 * Instructor: Professor Joe Jupin       Class: CIS1057
 *
 * Description of program: 
 * Determines the monthly payement on a car based upon the price of
 * the car, the size of the down payment, the annual interest, and 
 * the amount of payments that will be made on the vehicle
 */

//preprocessor directives
 #include <stdio.h>
 #include <math.h>

 // declarations of the functions
 double amountBorrowed(int purchasePrice, double downPayment);
 double payment(double p, double annualInterest, int numOfPayments);

 int main(){
     // declaration of input variables
     int purchasePrice, numOfPayments;
     double downPayment, annualInterest;

     // printf and scanf pair for purchasePrice
     printf("Enter the purchase price of the car:");
     scanf("%d", &purchasePrice);

    // printf and scanf pair for downPayment
     printf("Enter the down payment amount for the car: ");
     scanf("%lf", &downPayment);

     // printf and scanf pair for annualInterest
     printf("Enter the annual interest rate for the car in the format of x.x percent:");
     scanf("%lf", &annualInterest);

     // printf and scanf pair for numOfPayments
     printf("Enter the number of payments for the car: ");
     scanf("%d", &numOfPayments);

     // calculates the amount borrowed by calling the amountBorrowed function and passing various parameters
     double p = amountBorrowed(purchasePrice, downPayment);

     // calculates the monthly payment amount by calling the payment function and passing various parameters
     double paymentAmount = payment(p, annualInterest, numOfPayments);

     // prints amount borrowed and monthly payment amount to the console
     printf("Amount borrowed: $%.2lf\tPayment Amount: $%.2lf\n", p, paymentAmount);
     
     return 0;
 }
 // consumes the purchasePrice of a vehicale and the downPayment and then calculates the difference between the two
 double amountBorrowed(int purchasePrice, double downPayment){
     return purchasePrice - downPayment;
 }
 // consumes the money owed, the annual interest, and the amount of payments; then produces the monthly payment amount
 double payment(double p, double annualInterest, int n){
     // converts anual interest to monthly interest
     double i = (annualInterest / 100) / 12;
     // computes result
     return (i * p) / (1 - pow((1 + i), -n));
 } 