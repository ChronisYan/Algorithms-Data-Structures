#include <stdio.h>
#include <stdlib.h>

// pass by value
void swap_value(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// pass by address (reference)
void swap_address(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// passing arrays as parameters (arrays are always passed by address)
void displayer(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// returning an array
int *new_array(int n)
{
    int *p;
    p = (int *)malloc(n * sizeof(int));
    return (p);
}

// passing a struct as parameter
// you can pass a struct either by value(creates a copy) or by address (modifies the original)
struct Rectangle
{
    int width;
    int length;
};
// pass by value (copy)
int area(struct Rectangle r)
{
    return r.length * r.width;
}
// pass by address (modify original)
void edit_length(struct Rectangle *r, int new_length)
{
    r->length = new_length;
}

int main()
{
    int x = 10;
    int y = 20;

    printf("x: %d, y: %d\n", x, y);

    swap_value(x, y);
    printf("Pass by value ~~ x: %d, y: %d\n", x, y);

    swap_address(&x, &y);
    printf("Pass by reference ~~ x: %d, y: %d\n", x, y);

    // working with array functions
    int *ptr;
    ptr = new_array(5); // return array and save it to ptr
    for (int i = 0; i < 5; i++)
    {
        ptr[i] = i + 1;
    }
    printf("My Array: ");
    displayer(ptr, 5); // pass array (ptr) and its length

    // structs
    struct Rectangle my_rect = {5, 10};
    edit_length(&my_rect, 20);

    int rect_area = area(my_rect);

    printf("Rectangle area: %d\n", rect_area);

    return 0;
}