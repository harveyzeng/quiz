/* FIXME: Implement! */
// A utility funtion to find maximum of two integers
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
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
int max_2(int a, int b)
{
    return (a > b)? a : b;
}

// A utility funtion to find maximum of three integers
int max_3(int a, int b, int c)
{
    return max_2(max_2(a, b), c);
}

// Find the maximum possible sum in arr[] auch that arr[m] is part of it
int maxCrossingSum(int arr[], int l, int m, int h)
{
    // Include elements on left of mid.
    int sum = 0;
    int left_sum = INT_MIN;
    int i;
    for (i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for ( i = m+1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    // Return sum of elements on left and right of mid
    return left_sum + right_sum;
}

// Returns sum of maxium sum subarray in aa[l..h]
int maxSubArraySum(int arr[], int l, int h)
{
    // Base Case: Only one element
    if (l == h)
        return arr[l];

    // Find middle point
    //int m = (l + h)/2;

    /* Return maximum of following three possible cases

       a) Maximum subarray sum in left half

       b) Maximum subarray sum in right half

       c) Maximum subarray sum such that the subarray crosses the midpoint */

    return max_3(maxSubArraySum(arr, l, ((l + h)/2)),
                 maxSubArraySum(arr, ((l + h)/2)+1, h),
                 maxCrossingSum(arr, l, ((l + h)/2), h));
}

int maxSubArray_recursive(int* s, int ns)
{
    maxSubArraySum(s, 0,ns-1);
}
int maxSubArray_iterative(int* s, int ns)
{
    int t = 0;
    int max = s[0];
    int i;
    for ( i = 0; i < ns; ++i) {
        if (t>0)
            t += s[i];
        else
            t = s[i];
        max = max > t ? max : t;
    }
    return max;
}
int main()
{
    struct timespec start, end;
    double cpu_time1,cpu_time2;
    int k,l;
    FILE *fw = fopen("orig_time_recursive.txt", "w");
    FILE *fw2 = fopen("orig_time_iterative.txt", "w");
    srand(time(NULL));
    for(k=1; k<100; k++) {
        int arr[k];
        for(l=0; l<k; l++) {
            arr[l]=(rand()%100)-50;
        }
        int len = sizeof(arr) / sizeof(arr[0]);
        int j;
        int answer;
        clock_gettime(CLOCK_REALTIME, &start);
        for( j=0; j<1000; j++) {
            maxSubArray_recursive(arr, len);
        }
        clock_gettime(CLOCK_REALTIME, &end);
        cpu_time1 = diff_in_second(start, end);
        clock_gettime(CLOCK_REALTIME, &start);
        for( j=0; j<1000; j++) {
            answer=maxSubArray_iterative(arr, len);
        }
        clock_gettime(CLOCK_REALTIME, &end);
        cpu_time2 = diff_in_second(start, end);
        printf("execution time of recursive() : %lf sec answer= %d\n", cpu_time1,answer);
        printf("execution time of iterative() : %lf sec\n", cpu_time2);
        fprintf(fw, "%d %lf\n",k, cpu_time1);
        fprintf(fw2, "%d %lf\n",k, cpu_time2);
    }
    fclose(fw);
    fclose(fw2);
    // int max = maxSubArray(arr, len);
    // printf("Maximum contiguous sum = %d\n", max);
    return 0;
}
