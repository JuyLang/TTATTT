// nhan binh phuong co lap
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int  k[50], i, t;
unsigned long long a, b, mu_k, A, n;
void  convert_decimal_to_binary(int k[], int *t, unsigned long long mu_k) {
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
void algorithm() {
	b = 1;
	A = a;
	if (mu_k == 0) {
		printf("%lld^%lld mod %lld = %lld", a, mu_k, n, b);
		exit(0);
	}
	else {
		convert_decimal_to_binary(k, &t, mu_k);
		if (k[0] == 1)	b = a;
		for (i = 1; i < t; i++) {
			A = A*A % n;
			if (k[i] == 1)	b = (A*b) % n;
		}
		printf("\n%lld^%lld mod %lld = %lld", a, mu_k, n, b);
	}
}
int main() {
	printf("Thuat toan nhan binh phuong co lap, tinh gia tri a^k mod n\n");
	printf("\nEnter a, k, n: ");
	scanf_s("%lld %lld %lld", &a, &mu_k, &n);
	algorithm();
	printf("\nPress any key to continue...");
	_getch();
	return 0;
}

