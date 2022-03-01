// Boyyer more
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstring>
#define For(i,a,b) for(long i = a;i<=b;i++)
	using namespace std;
	char x[100001],y[100001];
	int m, n, ASIZE = 256,XSIZE;
void nhap(){ 
		printf("Nhap vao chuoi van ban ban dau: "); 
		gets(y); 
		n = strlen(y);
		printf("Nhap vao chuoi con muon tim trong van ban : "); 
		gets(x); 
		m = strlen(x); 
		XSIZE = m;
}
void preBmBc(char *x, int m, int bmBc[]) {
	int i;
	for (i = 0; i < ASIZE; ++i)
	bmBc[i] = m;
	for (i = 0; i < m - 1; ++i)
	bmBc[x[i]] = m - i - 1;
}
void suffixes(char *x, int m, int *suff) {
	int f, g, i;
	suff[m - 1] = m;
	g = m - 1;
	for (i = m - 2; i >= 0; --i){
		if (i > g && suff[i + m - 1 - f] < i - g)
		suff[i] = suff[i + m - 1 - f];
		else {
			if (i < g)
		g = i;
		f = i;
		while (g >= 0 && x[g] == x[g + m - 1 - f])
		--g;
		suff[i] = f - g;
			}
	}
}
void preBmGs(char *x, int m, int bmGs[]) {
	int i, j, suff[XSIZE];
	suffixes(x, m, suff);
	for (i = 0; i < m; ++i)
	bmGs[i] = m;
	j = 0;
	for (i = m - 1; i >= 0; --i) 
	if (suff[i] == i + 1)
	for (; j < m - 1 - i; ++j)
	if (bmGs[j] == m)
	bmGs[j] = m - 1 - i;
	for (i = 0; i <= m - 2; ++i)
	bmGs[m - 1 - suff[i]] = m - 1 - i;
}
	
void BM(char *x, int m, char *y, int n) {
	int i, j, bmGs[XSIZE], bmBc[ASIZE];
	/* Preprocessing */
	preBmGs(x, m, bmGs);
	preBmBc(x, m, bmBc);
	/* Searching */
	j = 0;
	while (j <= n - m) {
		for (i = m - 1; i >= 0 && x[i] == y[i + j]; --i);
			if (i < 0) {
				printf("Chuoi ban tim nam o vi tri so : %d\n",j);
				j += bmGs[0];
			}
			else
				j += max(bmGs[i], bmBc[y[i + j]] - m + 1 + i);
			}
}

int main(){
	nhap();
	BM(x,m,y,n);
	return 0;
}
