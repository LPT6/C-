/*------------------------------------------------
【程序设计】
--------------------------------------------------

题目：杨辉三角如下所示：
1
1	1
1	2	1
1	3	3	1
1	4	6	4	1 
	编写程序，从键盘输入杨辉三角的行数n（n<=20），
    通过二维数组保存杨辉三角系数，输出杨辉三角中所有非1元素的和。
	例如：
	输入：
	n=5
	输出:
 	22


【特别注意】
    1)部分源程序给出如下。请勿改动主函数main和其他函数中的任何内容，仅在函数func的Begin和End之间填入你编写的若干语句。
    2)写好的程序一定要编译链接运行后，关闭Dev-C++窗口后，再返回到试题。

     *********Begin**********和**********  End  **********不可删除

------------------------------------------------*/

#include <iostream>
#include <cmath>
using namespace std;
void  bky();//请勿改动该代码 


int func(int n)  
{
  /*********Begin**********/
  	int i,j,a[20][20],sum=0;
	for(i=0;i<n;i++)
		for(j=0;j<i+1;j++)
		{
			if(i==j||j==0)
				a[i][j]=1;
			else
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			if(a[i][j]!=0)
				sum+=a[i][j];
		}
	for(i=0;i<n;i++)
	{
		for(j=0;j<i+1;j++)
		{cout<<a[i][j]<<"   ";}
		cout<<endl;
	}
	cout<<"杨辉三角中所有非1元素的和:"<<endl;
	return sum;
  /**********  End  **********/
}

int main()
{
    int n;
    cout<<"n=";
    cin>>n;
    cout<<func(n)<<endl;
   
    bky();//请勿改动该代码

    return 0;
}

//==============下面的代码用于阅卷，勿动==========================
#include<string>
#include <fstream>
#include <sstream>
#include <stdlib.h>


void bky()
{ 
    ifstream infile("in.dat");
	ofstream outfile("out2.dat");
	string tmp;
    int n;
    while(getline(infile,tmp))
    {
        n=atoi(tmp.c_str());
        int dtemp=func(n);
      
        stringstream ss;
        string sr;
        ss << dtemp;
        ss >>sr;
        outfile<<sr <<endl;
    }

    infile.close();
    outfile.close();
}
