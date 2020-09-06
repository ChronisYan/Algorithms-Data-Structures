#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE 1

char *reverseWords(char *text)
{
    // allocate memory to hold the reversed string
    char *result;
    result = (char *)malloc(sizeof(char) * strlen(text));
    if (result == NULL)
    {
        printf("Memory Allocation error");
        exit(1);
    }

    int i = 0;
    char *lastChar = (text + strlen(text) - 1);
    while (TRUE)
    {
        char *curPos = (result + i);
        char *curChar = (lastChar - i);

        *curPos = *curChar;
        if (curChar == text)
            break;

        i++;
    }
    return result;
}

int main()
{
    char string[] = "Hello World!";
    char *str = string;

    char *reversedStr = reverseWords(str);

    // print string and reversed string
    printf("%s\n", string);
    while (*reversedStr) // *reversedStr != '\0', but '\0' is falsy
    {
        printf("%c", *reversedStr);
        reversedStr++;
    }
    printf("\n");
    return 0;
}
