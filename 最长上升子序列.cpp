#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=1010;
int a[MAXN];
int MAXLen[MAXN];
int main()
{
	int N;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>a[i];
		MAXLen[i]=1; 
	  } 
	for(int i=2;i<=N;i++)
		for(int j=1;j<i;j++)
		 {
		 	if(a[i]>a[j])
		 	{
		 		MAXLen[i]=max(MAXLen[i],MAXLen[j]+1);
			 }
		  } 
	cout<<* max_element(MAXLen+1,MAXLen+N+1)<<endl;
	return 0; 
 } 
