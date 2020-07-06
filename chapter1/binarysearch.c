//二分查找

#include<stdio.h>
#include<stdlib.h>
#define NotFound -1;
/**
 * @parameter:arr 输入数组
 * @parameter:x 要查找的值
 * @parameter:N 数组长度
 * @return 如果arr存在元素等于x，返回该元素的位置,不存在则返回-1
**/
int binarySearch(const int arr[], int x, int N) {
    int low, mid, high;
    low = 0;
    high = N - 1;
    while(low <= high) {  //这里考虑了数组长度为1的情况和数组长度为0的情况
        mid = (low + high) / 2;
        if(arr[mid] > x) {
            high = mid -1;
        } else if(arr[mid] < x) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return NotFound;
}

int main(void) {
    int arr[] = {5,7,8,20};
    printf("%d\n",binarySearch(arr, 5, 4));
    system("pause");
    return 0;
}