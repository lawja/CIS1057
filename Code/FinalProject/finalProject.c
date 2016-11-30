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
	char product_id[50];
	int quantity;
}order_t;

typedef struct{
	product_t inventory[100];
	int count;
}product_array_t;

typedef struct{
	order_t array[100];
	int count;
}order_array_t;

void read_products(char filename[], product_array_t *product_list);
void read_orders(char filename[], order_array_t *order_list);
void print_product(product_array_t product_list, int index);
void printProducts(product_array_t product_list);
void printOrder(order_array_t order_list, int index);
void printOrders(order_array_t order_list);
void sortProducts(product_array_t *product_list);
void swap(product_array_t *product_list, int index1, int index2);
int id_lessThan(char id_1[], char id_2[]);

int main(){
	product_array_t product_list;
	product_list.count = 0;

	order_array_t order_list;
	order_list.count = 0;

	read_products("files/Products.csv", &product_list);
	printProducts(product_list);
	printf("\n");
	read_orders("files/Orders.csv", &order_list);
	printOrders(order_list);
	sortProducts(&product_list);
	printf("\nSorted Orders\n");
	printProducts(product_list);
	return 0;
}

void read_products(char filename[], product_array_t *product_list){
	char buff[MAX_LENGTH];

	FILE *products_in = fopen(filename, "r");

	if(products_in == NULL){
		printf("Error: File contains no data\n");
		return;
	}

	while(fgets(buff,MAX_LENGTH,products_in) != NULL){
		// assigns product type to the product in the product list
		strcpy(product_list->inventory[product_list->count].type, strtok(buff,","));

		// assigns product id to the product in the product list
		strcpy(product_list->inventory[product_list->count].id, strtok(NULL,","));

		// assigns product type to the description in the product list
		strcpy(product_list->inventory[product_list->count].desc, strtok(NULL,","));

		// assigns product price to the product within the product list
		product_list->inventory[product_list->count].price = atof(strtok(NULL,","));

		// assigns product quantity to the product within the product list
		product_list->inventory[product_list->count].quantity = atoi(strtok(NULL,","));
		// count increment to keep track of the size of the array
		product_list->count++;
	}

	printf("Read %d products.\n", product_list->count);

	fclose(products_in);
}

void read_orders(char filename[], order_array_t *order_list){
	char buff[MAX_LENGTH];

	FILE *orders_in =  fopen(filename, "r");

	if(orders_in == NULL){
		printf("Error: File contains no data\n");
		return;
	}

	while(fgets(buff,MAX_LENGTH,orders_in)){
		order_list->array[order_list->count].order_id = atoi(strtok(buff,","));
		strcpy(order_list->array[order_list->count].product_id, strtok(NULL,","));
		order_list->array[order_list->count].quantity = atoi(strtok(NULL,","));
		order_list->count++;
	}

	printf("Read %d orders.\n", order_list->count);

}

void print_product(product_array_t product_list, int index){
	printf("%s - %s - %s - %.2lf - %d\n",
				product_list.inventory[index].type,
				product_list.inventory[index].id,
				product_list.inventory[index].desc,
				product_list.inventory[index].price,
				product_list.inventory[index].quantity);
}

void printProducts(product_array_t product_list){
	int i;
	for(i = 0; i < product_list.count; i++){
		print_product(product_list, i);
	}
}

void printOrder(order_array_t order_list, int index){
	printf("%d - %s - %d\n",
				order_list.array[index].order_id,
				order_list.array[index].product_id,
				order_list.array[index].quantity);
}

void printOrders(order_array_t order_list){
	int i;
	for(i = 0; i < order_list.count; i++){
		printOrder(order_list, i);
	}
}

void sortProducts(product_array_t *product_list){
	int i;
	for(i = product_list->count - 1; i > 0; i--){
		int j;
		for(j = i - 1; j >= 0; j--){
			if(id_lessThan(product_list->inventory[i].id,product_list->inventory[j].id)){
				product_t temp = product_list->inventory[j];
				product_list->inventory[j] = product_list->inventory[i];
				product_list->inventory[i] = temp; 
			}
		}
	}
	//swap(product_list, 1, 0);
	//printProducts(product_list);
}

void swap(product_array_t *product_list, int index1, int index2){
	product_t temp = product_list->inventory[index1];
	product_list->inventory[index1] = product_list->inventory[index2];
	product_list->inventory[index2] = temp;
}

int id_lessThan(char id_1[], char id_2[]){
	if(id_1[0] < id_2[0]){
		return 1;
	}else{
		char id_num_1[strlen(id_1)-1];
		int i;
		for(i = 1; i < strlen(id_1);i++){
			id_num_1[i - 1] = id_1[i];
		}
		char id_num_2[strlen(id_2)-1];
		int j;
		for(j = 1; j < strlen(id_2);j++){
			id_num_2[j - 1] = id_2[j];
		}
		int id_num_1_i = atoi(id_num_1);
		int id_num_2_i = atoi(id_num_2);

		return (id_num_1_i < id_num_2_i);
	}
}

