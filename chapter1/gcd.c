//欧几里得求余数
#include <stdio.h>
#include <stdlib.h>

unsigned int gcd(unsigned int m, unsigned int n) {
    unsigned int rem;
    while(n > 0) {
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

int main(void) {
    printf("%d\n",gcd(76, 70));
    system("pause");   //防止闪退
    return 0;
}