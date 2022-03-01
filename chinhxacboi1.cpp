#include <stdio.h>
#include <math.h>
int InputCong(int arr1[], int arr2[], int c[]){
	int e, test, i, w = 4, t = 2;
	float Mu = pow(2, w*t);
	for(i = 3; i>=0; i--){
		c[i] = arr1[i] + arr2[i] + e;
		if(c[i] >= Mu){
		e = 1; 
			if(c[0]>=Mu){
				test = 1;
			}
			else{
				test = 0;
			}
		}
		else {
		e = 0;
		}
	}
	return c[i], test;
}

int InputTru(int arr1[], int arr2[], int c[]){
	int e, test, i, w = 4, t = 2;
	float Mu = pow(2, w*t);
	for(i = 3; i>=0; i--){
		c[i] = arr1[i] - arr2[i] - e;
		if(c[i] >= Mu){
		e = 0; 
			if(c[0]>=Mu){
				test = 0;
			}
			else{
				test = 1;
			}
		}
		else {
		e = 1;
		}
	}
	return test;
}

void Ouput(int arr1[], int arr2[], int c[]){
	int i;
	for(i = 3; i>=0; i--){
		printf("%d ", c[i]);
	}
}
int main(){
	int arr1[4] = { 0, 11, 173, 248},  arr2[4] = { 0, 1, 226, 64}, c[4];
	printf("%d, " ,InputCong(arr1, arr2, c ));
	Ouput(arr1, arr2, c);
	printf("\n%d, " ,InputTru(arr1, arr2, c ));
	Ouput(arr1, arr2, c);
	return 0;
}
