//bai 11: Tinh tong so nguyen to nho hon n 
#include <stdio.h>
#include <math.h>
#include <stdio.h>
 
int main(){
  unsigned long long n, count = 0;
  while(n>=2){
  	printf("Nhap vao n = ");
    scanf("%llu", &n);
  }
 
  bool Check[n + 1];
  for(int i = 0 ;i <= n; i++){
  	Check[i] = true;
  }
  //neu mot so la so nguyen to thi boi cua so day khong phai so nguyen to
  for (int i = 2; i <= n; i++) {
    if (Check[i] == true) {
      for (int j = 2 * i; j <= n; j += i) {
        Check[j] = false;
      }
    }
  }
  printf("Cac so nguyen to nho hon n = ");
  for (int i = 2; i <= n; i++) {
    if (Check[i] == true) {
      printf("%d ", i);
      count = count + i;
    }
  }
  
  printf("\nTong Cac So Nguyen To nho hon N la %llu", count);
  return 0;
}
