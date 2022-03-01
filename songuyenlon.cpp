#include <stdio.h>
#include <math.h>

void ChuyenPthanhmang(unsigned long long p, unsigned long long p1, int w, float m, int t,  unsigned long long P[100]){
	int i;
	printf("p => p[] = ");
    for(i=t-1;i>=0;i--){
        unsigned long long log = pow(2 ,(i*w));
        P[i]= p1 / log;
        p1 = p1 - (log*P[i]);
        printf("%llu ", P[i]);
	}
	printf("\n");
}

void MangA(unsigned long long p,  unsigned long long a, int w, float m, int t1,  unsigned long long A[100]){
	int i, j;
	printf("a => a[] = ");
    for(i=t1-1;i>=0;i--){
        unsigned long long log = pow(2 ,(i*w));
        A[i]= a / log;
        a = a - (log*A[i]);
        printf("%llu ", A[i]);	
	}
	printf("\n");
}
void MangB(unsigned long long p,  unsigned long long b, int w, float m, int t,  unsigned long long B[100]){
	int i, j;
	printf("b => b[] = ");
    for(i=t-1;i>=0;i--){
        unsigned long long log = pow(2 ,(i*w));
        B[i]= b / log;
        b = b - (log*B[i]);
        printf("%llu ", B[i]);	
  	}
  	printf("\n");
}

int mod(int k){
    int r = k % 256;
    return r < 0 ? r + 256 : r; // neu r <0 dung thi tra ve r + 256.  Sai thi tra ve r
}


void Tinhc(unsigned long long A[], unsigned long long B[], unsigned long long c[], float m, int t1, int k){
	int i, e;
	for(i = t1 -1 ; i >= 0; i--){
	e = 0;
	c[i] = (A[i] - B[i] - e);
	if(c[i]>=0){
		k = c[i];
		c[i]=mod(k);
		e = 0;
		}
	else {
		k = c[i];
		c[i]=mod(k);
		e = 1;
		}
	
}
	printf("\n\ne, c[]= a[] - b[] - e  --> \t(%d ,", e);
	for(i = 0; i<= t1-1; i++){
		printf("%llu ", c[i]);
	}
	printf(")");
}

void TinhC(unsigned long long C[], unsigned long long c[],  unsigned long long P[], int t1, int k){
	int i , e;
	for(i = t1-1 ; i >= 0; i--){
		e = 1;
		C[i] = (c[i] - P[i] - e);
		if(C[i]>=0){
			k = C[i];
			C[i] = mod(k);
			e = 0;
			}
		else{
			k = C[i];
			C[i] = mod(k);
			e = 1;
			}
	}	
	printf("\n\ne,  C[]= c[] - p[] - e  -->\t(%d ,", e);
	for(i = t1 - 1 ; i>= 0;  i--){
		printf("%d ", C[i]);
	}
	printf(")");
}
int soSanhMang(unsigned long long c[],unsigned long long P[])
{
	for(int i=0;i<4;i++)
	{
		if(c[i]>P[i])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
int main(){
	unsigned long long p , a, b;
	int k;
	mod(k);
	unsigned long long P[100], A[100], B[100], C[100], c[100], PP[100];
	printf("Nhap vao p =");
    scanf("%llu", &p);
    unsigned long long p1 = p;
    int w;
    printf("Nhap w = ");
    scanf("%d", &w); 
    float m = ceil (log(p)/log(2));
    int t = ceil (m/w);
    ChuyenPthanhmang(p, p1, w, m, t, P);
    printf("Nhap vao a =");
    scanf("%llu", &a);
    int t1 = ceil (m/w);
    MangA(p, a, w, m ,t1 , A);
    printf("Nhap vao b =");
    scanf("%llu", &b);
	MangB(p ,b, w, m, t, B);
    Tinhc(A, B, c, w, t1, k);
   	if(soSanhMang(c, P) == true){
		printf("\nVi c > p nen return c \n");
		Tinhc(A, B, c, w, t1, k);
		}
	else{
		printf("\nVi c < p nen return c - p \n");
		TinhC(C, c, P, t1, k);
		}	
	return 0;
}
