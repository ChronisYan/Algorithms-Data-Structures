#include <stdio.h>

// structs can be used to define our own custon data types

// struct definition (don't occupy memory)
struct Rectangle
{
    int length;
    int width;
};

int main()
{

    // struct declaration (take as much memory as the sum of the memory occupied by each of its members)
    struct Rectangle rect1;

    // struct declaration and initialization
    struct Rectangle rect2 = {10, 5};

    // accessing members of a struct
    rect1.length = 90;
    rect1.width = 45;
    rect2.width = 15;

    // Array of structs
    struct Rectangle rect_list[3] = {{2, 4}, {50, 4}, rect2};

    printf("Area of rect2: %d\n", rect_list[2].length * rect_list[2].width);

    return 0;
}