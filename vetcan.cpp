
#include<stdio.h>
#include<string.h>
 
int main() {
   char P[200], T[200];
   int n, m;
   printf("\nNhap mot chuoi bat ky P: ");
   gets(P);
   printf("\nNhap chuoi can tim tren dong ben tren ");
   gets(T);
   n = strlen(P);
   m = strlen(T);
   for(int i = 0; i < n - m; i++){
		if(P[i] == T[0]){
			for(int j = 1; j < m; j++){
				
	    		if(j == m - 1){
	    			printf("Chuoi can tim trong P bat dau tu so : %d ", i+1);
				}
				if(P[i + j] != T[j]){
					break;
				}			
			}
		}	
	}
   return 0;
}
