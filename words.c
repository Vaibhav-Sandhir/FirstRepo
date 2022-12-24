#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

void main()
{
    char sent[50];
    char words[50][50] = {0};
    int i, j, k;
    j = 0;
    i = 0;
    k = 0;
    printf("\nEnter sentence: ");
    scanf("%[^\n]s", sent);
    for (i = 0; sent[i] != '\0'; i++)
    {
        if (sent[i] == ' ' && sent[i + 1] != ' ' && sent[i + 1] != '\0')
        {
            printf("%s", words[j]);
            j++;
            k = 0;
        }
        else
        {
            words[j][k] = sent[i];
            k++;
        }
    }
    printf("%s", words[j]);
}