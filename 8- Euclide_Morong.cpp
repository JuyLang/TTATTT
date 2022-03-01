//euclide mo rong
#include <stdio.h>
#include <math.h>
int main(){
	unsigned long long a, b;
	double d, q, r, x, y, x1 = 0 , x2 = 1, y1 = 1, y2 = 0, i = 0;
	printf("Nhap vao a ");
	scanf("%llu", &a);
	printf("Nhap vao b ");
	scanf("%llu", &b);
	printf(" q = 0.0  \tr = 0.0 \tx = 0.0 \ty = 0.0 \ta = %d \tb = %d \tx2 = %f \tx1 = %f \ty2 = %f \ty1 = %f", a, b, x2, x1, y2, y1);
	while(b>0){
//	printf("vong lap thu %f", i);
	i++;
	q = floor(a/b);
	printf("\n q = %0.1f |", q);
	r =  a - q*b;
	printf("\t r = %0.1f |", r);
		x = x2 - x1*q;
	printf("\t x = %0.1f |", x);
		y = y2 - y1*q;
	printf("\t y = %0.1f |", y);
		a = b;
	printf("\t a = %d |", a);
		b = r;
	printf("\t b = %d |", b);
		x2 = x1;
	printf("\t x2 = %0.1f |", x2);
		x1= x;
	printf("\t x1 = %0.1f |", x1);
		y2=y1;
	printf("\t y2 = %0.1f |", y2);
		y1=y;
	printf("\t y1 = %0.1f |", y1);
		d = a;
	printf("\n ---------------------------------------------------------------------------------------------------------------------------- ");
	}	
	
	printf("\n Uoc Chung cua a va b là %f", d);
	printf("\n x2 = %f \t y2 = %f", x2, y2);
	return 0;
}
