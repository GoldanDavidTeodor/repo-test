#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int compareLetters(char a[100], char b[100], int lg)
{
    for(int i=0; i<lg; i++)
    {
        if(a[i]>b[i]) return 1;
        else if(a[i]<b[i]) return -1;
    }
    return 0;
}

char words[100][100];
int lenght[100];
int main()
{
    int j=0;
    int k=0;
    char sentence[100];
    FILE *file = fopen("in.txt", "r");

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    if (fscanf(file, " %[^\n]", sentence) == 1)
    {
        for(int i=0; sentence[i]!='\0'; i++)
        {
            if(sentence[i]==' ')
            {
                lenght[k]=j;
                k++;
                j=0;
            }
            else
            {
                words[k][j]=sentence[i];
                j++;

            }
        }
        //printf("%s\n", sentence);
    }
    else
    {
        printf("Error reading from the file.\n");
    }

    for(int i=0; i<k; i++)
        for(int l=i+1; l<=k; l++)
            if(lenght[i]<lenght[j])
            {
                std::swap(words[i], words[j]);
                std::swap(lenght[i], lenght[j]);
            }
    for(int i=0; i<k; i++)
        for(int l=i+1; l<=k; l++)
        {
            if(lenght[i]==lenght[l])
                if(compareLetters(words[i], words[l], lenght[i])==1)
                {
                    std::swap(words[i], words[j]);
                    std::swap(lenght[i], lenght[j]);
                }
        }
    for(int i=0; i<=k; i++)
        printf("%s\n", words[i]);
    fclose(file);

    return 0;
}

