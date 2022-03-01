// hieu cx A B
#include <stdio.h>
#include <math.h>
#include  <stdlib.h>
void ConvertArray(unsigned long long a, unsigned long long A[100], int t, int w){
    for( int i=t-1;i>=0;i--){
        unsigned long long log = pow(2 ,(i*w));
        A[i]= a / log;
        a = a - (log*A[i]);
        printf("%llu ", A[i]);	 
	}
	printf("\n");
}
int mod(int k, int w){
    int r = k % 256;
    return r < 0 ? r + 256 : r; // neu r <0 dung thi tra ve r + 256.  Sai thi tra ve r
}
void Subtraction(unsigned long long A[100],unsigned long long B[100],unsigned long long C[100], int t, int w){
	int e;
	unsigned long long log = pow(2 ,w);
	for(int i = 0 ; i <= t-1; i++){
		C[i] = (A[i] - B[i] - e);
		if(C[i]>=0){
			C[i] = mod(C[i], w);
			e = 0;
			}
		else{
			C[i] = mod(C[i], w);
			e = 1;
		}
	}
	printf("mang a - b  = (e = %d),", e);
	for( int i=t-1;i>=0;i--){
        printf("%llu ", C[i]);	 
	}
}
int main() {
    int w = 8;
    unsigned long long p = 2147483647, a = 38762497 , b = 568424364, A[100], B[100], C[100];
//    printf("Nhap vao p ");
//    scanf("%llu", &p);
//    printf("Nhap vao w ");
//    scanf("%d", &w);
    float m = ceil (log(p)/log(2));
    int t = ceil (m/w);
//    printf("Nhap vao a ");
//    scanf("%llu", &a);
	printf("a Chuyen sang mang =  "); ConvertArray(a, A, t, w);
//    printf("Nhap vao b ");
//    scanf("%llu", &b);
    printf("b Chuyen sang mang =  ");  ConvertArray(b, B, t, w);
    Subtraction(A, B, C, t, w);
    return 0;
}
