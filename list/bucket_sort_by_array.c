#include <stdio.h>
#include <stdlib.h>

int find_max(int A[], int N) {
    int i, max;
    max= A[0];
    for(i=1; i<N; i++) {
        if(A[i] > max) {
            max = A[i];
        }
    }

    return max;
}

void bucket_sort(int A[], int N) {
    int i, M;
    M = find_max(A, N);
    int count[10];

    for(i=0; i<=M; i++) {
        count[i] = 0;
    }

    for(i=0; i<N; i++) {
        count[A[i]]++;
    }

    for(i=0; i<=M; i++) {
        while(count[i] > 0) {
            printf("%d ", i);
            count[i]--;
        }
    }

    printf("\n");
}

int main(void) {
    int i;
    int A[] = {3,2,4,5,8,1,7,6,2};
    printf("before sorted: ");
    for(i=0; i< 9; i++) {
        printf("%d ",A[i]);
    }
    printf("\nafter sorted:");
    bucket_sort(A, 9);

    system("pause");   //防止闪退
    return 0;
}