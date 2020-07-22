#include <stdio.h>
#include <stdlib.h>

// A pointer is a variable that stores an address of data in memory instead of the date itself
// pointers can access the heap and resources that are outside the program

int main()
{
    // data varibale
    int a = 10;
    // pointer varibale (a pointer variable also occupies memory itself)
    int *aptr;

    aptr = &a; // adress of a

    // dereferencing
    int b = *aptr;
    printf("%d", b);

    // all variables are store in the stack
    // If you want to store something in heap you need to use malloc from <stdlib.h>
    // allocate the size of five ints in heap
    int *heap_var;
    heap_var = (int *)malloc(5 * sizeof(int));
    // in c++
    // heap_var = new int[5];

    return 0;
}