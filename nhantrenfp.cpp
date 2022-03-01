//Nhan fp
#include <stdio.h>
#include <math.h>
void ConvertArray(unsigned long long a, unsigned long long A[100], int t, int w){
	int i;
    for(i=t-1;i>=0;i--){
        unsigned long long log = pow(2 ,(i*w));
        A[i]= a / log;
        a = a - (log*A[i]);
        printf("%llu ", A[i]);	
	}
	printf("\n");
}
void Multiplication(unsigned long long A[100], unsigned long long B[100],unsigned long long C[100], int t, int w){
	int i, j;
	unsigned long long u, UV;
	for(i=0;i<t;i++){
		u = 0;
		for(j=0;j<t;j++){
		 UV=C[i+j]+A[i]*B[j]+u;
            u=UV/pow(2,w);
            C[i+j]=UV%(long long)pow(2,w);//=v
            C[i+t]=0;
		}
	}
	printf("\nmang sau khi nhan la: ");
    for(i=2*t-1;i>=0;i--){
        printf("\n%llu",C[i]);  
    }
}
int main(){
	unsigned long long a, b, p, A[100], B[100], C[100];
	int w;
	printf("Nhap vao p ");
	scanf("%llu", &p);
	printf("Nhap vao w ");
	scanf("%d", &w);
	float m = ceil (log(p)/log(2));
    int t = ceil (m/w);
	printf("Nhap vao a ");
	scanf("%llu", &a);
	ConvertArray(a, A, t, w);
	printf("Nhap vao b ");
	scanf("%llu", &b);
	ConvertArray(b, B, t, w);
	Multiplication(A, B, C, t, w);
	return 0;
}
 
