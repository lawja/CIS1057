/*
 * Title: Project 7
 * Programmer: Christopher Lawrence      Date completed: 10/30/2016
 * Instructor: Professor Joe Jupin       Class: CIS1057
 *
 * Description of program:
 * Implements various functions to demonstrate not only the purposee
 * of arrays but also their capabilities
 */

// preprocessor directives
#include <stdio.h>
#include <ctype.h>

// constants
#define COUNT 10
#define COUNT_COLS 5
#define COUNT_ROWS 3

// function declarations
void printArray(int a[]);
int sumArray(int a[]);
int equals(int a[], int b[]);
int isSorted(int a[]);
void bubbleSort(int a[]);
int binarySearch(int a[], int value);
void printMatrix(int a[COUNT_ROWS][COUNT_COLS]);
int sumRow(int a[COUNT_ROWS][COUNT_COLS], int rowIndex);
int sumCol(int a[COUNT_ROWS][COUNT_COLS], int colIndex);
int sumMatrix(int a[COUNT_ROWS][COUNT_COLS]);

int main() {
    // arrays of size COUNT
    int array1[COUNT] = {5, 9, 3, 1, 7, 2, 8, 0, 4, 6};
    int array2[COUNT] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // array with no elements
    int array3[COUNT];
    
    // printing of arrays 1 and 2
    printf("Array 1: ");
    printArray(array1);
    printf("Array 2: ");
    printArray(array2);
    
    // checking array equivalencies
    printf("Array 1 equals Array 2: %d\n", equals(array1, array2));
    printf("Array 1 equals Array 1: %d\n", equals(array1, array1));
    
    // checking if arrays are sorted
    printf("Array 1 isSorted: %d\n", isSorted(array1));
    printf("Array 2 isSorted: %d\n", isSorted(array2));
    
    // sorting of arrays using bubble sort
    printf("array 1 unsorted: ");
    printArray(array1);
    bubbleSort(array1);
    printf("array 1 sorted: ");
    printArray(array1);
    
    // value to be searched for
    int v;
    // prompting of user for value to search for
    printf("What value would you like to search for? ");
    scanf("%d", &v);
    // demonstrates that unsorted arrays will be sorted
    printf("Index of %d in array 1 is: %d\n", v, binarySearch(array1, v));
    printf("Index of %d in array 2 is: %d\n", v, binarySearch(array2, v));
    
    // 2d array of COUNT_ROWS x COUNT_COLS size
    int matrix[COUNT_ROWS][COUNT_COLS] = {{1, 2, 3, 4, 5}, {2, 4, 6, 8, 10}, {3, 6, 9, 12,
        15}};
    
    // printing of matrix
    printf("Matrix:\n");
    printMatrix(matrix);
    
    // row index, for input
    int ri;
    // gives the sum of the row thaat the user desired
    printf("What row in the matrix would you like to find the sum of? ");
    scanf("%d", &ri);
    printf("Sum of row %d in matrix: %d\n", ri, sumRow(matrix, ri));
    
    // column index, for input
    int ci;
    // gives the sum of the column thaat the user desired
    printf("What column in the matrix would you like to find the sum of? ");
    scanf("%d", &ci);
    printf("Sum of col %d in matrix: %d\n", ci, sumCol(matrix, ci));
    
    // sum of the entire matrix
    printf("Sum of matrix: %d\n", sumMatrix(matrix));
    
    return 0;
}

// prints the given array
void printArray(int a[]){
    printf("[");
    
    int i = 0;
    for(i = 0; i < COUNT; i++){
        printf("%d", a[i]);
        if(i != COUNT - 1)
            printf(", ");
    }
    printf("]\n");
}

// returns the sum of the elements within the given array
int sumArray(int a[]){
    int i = 0;
    int sum = 0;
    for(i = 0; i < COUNT; i++){
        sum += a[i];
    }
    return sum;
}

// compares two arrays, returns true if they contain the same elements and are in the same order
int equals(int a[], int b[]){
    int i = 0;
    for(i = 0; i < COUNT; i++){
        if(a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}

// returns two if the array is sorted in ascending order
int isSorted(int a[]){
    int i = 0;
    for(i = 0; i < COUNT - 1; i++){
        if(a[i] >= a[i+1])
            return 0;
    }
    return 1;
}

// sorts the array using the bbble sort algorithm
void bubbleSort(int a[]){
    int i = 0;
    int j = 0;
    for(i = COUNT - 1;i > 0; i--){
        for(j = i - 1; j >= 0; j--){
            if(a[i] < a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// returns the index of the given value within the given array
int binarySearch(int a[], int value){
    int left = 0, right = COUNT - 1;
    int middle = right / 2;
    
    if(isSorted(a) == 0)
        bubbleSort(a);
    
    while(right >= left){
        if(a[middle] == value){
            return middle;
        }
        if(a[middle] < value)
            left = middle + 1;
        if(a[middle] > value)
            right = middle - 1;
        middle = (right + left) / 2;
    }
    
    return -1;
}

// prints the given matrix
void printMatrix(int a[COUNT_ROWS][COUNT_COLS]){
    int i = 0, j = 0;
    
    for(i = 0; i < COUNT_ROWS; i++){
        for(j = 0; j < COUNT_COLS; j++){
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }
}

// returns the sum of the row chosen by index from the given matrix
int sumRow(int a[COUNT_ROWS][COUNT_COLS], int rowIndex){
    int i = 0;
    int sum = 0;
    for(i = 0; i < COUNT_COLS;i++){
        sum += a[rowIndex][i];
    }
    return sum;
}

// returns the sum of the column chosen by index from the given matrix
int sumCol(int a[COUNT_ROWS][COUNT_COLS], int colIndex){
    int i = 0;
    int sum = 0;
    for(i = 0; i < COUNT_ROWS;i++){
        sum += a[i][colIndex];
    }
    return sum;
}

// returns the sum of the given matrix
int sumMatrix(int a[COUNT_ROWS][COUNT_COLS]){
    int i = 0, j = 0;
    int sum = 0;
    
    for(i = 0; i < COUNT_ROWS; i++){
        for(j = 0; j < COUNT_COLS; j++){
            sum += a[i][j];
        }
    }
    return sum;
}
