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
char smallest_character_iterative(char str[], char c)
{
    int i;
    for( i = 0; str[i]!=127; i++) {
        if( str[i] > c)
            return str[i];
    }
    return str[0];
}
char smallest_character_recursive(char str[], char c, int len)
{
    if(str[len-1] > c)
        return smallest_character_recursive(str, c, len-1);
    else if(len == 0 || len == strlen(str)) {
        return str[0];
    } else
        return str[len];

}
int main()
{
    FILE *fp;
    struct timespec start, end;
    char buffer[1024];
    int i = 0,c=0;
    double cpu_time1,cpu_time2;
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
    int k;
    char x;
    FILE *fw = fopen("orig_time_recursive.txt", "w");
    FILE *fw2 = fopen("orig_time_iterative.txt", "w");
    for(k=97; k<=122; k++) {

        int j;
        clock_gettime(CLOCK_REALTIME, &start);
        for( j=0; j<1000; j++) {
            smallest_character_recursive(str,k,i);
        }
        clock_gettime(CLOCK_REALTIME, &end);
        cpu_time1 = diff_in_second(start, end);
        clock_gettime(CLOCK_REALTIME, &start);
        for( j=0; j<1000; j++) {
            x=smallest_character_iterative(str,k);
        }
        clock_gettime(CLOCK_REALTIME, &end);
        cpu_time2 = diff_in_second(start, end);
        printf("execution time of recursive() : %lf sec   answer=%c \n", cpu_time1,x);
        printf("execution time of iterative() : %lf sec\n", cpu_time2);
        fprintf(fw, "%d %lf\n",k-96, cpu_time1);
        fprintf(fw2, "%d %lf\n",k-96, cpu_time2);

    }
    fclose(fw);
    fclose(fw2);
    return 0;
}

