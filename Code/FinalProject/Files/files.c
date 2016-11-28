#include <stdio.h>

#define MAX_LENGTH 100
#define MAX_READ 200

// Person struct to contain data for a single person.
typedef struct{
    char first_name[20];
    char last_name[20];
    int age;
}person_t;

int main(){

    // String buffer for read
    char s[50];

    // Data for person bob
    char fn[] = "Bob";
    char ln[] = "Smith";
    int age = 30;

    // OPen a file to write
    FILE *out_file = fopen("out_filename.txt", "w");
    int i = 0; // Iterator
    // Write Bob to file 5 times
    for(i=0; i<5; i++)
        fprintf(out_file, "%s,%s,%d\n", fn, ln, age);
    // Close file
    fclose(out_file);


    // Open a file for reading
    FILE *in_file = fopen("out_filename.txt", "r");
    // Read file until no more Bob's
    while(fgets(s, 50, in_file) != NULL){
        // Put a null over the newline read from file
        s[strlen(s)-1] = '\0';
        // Print this Bob to screen
        printf("s: %s\n", s);
    }
    fclose(in_file);

    // Example of binary file write
    person_t p1 = {"Bob", "Smith", 30};
    out_file = fopen("out_filename.bin", "wb");
    fwrite(&p1, sizeof(p1), 1, out_file);
    fclose(out_file);

    // Example of binary file read
    person_t p2;
    in_file = fopen("out_filename.bin", "rb");
    fread(&p2, sizeof(p2), 1, in_file);
    fclose(in_file);

    // Print the binary file read
    printf("P2: %s %s %d\n", p2.first_name, p2.last_name, p2.age);

    return 0;
}
