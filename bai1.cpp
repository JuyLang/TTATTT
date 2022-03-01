//bieu dien A thanh mang
#include <stdio.h>
#include <math.h>
#include  <stdlib.h>
void ConvertArray(unsigned long long a, unsigned long long A[100], int t, int w){
	int i;
    for(i=t-1;i>=0;i--){
        unsigned long long log = pow(2 ,(i*w));
        A[i]= a / log;
        a = a - (log*A[i]);
        printf("%llu ", A[i]);	 
	}
}
int main() {
    int w;
    unsigned long long p, a, A[100];
    printf("Nhap vao p ");
    scanf("%llu", &p);
    printf("Nhap vao w ");
    scanf("%d", &w);
    printf("Nhap vao a ");
    scanf("%llu", &a);
    float m = ceil (log(p)/log(2));
    int t = ceil (m/w);
    ConvertArray(a, A, t, w);
    return 0;
}
