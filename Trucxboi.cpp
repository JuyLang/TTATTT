// Tru Cx A-B
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
int check(unsigned long long P[100], unsigned long long C[100], int t){
	for(int i = t-1; i >= 0;i-- ){
		if(C[i] > P[i]){
			return true;
		}
		else{
			return false;
		}
	}
}
void SubtractiononFp(unsigned long long P[100], unsigned long long C[100], unsigned long long c[100], int t, int w){
	int e;
	unsigned long long log = pow(2 ,w);
	for(int i = 0 ; i <= t-1; i++){
		c[i] = (C[i] - P[i] - e);
		if(c[i]>=0){
			c[i] = mod(c[i], w);
			e = 1;
			}
		else{
			c[i] = mod(c[i], w);
			e = 0;
		}
	}
	for( int i=t-1;i>=0;i--){
        printf("%llu ", c[i]);	 
	}
}
int main() {
    int w = 8;
    unsigned long long p = 2147483647, a = 38762497 , b = 568424364, A[100], B[100], C[100], P[100], c[100];
//    printf("Nhap vao p ");
//    scanf("%llu", &p);
//    printf("Nhap vao w ");
//    scanf("%d", &w);
    float m = ceil (log(p)/log(2));
    int t = ceil (m/w);
    printf("p Chuyen sang mang =  "); ConvertArray(p, P, t, w);
//    printf("Nhap vao a ");
//    scanf("%llu", &a);
	printf("a Chuyen sang mang =  "); ConvertArray(a, A, t, w);
//    printf("Nhap vao b ");
//    scanf("%llu", &b);
    printf("b Chuyen sang mang =  ");  ConvertArray(b, B, t, w);
    printf("a - b = ");SubtractiononFp(A, B, C, t, w);
    SubtractiononFp(P, C, c, t, w);
//    if(check(P, C, t)){
//    	printf("c - p = ");SubtractiononFp(P, C, c, t, w);
//	}
//	else{
//		printf(" vi c < p => c = ");
//		for( int i=t-1;i>=0;i--){
//        printf("%llu ", c[i]);	 
//		}
//	}
    
    return 0;
}
