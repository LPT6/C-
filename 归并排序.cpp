#include <iostream>
#define N 10
using namespace std;
void Merge(int a[],int s,int m,int e,int temp[]){
	int p1=s,p2=m+1,k=0;
	while(p1<=m&&p2<=e){
		if(a[p1]<a[p2])
			temp[k++]=a[p1++];
		else
			temp[k++]=a[p2++]; 
	}
	while(p1<=m){
		temp[k++]=a[p1++];
	}
	while(p2<=e){
		temp[k++]=a[p2++];
	}
	for(int i=0;i<e-s+1;i++){
		a[s+i]=temp[i];
	}
}
void MergeSort(int a[],int s,int e,int temp[]){
	int m=s+(e-s)/2; 
	if(s<e){
		MergeSort(a,s,m,temp);
		MergeSort(a,m+1,e,temp);
		Merge(a,s,m,e,temp);
	}
}
int a[N];
int b[N];
int main(){
	for(int i=0;i<N;i++)
		cin>>a[i];
	int s=0,e=sizeof(a)/sizeof(int)-1;
	MergeSort(a,s,e,b);
	for(int i=0;i<N;i++){
		if(i==N-1)
			cout<<a[i]<<endl;
		else 
			cout<<a[i]<<" ";
	}
	return 0;
}
