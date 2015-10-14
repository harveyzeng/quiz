/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>

int maxSubArray(int* s, int ns)
{
    int t = 0;
    int max = s[0];
    for (int i = 0; i < ns; ++i) {
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
    int arr[]= {-2,1,-3,4,-1,2,1,-5,4};
    int len = sizeof(arr) / sizeof(arr[0]);
    maxSubArray(arr, len);
    // int max = maxSubArray(arr, len);
    // printf("Maximum contiguous sum = %d\n", max);
    return 0;
}
