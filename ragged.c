#include <stdio.h>
#include <stdlib.h>
void main()
{
    int rowNum, colNum, i, j;
    int **table;
    printf("\n Enter the number of rows \n");
    scanf("%d", &rowNum);
    table = (int **)calloc(rowNum, sizeof(int *));
    for (i = 0; i < rowNum; i++)
    {
        printf("\nEnter size of %d row :\n", i + 1);
        scanf("%d", &colNum);
        *(table + i) = (int *)calloc(colNum, sizeof(int));
        printf("\nEnter %d row elements ", i + 1);
        for (j = 1; j <= colNum; j++)
        {
            scanf("%d", (*(table + i) + j));
        }
        table[i][0] = colNum;
    }
    for (i = 0; i < rowNum; i++)
    {
        for (j = 1; j <= *table[i]; j++)
        {
            printf("  %d", table[i][j]);
        }
        printf("\n");
    }
}
