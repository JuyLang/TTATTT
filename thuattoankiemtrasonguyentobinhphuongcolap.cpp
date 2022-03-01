//bai 41. nhan binh phuong co lap va kiem tra co phai so nguyen to
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
int  k[100], i, t;
unsigned long long a, b, mu_k, A, n;
void convert_decimal_to_binary(int k[], int *t, unsigned long long mu_k) {
	for (*t = 0; mu_k > 0; (*t)++) {
		if (mu_k % 2) {
			k[*t] = 1;
			mu_k = mu_k / 2;
		}
		else {
			k[*t] = 0;
			mu_k = mu_k / 2;
		}
	}
}
void kiemtrasonguyento(int x){
	if(x < 2){
        printf("\n%d khong phai so nguyen to", n);
    }
    int count = 0;
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0){
            count++;
        }
    }
    if(count == 0){
        printf("\n%d la so nguyen to", x);
    }else{
        printf("\n%d khong phai so nguyen to", x);
    }
}
void algorithm() {
	b = 1;
	A = a;
	if (mu_k == 0) {
		printf("%lld^%lld mod %lld = %lld", a, mu_k, n, b);
	}
	else {
		convert_decimal_to_binary(k, &t, mu_k);
		if (k[0] == 1)	b = a;
		for (i = 1; i < t; i++) {
			A = A*A % n;
			if (k[i] == 1)	b = (A*b) % n;
		}
		printf("\n%lld^%lld mod %lld = %lld", a, mu_k, n, b);
		kiemtrasonguyento(b);	
	}
	
}
int main() {
	printf("tinh gia tri a^k mod n\n");
	printf("\nEnter a, k, n: ");
	scanf("%lld %lld %lld", &a, &mu_k, &n);
	algorithm();
	getch();
	return 0;
}

