#include<stdio.h>
#include<stdlib.h>

int k[1000], i, j, t, tmp, so_bit, flag;
unsigned long long a, A, number, so_mu, r, b;
void  convert_decimal_to_binary(int k[], int *so_bit, unsigned long long so_mu) {
	for (*so_bit = 0; so_mu > 0; (*so_bit)++) {
		if (so_mu % 2) {
			k[*so_bit] = 1;
			so_mu = so_mu / 2;

		}
		else {
			k[*so_bit] = 0;
			so_mu = so_mu / 2;
		}
	}
}
int nhan_binh_phuong_co_lap(unsigned long long a, unsigned long long so_mu, unsigned long long number) {
	b = 1;
	A = a;
	if (so_mu == 0)	return b;
	else {
		convert_decimal_to_binary(k, &so_bit, so_mu);
		if (k[0] == 1)	b = a;
		for (j = 1; j < so_bit; j++) {
			A = A*A % number;
			if (k[j] == 1)	b = (A*b) % number;
		}
		return b;
	}
}
int checking_prime(int number, int t) {
	flag = 0;
	if (number == 0 || number == 1)		return 0;
	else if (number == 2 || number == 3)	  return 1;
	for (i = 1; i <= t; i++) {
		tmp = 1;
		while (tmp > 0) {
			a = rand();
			if (a >= 2 && a <= number - 2)
				tmp = 0;
		}
		r = nhan_binh_phuong_co_lap(a, number - 1, number);
		if (r != 1)	return 0;
	}
	return 1;
}
void display() {
	if (checking_prime(number, t))	 printf("\n\n=> Day la so nguyen to\n");
	else 	printf("\n% Day la hop so!\n");
}
int main() {
	printf("Thuat toan Fermat. Kiem tra tinh nguyen to cua so nguyen le number\n");
	printf("\n Nhap tham so an toan: ");
	scanf("%d", &t);
	printf("\n Nhap so nguyen le can kiem tra:");
	scanf("%lld", &number);
	display();
	system("pause");
	return 0;
}

