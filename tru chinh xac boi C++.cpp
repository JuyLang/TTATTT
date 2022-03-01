#include <iostream>
#include <math.h>

using namespace std;

void chuyenSoSangMang(int t,int w,double a,int b[])
{
	int k;
	for(int i=1;i<=t;i++)
	{
		k=a/(pow(2,(t-i)*w));
		if(k==0)
		{
			b[i] =0;
			cout<<b[i]<<"\t";
			continue;
		}
		else
		{
			b[i]=k;
			cout<<b[i]<<"\t";
			a=a-k*(pow(2,(t-i)*w));
		}
	}
}

int modulo(int a,int w)
{
	int k=0;
	k = a/w;
	if(a>=0)
	{
		if(k==0)
		{
			return a;
		}	
		else
		{
			return a-(k*w);
		}	
	}
	else
	{
		while(a<0)
		{
			a=a+w;
		}
		return a;
	}
}

int thuatToanCong(int a[], int n,int b[],int arr[],int w) // n la so luong phan tu trong mang
{
	int f,e;
	f = a[n]+b[n];
	int k = pow(2,w);
	arr[n]= modulo(f,k);
	if(arr[n]==f)
	{
		e=1;
	}
	else
	{
		e=0;
	}
	
	for(int i=n-1;i>=0;i--)
	{
		int j = a[i]+b[i]+e;
		if(j>=k)
		{
			arr[i] = modulo(j,k);
			e=0;
		}
		else
		{
			arr[i] = modulo(j,k);
			e=1;
		}
	}
	cout<<"\nMang tong la: ";
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"e ="<<e;
	return e;
}

int thuatToanC(int a[],int n,int b[],int arr[],int w)
{
	int f,e;
	f = a[n]-b[n];
	int k = pow(2,w);
	arr[n]= modulo(f,k);
	if(f>=0)
	{
		e=0;
	}
	else
	{
		e=1;
	}
	for(int i=3;i>=0;i--)
	{
		int j = a[i]+b[i]+e;
		if(j<0)
		{
			arr[i] = modulo(j,k);
			e=0;
		}
		else
		{
			arr[i] = modulo(j,k);
			e=1;
		}
	}
	cout<<"\nMang a + b = : ";
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\ne ="<<e;
	return e;
}

int soSanhMang(int a[],int b[],int n)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b[i])
		{
			return true;
			break;
		}
		else if(a[i]==b[i])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
}
int main()
{
	double a,c;
	int t,w,m,tong=0,k,e;
	long p;
	int b[100];
	int d[100];
	int arr[100];
	int arrp[100];
	int arrh[100];// mang hieu
	cout<<"Nhap a = ";
	cin>>a; 
	cout<<"Nhap so p= ";
	cin>>p;
	cout<<"Nhap so w= ";
	cin>>w;
	cout<<"Nhap so b= ";
	cin>>c;
	
	m = log2(p);
	t= (m/w)+1;
	
	cout<<"\nmang a[] = ";
	chuyenSoSangMang(t,w,a,b);
	cout<<"\nmang b[] = ";
	chuyenSoSangMang(t,w,c,d);
	int f= thuatToanC(b,t,d,arr,w);
	cout<<"\nmang p[] =  ";
	chuyenSoSangMang(t,w,p,arrp);
	if(f==1)
	{
		thuatToanCong(arr,t,arrp,arrh,w);
	}
	else
	{
		thuatToanC(b,t,d,arr,w);
	}
}
