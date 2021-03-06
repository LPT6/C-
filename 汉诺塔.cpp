#include <iostream>
using namespace std;
void hanoi(int n,char src,char mid,char dest,int *count);
int main()
{
	int n,count=0;
	cin>>n;
	hanoi(n,'A','B','C',&count);
	cout<<count<<endl;
	return 0;
}
void hanoi(int n,char src,char mid,char dest,int * pcount)
{
	if(n==1)
	{
		cout<<src<<"！！>" <<dest<<endl;
		(*pcount)++; 
	}else if(n>1)
	{
		hanoi(n-1,src,dest,mid,pcount);
		cout<<src<<"！！>" <<dest<<endl;
		(*pcount)++; 
		hanoi(n-1,mid,src,dest,pcount);
	}
} 
