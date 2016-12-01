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

int read_products(char filename[], product_array_t *product_list);
int read_orders(char filename[], order_array_t *order_list);
void print_product(product_array_t product_list, int index);
void print_products(product_array_t product_list);
void print_order(order_array_t order_list, int index);
void print_orders(order_array_t order_list);
void sort_products(product_array_t *product_list);
void swap(product_array_t *product_list, int index1, int index2);
int search_products(product_array_t *product_list, char _id[]);
double process_orders(order_array_t order_list, product_array_t *product_list);
char* write_products(product_array_t product_list);

int main(){
	// initialization of data
	product_array_t product_list;
	product_list.count = 0;

	order_array_t order_list;
	order_list.count = 0;
	
	// reading and printing of products
	int n = read_products("files/Products.csv", &product_list);
	printf("Read %d products\n", n);
	print_products(product_list);
	printf("\n");

	// reading and printing of orders
	n = read_orders("files/Orders.csv", &order_list);
	printf("Read %d orders\n", n);
	print_orders(order_list);
	sort_products(&product_list);
	
	// sorting of products
	printf("\nSorted Products\n");
	print_products(product_list);

	// search example
	char sample_id[] = "B123";
	int i = search_products(&product_list, sample_id);
	if(i != -1){
		printf("Search for product %s found at index %d\n", sample_id, i);
	}else{
		printf("Search for product %s was not found.\n", sample_id);
	}

	// processing of orders
	printf("\nProcessing Orders...\n");
	double grand_total = process_orders(order_list, &product_list);
	printf("Grand Total: %.2lf\n", grand_total);

	// shows the results of the processing
	printf("\nUpdated Products\n");
	print_products(product_list);

	// writes the changed product data to an output file
	printf("\nWriting File...\n");
	char *path_name = write_products(product_list);
	printf("File written to %s\n", path_name);

	return 0;
}

// read products from a file and write them to a product_array_t datatype
int read_products(char filename[], product_array_t *product_list){
	// reader buffer
	char buff[MAX_LENGTH];
	// input file
	FILE *products_in = fopen(filename, "r");
	// if the file contains notihing
	if(products_in == NULL){
		printf("Error: File contains no data\n");
		return -1;
	}
	// loops through the data
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

	fclose(products_in);

	return product_list->count;
}

// reads orders from a file and writes them to an order_array_t datatype
int read_orders(char filename[], order_array_t *order_list){
	// reading buffer
	char buff[MAX_LENGTH];
	// opens order file
	FILE *orders_in =  fopen(filename, "r");

	// if the file contatins nothing
	if(orders_in == NULL){
		printf("Error: File contains no data\n");
		return -1;
	}
	// reads data and writes it to order_list
	while(fgets(buff,MAX_LENGTH,orders_in)){
		// atoi converts string to int
		order_list->array[order_list->count].order_id = atoi(strtok(buff,","));
		// sets first arg to second arg
		strcpy(order_list->array[order_list->count].product_id, strtok(NULL,","));
		order_list->array[order_list->count].quantity = atoi(strtok(NULL,","));
		order_list->count++;
	}
	// returns how many orders were read
	return order_list->count;

}

// products a singular product
void print_product(product_array_t product_list, int index){
	// formatting
	printf("%s - %s - %s - %.2lf - %d\n",
				product_list.inventory[index].type,
				product_list.inventory[index].id,
				product_list.inventory[index].desc,
				product_list.inventory[index].price,
				product_list.inventory[index].quantity);
}

// prints an array of products
void print_products(product_array_t product_list){
	int i;
	for(i = 0; i < product_list.count; i++){
		print_product(product_list, i);
	}
}

// prints a singular order
void print_order(order_array_t order_list, int index){
	// formatting
	printf("%d - %s - %d\n",
				order_list.array[index].order_id,
				order_list.array[index].product_id,
				order_list.array[index].quantity);
}

// prints an array of orders
void print_orders(order_array_t order_list){
	int i;
	for(i = 0; i < order_list.count; i++){
		print_order(order_list, i);
	}
}

void sort_products(product_array_t *product_list){
	// bubble sort algorithm
	int i;
	for(i = product_list->count - 1; i > 0; i--){
		int j;
		for(j = i - 1; j >= 0; j--){
			if(strcmp(product_list->inventory[i].id,product_list->inventory[j].id) < 0){
				// swaps elements in product_list at i and j
				swap(product_list,i,j);
			}
		}
	}
}

// swaps elements at the given indexes within the product_array passed
void swap(product_array_t *product_list, int index1, int index2){
	product_t temp = product_list->inventory[index1];
	product_list->inventory[index1] = product_list->inventory[index2];
	product_list->inventory[index2] = temp;
}

int search_products(product_array_t *product_list, char _id[]){
	// binary search algorithm
	int left = 0, right = product_list->count - 1;
	int middle = right / 2;

	while(right >= left){
		// pointer use
		// strcmp returns < 0 if str1 is less than str2
		//  > 0 is str1 > str2
		//  0 if str1 == str2
		if(strcmp(product_list->inventory[middle].id, _id) == 0)
			return middle;
		if(strcmp(product_list->inventory[middle].id, _id) < 0)
			left = middle + 1;
		if(strcmp(product_list->inventory[middle].id, _id) > 0)
			right = middle - 1;
		middle = (left + right) / 2;
	}
	// if valueis not found
	return -1;
}

double process_orders(order_array_t order_list, product_array_t *product_list){
	double order_total = 0, grand_total = 0;

	int i = 0;
	// loops until the end of the order list is reached
	while(i < order_list.count){
		// finds the the index of the product in product_list from the
		// product_id within the given order
		int j = search_products(product_list, order_list.array[i].product_id);

		// logging the prices to the totals
		grand_total += product_list->inventory[j].price * order_list.array[i].quantity;
		order_total += product_list->inventory[j].price * order_list.array[i].quantity;

		// subtracting ordered products from inventory quantity
		product_list->inventory[j].quantity -= order_list.array[i].quantity;

		// if it is the last order orthe next order is a different order number
		if(i == order_list.count - 1 || order_list.array[i].order_id != order_list.array[i + 1].order_id){
			printf("Order %d is $%.2lf\n", order_list.array[i].order_id, order_total);
			// resets order_total for next order
			order_total = 0;
		}
		// incrementation
		i++;
	}
	// grand_total for the order
	return grand_total;
}

char* write_products(product_array_t product_list){
	char *file_name = "files/updated_products.csv";
	// writes to the file at desire path
	FILE *out_file = fopen(file_name, "w");

	int i = 0;
	// loops until there is no longer an element in the product list
	while(i < product_list.count){
		// gets the product
		product_t element = product_list.inventory[i];
		// formatting of the file
		fprintf(out_file, "%s,%s,%s,%.2lf,%d\n", 
				element.type,
				element.id, 
				element.desc, 
				element.price,
				element.quantity);
		// itearation for the loop
		i++;
	}
	// closes file
	fclose(out_file);

	return file_name;
}

