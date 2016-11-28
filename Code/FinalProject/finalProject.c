/*
 * =====================================================================================
 *
 *       Filename:  finalProject.c
 *
 *    Description:  Final Project for CIS1057 at Temple University
 *
 *        Version:  1.0
 *        Created:  11/27/2016 18:22:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Christopher Lawrence (clawrence), jake.lawrence@temple.edu
 *        Company:  Temple University
 *
 * =====================================================================================
 */

#include <stdio.h>

// struct to contain product data
typedef{
	char type[10];
	char id[4];
	char desc[50];
	double price;
	int quantity;
}product_t;

// struct to contain order data
typedef{
	int order_id;
	char product_id[4];
	int quantity;
}order_t;

typedef{
	product_t product_list[4];
}product_array_t;

typedef{
	order_t order_list[10];
}order_array_t;

int main(){
	FILE *products_in = fopen("files/Products.csv", "r");

	do{
		printf("%s\n", s);
	}while(fgets(s,50,products_in) != NULL);

	return 0;
}



