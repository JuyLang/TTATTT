//kiem tra Camichenl
#include <stdio.h>
#include <math.h>
#include <stdio.h>

/// ch�ng ta lap qua tat ca c�c so tu 1 den n v� voi moi so nguy�n to c�ng nhau, 
//ch�ng ta kiem tra xem luy thua thua (n-1) cua n� theo modulo n c� l� 1 hay kh�ng.
int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
 
 
int power(int x, int y, int mod)
{
    if (y == 0)
        return 1;
    int temp = power(x, y / 2, mod) % mod;
    temp = (temp * temp) % mod;
    if (y % 2 == 1)
        temp = (temp * x) % mod;
    return temp;
}
 
 
bool isCarmichaelNumber(unsigned long long n)
{
    for (int b = 2; b < n; b++) {
        // N?u "b" l� nguy�n t? c�ng nhau v?i n
        if (gcd(b, n) == 1)
            // V� pow(b, n-1)%n kh�c 1,
            // return false.
            if (power(b, n - 1, n) != 1)
                return false;
    }
    return true;
}
 
 
int main()
{
	unsigned long long n ;
	printf("Nhap vao so can kiem tra ");
	scanf("%llu", &n);
	if(isCarmichaelNumber(n)==true){
		printf("Day la So Camichael");
	}else{
			printf("Khong Phai So Camichael");
	}
    return 0;
}
