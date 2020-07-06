#include <stdio.h>
#include <stdlib.h>

//最小子序列问题

//复杂度为O(N2)
int MaxSubsequenceSumN3(const int A[],int N) {
    int thisSum, maxSum, i, j, k;
    int start = 0,end = 0;
    maxSum = A[0];                  //可以先判断下数组是否为空,不为空再赋值
    for(i = 0; i < N; i++) {
        for(j = i; j < N; j++) {
            thisSum = 0;
            for(k = i; k <= j; k++) {
                thisSum += A[k];
            }
            if(thisSum > maxSum) {
                maxSum = thisSum;
                start = i;
                end = j;
            }
        }
    }
    printf("startd and end of max sub seq:%d,%d\n",start,end);
    
    return maxSum;
}

//复杂度为O(N2)
int MaxSubsequenceSumN2(const int A[],int N) {
    int thisSum, maxSum, i, j, k;
    int start = 0,end = 0;
    maxSum = A[0];
    for(i = 0; i < N; i++) {
        thisSum = 0;
        for(j = i; j < N; j++) {
            thisSum += A[j];
            if(thisSum > maxSum) {
                maxSum = thisSum;
                start = i;
                end = j;
            }
        }
    }
    printf("startd and end of max sub seq:%d,%d\n",start,end);
    
    return maxSum;
}

//复杂度为O(NlgN)
int MaxSubsequenceSumNLgN(const int arr[], int left, int right) {
    if(left == right) {
        return arr[left];
    }

    int mid = (left + right) / 2;
    int leftMaxSum = MaxSubsequenceSumNLgN(arr, left, mid);     //左半部分最大子序列值
    int rightMaxSum = MaxSubsequenceSumNLgN(arr, mid+1, right); //右半部分最大子序列值

    int leftMaxBorderSum, rightMaxBorderSum;
    int leftBorderSum = 0, rightBorderSum = 0;

    //左边部分中包含最右边元素的最大子序列值
    leftMaxBorderSum = arr[mid];
    for(int i = mid; i >= left; i--) {
        leftBorderSum += arr[i];
        if(leftBorderSum > leftMaxBorderSum) {
            leftMaxBorderSum = leftBorderSum;
        }
    }
    //右半部分中包含最左边元素的最大子序列值
    rightMaxBorderSum = arr[mid+1];
    for(int i = mid+1; i <= right; i++) {
        rightBorderSum += arr[i];
        if(rightBorderSum > rightMaxBorderSum) {
            rightMaxBorderSum = rightBorderSum;
        }
    }

    //跨越中部的最大子序列值
    int leftAndRight = leftMaxBorderSum + rightMaxBorderSum;

    //返回左半部分最大子序列，右半部分最大子序列，跨越中间最大子序列，三个中最大的一个
    if(leftMaxSum > rightMaxSum) {
        return ((leftMaxSum > leftAndRight) ? leftMaxSum : leftAndRight);
    } else {
        return((rightMaxSum > leftAndRight) ? rightMaxSum : leftAndRight);
    }
}
//算法复杂度为O(N)
int MaxSubsequenceSumN(const int arr[], int N) {
    int thisSum = 0;
    int maxSum = 0;        //并非所有元素都是负数时的返回结果
    int eleMax = arr[0];   //用来记录数组中的最大值，如果所有元素都为负数，就返回这个值
    int negNum = 0;        //用来记录负数个数
    for(int i = 0; i < N; i++) {
        thisSum += arr[i];
        if(thisSum > maxSum) {
            maxSum = thisSum; 
        }
        if(arr[i] > eleMax) {
            eleMax = arr[i];
        }
        if(thisSum < 0) {
            thisSum = 0;
            negNum++;
        }
    }
    if(negNum == N) {
        return eleMax;
    } else {
        return maxSum;
    }
}

int main(void) {
    int arr[] = {-2 ,2, -1, 3};
    printf("%d\n",MaxSubsequenceSumN(arr, 4));
    system("pause");   //防止闪退
    return 0;
}
