#include <stdio.h>
#include <stdlib.h>

// A pointer is a variable that stores an address of data in memory instead of the date itself
// pointers can access the heap and resources that are outside the program

struct Rectangle
{
    int width;
    int length;
};

int main()
{
    // data varibale
    int a = 10;
    // pointer varibale (a pointer variable also occupies memory itself)
    int *aptr;

    aptr = &a; // adress of a

    // dereferencing
    int b = *aptr;
    printf("%d\n", b);

    // all variables are store in the stack
    // If you want to store something in heap you need to use malloc from <stdlib.h>
    // allocate the size of five ints in heap
    int *heap_var;
    heap_var = (int *)malloc(5 * sizeof(int));
    // in c++
    // heap_var = new int[5];

    // pointers structs
    // A pointer takes as much memory as a int, no matter what it points to
    struct Rectangle r = {20, 40};
    struct Rectangle *r_ptr = &r;

    // accessing the struct from a pointer
    // the () is necessary if you don't use the array operator
    (*r_ptr).length = 25;
    r_ptr->width = 50;

    // Dynamic struct in heap
    struct Rectangle *p;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p->length = 10;
    p->width = 20;

    printf("Length: %d, Width: %d\n", p->length, p->width);

    return 0;
}