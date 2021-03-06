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
//�Ż� 
//�ݹ�ת�ɵ���
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
	for( int i = n-1; i>= 1;  --i ) //ת����������ѭ�� �������� 
		for( int j = 1; j <= i; ++j ) 
			maxSum[i][j] = max(maxSum[i+1][j],maxSum[i+1][j+1]) + D[i][j]; 
	cout << maxSum[1][1] << endl;
}
*/
//�ռ��Ż�  maxSum[MAX][MAX]��λ����ת����һά���飬���ٿռ��˷�
//�ٴοռ��Ż� ��ҪmaxSum[MAX]��ֱ��ʹ��D[i][j]�����һ��D[n][j]�������� 

 
