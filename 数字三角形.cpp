#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
int n;
int D[MAX][MAX];
int Maxsum[MAX][MAX];
int maxsum(int i,int j){
	if(Maxsum[i][j]!=-1)
		return Maxsum[i][j];
	if(i==n)
		Maxsum[i][j]=D[i][j];
	else{
		int x=maxsum(i+1,j);
		int y=maxsum(i+1,j+1);
		Maxsum[i][j]=max(x,y)+D[i][j];
	}
	return Maxsum[i][j];
} 
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++){
			cin>>D[i][j];
			Maxsum[i][j]=-1;
		}
		cout<<maxsum(1,1)<<endl;
	return 0; 
}
//优化 
//递归转成递推
/*
#include <iostream> #include <algorithm> using namespace std;
#define MAX 101 int D[MAX][MAX];  
int n; 
int maxSum[MAX][MAX]; 
void main()  
{ 
	int i,j; 
	cin >> n; 
	for(i=1;i<=n;i++) 
		for(j=1;j<=i;j++) 
			cin >> D[i][j];
	for( int i = 1;i <= n; ++ i )
 		maxSum[n][i] = D[n][i];
	for( int i = n-1; i>= 1;  --i ) //转化成了两次循环 ，来递推 
		for( int j = 1; j <= i; ++j ) 
			maxSum[i][j] = max(maxSum[i+1][j],maxSum[i+1][j+1]) + D[i][j]; 
	cout << maxSum[1][1] << endl;
}
*/
//空间优化  maxSum[MAX][MAX]二位数组转化成一维数组，减少空间浪费
//再次空间优化 不要maxSum[MAX]，直接使用D[i][j]的最后一行D[n][j]来存最大和 

 
