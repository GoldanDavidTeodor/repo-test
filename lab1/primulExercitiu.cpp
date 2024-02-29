#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int turnIntoNumber(char line[1000])
{
    int n=0;
    int c=0;
    for(int i=0; line[i]!='\0'; i++)
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            c = line[i]-'0';
            n=n*10+c;
        }
    }
    return n;
}

int main()
{
    int s = 0;
    FILE* file;
    char line[1000];

    file = fopen("in.txt", "r");

    if (file == NULL)
    {
        printf("Eroare la deschiderea fisierului.\n");
        return 1;
    }

    while (fgets(line, 100, file) != NULL)
        s=s+turnIntoNumber(line);

    printf("%d", s);

    fclose(file);

    return 0;
}
