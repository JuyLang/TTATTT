#include <stdio.h>
#include <math.h>
int ConvertArray(unsigned long long a, unsigned long long A[100], int t, int w){
	int i;
    for(i=t-1;i>=0;i--){
        unsigned long long log = pow(2 ,(i*w));
        A[i]= a / log;
        a = a - (log*A[i]);
        printf("%llu ", A[i]);	
	}
	printf("\n");
	return A[i];
}
int mod(int k, int w){
    int r = k % 256;
    return r < 0 ? r + 256 : r; // neu r <0 dung thi tra ve r + 256.  Sai thi tra ve r
}
int tinhc(	unsigned long long A[100], 	unsigned long long B[100], 	unsigned long long c[100], int t, int w, int E){
 	int i, e = 0;
	for(i = t -1 ; i >= 0; i--){
	c[i] = (A[i] - B[i] - e);
	if(c[i]>=0){
		c[i]=mod(c[i], w);
		e = 0;
		printf("%llu ", c[i]);
		E = e;
		}
	else {
		c[i]=mod(c[i], w);
		e = 1;
		printf("%llu ", c[i]);
		}
		E = e;
	}
	return E;
}
void TinhC(unsigned long long c[], unsigned long long P[], unsigned long long C[], int t, int w, int E){
	int i ;
	for(i = t-1 ; i >= 0; i--){
		C[i] = (c[i] - P[i] - E);
		if(C[i]>=0){
			C[i] = mod(C[i], w);
			E = 0;
			}
		else{
			C[i] = mod(C[i], w);
			E = 1;
			}
	}	
	printf("\n\ne,  C[]= c[] - p[] - e  -->\t(%d ,", E);
	for(i = t - 1 ; i>= 0;  i--){
		printf("%d ", C[i]);
	}
	printf(")");
}
int main(){
	unsigned long long a = 38762497, b = 568424364 , p = 2147483647, P[100], A[100], B[100], c[100], C[100];
	int w = 8, E = 1;
//	printf("Nhap vao p ");
//	scanf("%llu", &p);
//	printf("Nhap vao w ");
//	scanf("%d", &w);
	float m = ceil (log(p)/log(2));
    int t = ceil (m/w);
    ConvertArray(p, P, t, w);
//	printf("Nhap vao a ");
//	scanf("%llu", &a);
	ConvertArray(a, A, t, w);
//	printf("Nhap vao b ");
//	scanf("%llu", &b);
	ConvertArray(b, B, t, w);
	tinhc(A, B, c, t, w, E);
	TinhC(c, P, C, t, w, E);
	return 0;
}
 
