// thua so khong tam thuong

#include <stdio.h>
#include <math.h>
#include <stdio.h>
int gcd(unsigned long long a, unsigned long long b){
	unsigned long long  resa = a;
    unsigned long long  resb = b;
    while (resb >0){
    	unsigned long long	r = resa % resb;
        resa = resb;
        resb = r;
	}
    return resa;
}
void FactorSpecial(unsigned long long a, unsigned long long b, unsigned long long n, unsigned long long d){
	for (int i = 1; i<10; i++){
    a = (a*a+1)%n;
    b = (b*b+1)%n;
    b = (b*b+1)%n;
    printf("(a = %llu | b = %llu )\n", a, b);
    if (a > b){
        d = gcd(a - b, n);
    }
    else{
        d = gcd(b - a, n);
    }
    if (d > 1 && d < n){
        printf("\nGia tri d = %llu ", d );
        break;
    }
    if(d == n){
        printf("\nKhong the phan tich %llu ra thua so khong tam thuong\n", n );
        break;
    }
  }
}
int main(){
  unsigned long long n, a = 2, b = 2, d;
  printf("Nhap vao so can phan tich ra thua so khong tam thuong = ");
  scanf("%llu", &n);
  FactorSpecial(a, b, n, d); 
  return 0;
}
