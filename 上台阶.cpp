#include <iostream>
using namespace std;
int N;
int stairs(int n)
{
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	return stairs(n-1)+stairs(n-2); 
} 
int main()
{
	while(cin>>N){
		cout<<stairs(N)<<endl; 
	}
	return 0;
}
