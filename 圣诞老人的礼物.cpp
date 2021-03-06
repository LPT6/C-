#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const double eps=1e-6;
struct Candy{
	int v;
	int w;
	bool operator < (const Candy & c){
		return double(v)/w-double(c.v)/c.w > eps;
	}
} Candies[110];
int main()
{
	int n,w;
	scanf("%d%d",&n,&w);
	//cin>>n>>w;
	for(int i=0;i<n;i++)
		scanf("%d%d",&Candies[i].v,&Candies[i].w);
		//cin>>Candies[i].v>>Candies[i].w;
	sort(Candies,Candies+n);
	int totalW=0;
	double totalV=0;
	for(int i=0;i<n;i++){
		if(Candies[i].w+totalW<=w){
			totalW+=Candies[i].w;
			totalV+=Candies[i].v;
		}
		else{
			totalV+=double(w-totalW)/Candies[i].w*Candies[i].v;
			break;
		}
	}
	printf("%0.1f\n",totalV);
//	cout<<totalV<<endl;
	return 0;
}
