//ngich dao euclide
#include <stdio.h>
#include <math.h>

int main(){
	unsigned long long a, p, u, v, q, r, kq;
	double x, x1 = 1, x2=0;
	printf("Nhap vao a ");
	scanf("%llu", &a);
	printf("Nhap vao p ");
	scanf("%llu", &p);
	u = a;
	v = p;
	while(u>1){
		q = floor(v/u);
		r = v -u*q;
		x = x2- x1*q;
		v = u;
		u = r;
		x2 = x1;
		x1 = x;
	}
	
	printf("%llu^-1 mod %llu = %f", a, p, x1);
	
	return 0;
}
