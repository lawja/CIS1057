#include <stdio.h>

#define MAX_LENGTH 100
#define MAX_READ 200

// Struct to contain person data
typedef struct{
    char first_name[20];
    char last_name[20];
    int age;
}person_t;

// Struct to contain an array of person
typedef struct{
    int length;
    int count;
    person_t array[MAX_LENGTH];
} person_array_t;


// Prototypes
void print_person(person_t p);
void print_persons(person_array_t);


int main(){

    // Create a person Bob
    person_t p = {"Bob","Smith",30};
    // Pointer to Bob
    person_t *pptr = &p;
    // Print Bob
    printf("%s %s %d %d\n", p.first_name, p.last_name, p.age, &p);
    // Print Bob from pointer
    printf("%s %s %d %d\n", pptr->first_name, pptr->last_name, pptr->age, pptr);

    // Print data and memory addresses
    printf("%s %d\n", p.first_name, &p.first_name);
    printf("%s %d\n", p.last_name, &p.last_name);
    printf("%d %d\n", p.age, &p.age);

    // Print size of a person in bytes
    printf("%d\n", sizeof(person_t));

    // Example for strtok on a string
    char s[] = {"1,Bob,1234 Grant Ave,Phila\n"};
    // Remove newline at end of string
    s[strlen(s)] = '\0';
    printf("\n\n|%s|\n", s);
    // Tokenize string with strtok
    char *pch1 = strtok(s, ",");
    printf("%s\n", pch1);
    char *pch2 = strtok(NULL, ","); // Note that this is NULL after first call
    printf("%s\n", pch2);
    char *pch3 = strtok(NULL, ",");
    printf("%s\n", pch3);
    char *pch4 = strtok(NULL, ",");
    printf("%s\n", pch4);

    // Print tokenized variable addresses
    printf("%d %d %d %d \n\n", pch1, pch2, pch3, pch4);

    // Declare and initialize an array of person
    person_array_t p_arr;
    p_arr.length = MAX_LENGTH;
    p_arr.array[0] = p;
    person_t p1 = {"Jane","Doe",25};
    p_arr.array[1] = p1;
    person_t p2 = {"Homer","Simpson",45};
    p_arr.array[2] = p2;
    p_arr.count = 3;

    // Print one person
    print_person(p_arr.array[1]);
    printf("\n\n");

    // Print array
    print_persons(p_arr);


    return 0;
}


void print_person(person_t p){
    printf("%s %s %d", p.first_name, p.last_name, p.age);
}


void print_persons(person_array_t arr){
    int i = 0;
    printf("count = %d\n", arr.count);
    for(i=0; i<arr.count; i++){
        print_person(arr.array[i]);
        printf("\n");
    }
}
