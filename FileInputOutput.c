#include<stdio.h>
int main()
{

    FILE *fp;
    char c;
    char CharFromFile[100];
    int i=0;
    fp = fopen("In.txt", "r"); // opening file In.txt in reading mode to read the text
    while((c = getc(fp)) != EOF) // The loop will run till End Of File
    {
        CharFromFile[i++] = c; //Storing the letters/characters in a string
    }

    CharFromFile[i] = '\0';
    puts(CharFromFile);

    fclose(fp); // closing In.txt



    fp = fopen("Out.txt", "w"); // opening file Out.txt in write mode
    CharFromFile[0]='C';
    CharFromFile[1]='S';
    CharFromFile[2]='E';   
    CharFromFile[3]='-';
    CharFromFile[4]='2';
    CharFromFile[5]='1';
    CharFromFile[6]='\0';
    i=0;
    while(CharFromFile[i] != NULL)
    {
        putc(CharFromFile[i], fp);
        i++;
    }

    putc('\n', fp);
//    puts(CharFromFile);
    fclose(fp); // closing Out.txt

}

