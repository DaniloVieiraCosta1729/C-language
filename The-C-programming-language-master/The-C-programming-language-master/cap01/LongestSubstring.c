#include <stdio.h>

#define MAXTEXT 100

int main(int argc, char const *argv[])
{
    char c;
    int largest = 0;
    int size = 0;

    while (((c = getchar()) != EOF))
    {
        size++;
        if ((c == ' ') || (c == '\n'))
        {
            if (size > largest)
            {
                largest = size;
            }
            
            size = 1;
        }
    }

    printf("Maior palavra: %d", largest - 1);
    
    return 0;
}
