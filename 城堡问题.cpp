#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int R,C;
int rooms[60][60];
int colors[60][60];
int roomsNum=0,MaxroomsArea=0;
int roomsArea;
void Dfs(int i,int k)
{
	if(colors[i][k])
		return;
	roomsArea++;colors[i][k]=roomsNum;
	if( (rooms[i][k] & 1) ==0 ) Dfs(i,k-1);
	if( (rooms[i][k] & 2) ==0 ) Dfs(i-1,k);
	if( (rooms[i][k] & 4) ==0 ) Dfs(i,k+1);
	if( (rooms[i][k] & 8) ==0 ) Dfs(i+1,k);
}
int main()
{
	cin>>R>>C;
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++){
			cin>>rooms[i][j];
		}	
	memset(colors,0,sizeof(colors));
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++){
			if(!colors[i][j])
			{
				roomsNum++;roomsArea=0;
				Dfs(i,j);
				MaxroomsArea=max(MaxroomsArea,roomsArea); 
			}
		}
	cout<<roomsNum<<endl<<MaxroomsArea<<endl;
	return 0;
}
