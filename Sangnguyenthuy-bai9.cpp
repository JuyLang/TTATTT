
// sang nguyen thuy
#include <stdio.h>
#include <math.h>
#include <stdio.h>
 
int main(){
  unsigned long long N, sum = 0;
  printf("Nhap vao N = ");
  scanf("%llu", &N);
  bool check[N + 1];
  //ví du tat ca so tu 2 den n deu la so nguyen to
  for (int i = 2; i <= N; i++) {
    check[i] = true;
  }
   //thuan toan sang nguyen to
 //neu mot so la so nguyen to thi boi cua so day khong phai so nguyen to
  for (int i = 2; i <= N; i++) {
    if (check[i] == true) {
      for (int j = 2 * i; j <= N; j += i) {
        check[j] = false;
      }
    }
  }
//in các so nguyen to
	
  for (int i = 2; i <= N; i++) {
    if (check[i] == true) {
      printf("%d ", i);
      sum = sum + i;
    }
  }
  printf("%llu ", sum);
  return 0;
}
