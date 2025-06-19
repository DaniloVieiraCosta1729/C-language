#include <stdio.h>

int main(int argc, char const *argv[])
{
    int vector[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    printf("Diagonal\n");
/*
    for (int i = 0; i < 9; i += 4)
    {
        printf("%d ", vector[i]);
    }
*/
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", matrix[i][i]);
    }

    return 0;
}
