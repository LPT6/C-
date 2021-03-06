#include <iostream>
#include <cmath>
#define EPS 1e-6
#define N 4
using namespace std;
double a[N];
bool isZero(double x){
	return fabs(x)<=EPS;
}
bool count24(double a[],int n)
{
	if(n==1){
		if(isZero(a[0]-24))
			return true;
		else
			return false;
	}
	double b[N];
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
			int m=0;
			for(int k=0;k<n;k++)
			{
				if(k!=i&&k!=j)
					b[m++]=a[k]; 
			}
			b[m]=a[i]+a[j];
			if(count24(b,m+1))
				return true;
			b[m]=a[i]-a[j];
			if(count24(b,m+1))
				return true;
			b[m]=a[j]-a[i];
			if(count24(b,m+1))
				return true;
			b[m]=a[i]*a[j];
			if(count24(b,m+1))
				return true;
			if(!isZero(a[j])){
				b[m]=a[i]/a[j];
				if(count24(b,m+1))
					return true;
			} 
			if(!isZero(a[i])){
				b[m]=a[j]/a[i];
				if(count24(b,m+1))
					return true;
			} 	
		}
	return false;
}
int main()
{
	int t=1;
	while(t){
		t=N;
		for(int i=0;i<N;i++){
			cin>>a[i];
			if(a[i]==0)
				--t;
		}
		while(t){
			if(count24(a,N)){
				cout<<"YES"<<endl;break;
			}
			else {
				cout<<"NO"<<endl;break;
			}
		}
	}
	return 0;
}
