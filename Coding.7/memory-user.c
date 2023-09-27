/********************
Josh Heigley

This program creates an array in memory, cycles through each location in the array and assigns a value to each locatation in memory. The program cycles indefi
nately until the user
ends the program.
*********************/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  // Checks that you have passed an argument
    if (argc != 2) {
        printf ("Invalid argument \n");
        exit(1);
    }

  // initializes the variable for the memory size allotment
    int mem_size = atoi(argv[1]);
    printf ("The size you have chosen is %i \n", mem_size);

  // Creates the array in memory
    int *mem_array = malloc(mem_size * sizeof(int));

    printf ("%i\n", (int) getpid());

  // Loops indefinately
    while (1) {

      // Cycles through each location in memory and writes to that location
        for (int i = 0; i < mem_size; ++i) {

            mem_array[i] = 1;
//            printf ("%p\n", &mem_array[i]);
        }
    }
  // This will never be reached
    return 0;
}
