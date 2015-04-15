/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCode : Median of Two Sorted Arrays
*/

#include<stdio.h>


double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int C[m + n];
    int im=0, in=0, ic=0;
    while(im < m && in < n) {
        if (A[im] < B[in]) {
            C[ic++] = A[im++];
        }else{
            C[ic++] = B[in++];
        }
    }
    if(im < m) {
        while(im < m)   C[ic++] = A[im++];
    } else {
        while(in < n)   C[ic++] = B[in++];
    }

    if ((m + n) % 2) {
        return (double)C[(m + n) / 2];
    } else {
        return ((double)C[(m + n) / 2] + (double)C[(m + n) / 2 -1]) / 2 ;
    }
}

int main() {
    int A[] = {};
    int B[] = {1};
    double ans = findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int));
    printf("ans=%lf\n", ans);
    return 0;
}

