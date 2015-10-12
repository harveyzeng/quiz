/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char smallest_character(char str[], char c)
{
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if( str[i] > c)
			return str[i];
	}
	return str[0];
}

int main()
{
	FILE *fp;
	char buffer[1024];
	int i = 0,c=0;
	fp = fopen("str_array.txt","r");
	if( fp == NULL)
		printf("Open failure\n");
	else{
		for(c = fgetc(fp); c != EOF ; i++){
			buffer[i] = c;
			c = fgetc(fp);
		}
	}
	fclose(fp);
	char str[i];
	strncpy(str,buffer,i);
	char character = smallest_character(str,'d');
	printf("%c\n", character);
    return 0;
}
