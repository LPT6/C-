#include <memory>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
char oriLight[5];  
char light[5];
char result[5];
int Getbit(char c,int i)
{
	return (c >> i) & 1;
}
void Setbit(char & c,int i,int v)
{
	if(v)
		c|=(1<<i);
	else
		c&=~(1<<i);
}
void Flipbit(char & c,int i)
{
	c^=(1<<i);
}
void outputResult(int t,char result[5])
{
	cout<<"PUZZLE #"<<t<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<6;j++)
		{
			cout<<Getbit(result[i],j);
			if(j<5)
				cout<<" "; 
		}
		cout<<endl;
	} 
}


int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<6;j++)
			{
				int s;
				cin>>s;
				Setbit(oriLight[i],j,s);
			}
		}
		for(int n=0;n<64;n++)
		{
			int switchs=n;
			memcpy(light,oriLight,sizeof(oriLight));
			for(int i=0;i<5;i++)
			{	
				result[i]=switchs;
				for(int j=0;j<6;j++)
				{
					if(Getbit(switchs,j)){
						if(j>0)
							Flipbit(light[i],j-1);
						if(j<5)
							Flipbit(light[i],j+1);
					Flipbit(light[i],j);}
				}
				if(i<4)
					light[i+1]^=switchs;
				switchs=light[i];
			}
			if(light[4]==0)
			{
				outputResult(t,result);break;	
			}	 
		}
	}
	return 0;
}
