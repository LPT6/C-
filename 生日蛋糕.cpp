#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N,M;
int minArea=1<<30;
int Area=0;
void Dfs(int v,int n,int maxR,int maxH)
{
	if(n==0)
		if(v)
			return;
		else{minArea=min(minArea,Area);return;}	
	if(v<=0)
		return;
	for(int rr=maxR;rr>=n;rr--){
		if(n==M)
			Area=rr*rr;
		for(int hh=maxH;hh>=n;hh--){
			Area+=2*rr*hh;
			Dfs(v-rr*rr*hh,n-1,rr-1,hh-1);
			Area-=2*rr-hh;
		}
	}
}
int main()//一定会超时，还需进行可行性剪枝和最优性剪枝 
{
	int maxR,maxH;
	cin>>N>>M;
	maxR=sqrt(N/1);
	maxH=N/1;
	Dfs(N,M,maxR,maxH);
	if(minArea<(1<<30))
		cout<<minArea<<endl;
	else 
		cout<<"0"<<endl; 
	return 0;
}
 
 
