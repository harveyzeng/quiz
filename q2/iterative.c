/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}
char smallest_character(char str[], char c)
{
	
	for(int i = 0; i < strlen(str); i++){
		if( str[i] > c)
			return str[i];
	}
	return str[0];
}

int main()
{
    FILE *fp;
    struct timespec start, end;
    char buffer[1024];
    int i = 0,c=0;
    double cpu_time1;
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
    char temp = 'k';
	clock_gettime(CLOCK_REALTIME, &start);
	for(int j=0;j<1000;j++){
        smallest_character(str,temp);}
	clock_gettime(CLOCK_REALTIME, &end);
    	cpu_time1 = diff_in_second(start, end);
	printf("execution time of recursive() : %lf sec\n", cpu_time1);
    return 0;
}

