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
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

// struct to contain product data
typedef struct{
	char type[100];
	char id[400];
	char desc[500];
	double price;
	int quantity;
}product_t;

// struct to contain order data
typedef struct{
	int order_id;
	char product_id[4];
	int quantity;
}order_t;

typedef struct{
	product_t inventory[4];
}product_array_t;

typedef struct{
	order_t array[10];
}order_array_t;

void read_products(char filename[], product_array_t *product_list);
void printProducts(product_array_t product_list);

int main(){
	product_array_t product_list;
	read_products("files/Products.csv", &product_list);
	printProducts(product_list);
	return 0;
}

void read_products(char filename[], product_array_t *product_list){
	char buff[MAX_LENGTH];

	FILE *products_in = fopen(filename, "r");

	if(products_in == NULL){
		printf("Error: File contains no data");
		return;
	}
	int count = 0;
	while(fgets(buff,MAX_LENGTH,products_in) != NULL){
		// assigns product type to the product in the product list
		strcpy(product_list->inventory[count].type, strtok(buff,","));
		// assigns product id to the product in the product list
		strcpy(product_list->inventory[count].id, strtok(NULL,","));
		// assigns product type to the description in the product list
		strcpy(product_list->inventory[count].desc, strtok(NULL,","));
		// assigns product price to the product within the product list
		product_list->inventory[count].price = atof(strtok(NULL,","));
		// assigns product quantity to the product within the product list
		product_list->inventory[count].quantity = atoi(strtok(NULL,","));
		count++;
	}
}

void printProducts(product_array_t product_list){
	int i;
	for(i = 0; i < 4; i++){
		printf("Type: %s ID: %s Description: %s Price: %.2lf Quantity: %d\n",
				product_list.inventory[i].type,
				product_list.inventory[i].id,
				product_list.inventory[i].desc,
				product_list.inventory[i].price,
				product_list.inventory[i].quantity);
	}
}


