#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int K,N,R;
struct Road {
	int d,L,t; 
};
vector< vector< Road > > G(110);
int minL[110][10010];
int minLen;
int totalLen;
int totalCost;
int visited[110];
void dfs(int s)
{
	if(s==N){
		minLen=min(minLen,totalLen); 
		return;
	}
	for(int i=0;i<G[s].size();i++){
		Road r=G[s][i];
		if(totalCost+r.t>K)
			continue;
		if(!visited[r.d]){
			if(totalLen+r.L>=minLen)
				continue;
			if(totalLen+r.L>=minL[r.d][totalCost+r.t])
				continue;
			minL[r.d][totalCost+r.t]=totalLen+r.L; 
			totalLen+=r.L;
			totalCost+=r.t;
			visited[r.d]=1;
			dfs(r.d);
			visited[r.d]=0;
			totalLen-=r.L;
			totalCost-=r.t;
		}
	}
}
int main()
{
	cin>>K>>N>>R;
	for(int i=0;i<R;i++){
		int s;
		Road r;
		cin>>s>>r.d>>r.L>>r.t; 
		if(s!=N)
			G[s].push_back(r);
	}
	for(int i=0;i<110;i++)
		for(int j=0;j<10010;j++)
			minL[i][j]=1<<30;
	memset(visited,0,sizeof(visited));
	minLen=1 <<30;
	totalLen=0;
	totalCost=0;
	visited[1]=1;
	dfs(1);
	if(minLen < (1<<30))
		cout<<minLen<<endl;
	else
		cout<<"-1"<<endl;
	return 0;
}
