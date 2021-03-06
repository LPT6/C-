#include <iostream>
using namespace std;
void swap(int & a,int & b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void Quicksort(int a[],int s,int e)
{
	if(s>=e)
		return;
	int k=a[s],i=s,j=e;  
	while(i!=j){
		while(i<j && a[j]>=k)
			--j;
		swap(a[i],a[j]);
		while(i<j && a[i]<=k)
			++i;
		swap(a[i],a[j]);
	}
	Quicksort(a,s,i-1);
	Quicksort(a,i+1,e);
}
int a[10]={45,89,25,43,78,63,12,32,75,52};
int main()
{
	int size=sizeof(a)/sizeof(int);
	Quicksort(a,0,size-1); 
	for(int i=0;i<size;i++){
		if(i<size-1)
			cout<<a[i]<<" ";
		else
			cout<<a[i]<<endl;
	}
	return 0;	
}
