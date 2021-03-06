#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
double exp()
{
	char s[20];
	cin>>s;
	switch(s[0]){
		case '+': return exp()+exp();break;
		case '-': return exp()+exp();break;
		case '*': return exp()*exp();break;
		case '/': return exp()/exp();break;
		default : return atof(s);//atof(s) 函数在cstdlib标准库里，
		//作用是把s所表示的字符串转化成double类型的数 
	}
}
int main()
{
	printf("%lf\n",exp());
	return 0;
} 
