/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char smallest_character(char str[], char c, int len)
{
    if(str[len-1] > c)
        return smallest_character(str, c, len-1);
    else if(len == 0 || len == strlen(str)) {
        return str[0];
    } else
        return str[len];

}

int main()
{
    FILE *fp;
    char buffer[1024];
    int i = 0,c=0;
    fp = fopen("str_array.txt","r");
    if( fp == NULL)
        printf("Open failure\n");
    else {
        for(c = fgetc(fp); c != EOF ; i++) {
            buffer[i] = c;
            c = fgetc(fp);
        }
    }
    fclose(fp);
    char str[i];
    strncpy(str,buffer,i);
    char character = smallest_character(str,'a',i);
    printf("%c\n", character);
    return 0;
}

