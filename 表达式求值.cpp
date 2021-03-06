#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int factor_vlue();
int term_vlue();
int expression_vlue();
int main()
{
	cout<<expression_vlue()<<endl;
	return 0;
}
int expression_vlue()
{
	int result=term_vlue();
	while(true){
		char op=cin.peek();
		if(op=='+'||op=='-'){
			cin.get();
			int vlue=term_vlue();
			if(op=='+')
				result+=vlue;
			else
				result-=vlue;
		}else
			break;
	}
	return result;
}
int term_vlue()
{
	int result=factor_vlue();
	while(true){
		char op=cin.peek();
		if(op=='*'||op=='/'){
			cin.get();
			int vlue=factor_vlue();
			if(op=='*')
				result*=vlue;
			else
				result/=vlue;
		}else
			break;
	}
	return result;
}
int factor_vlue()
{
	int result=0;
	char c=cin.peek();
	if(c=='('){
		cin.get();
		result=expression_vlue();
		cin.get();
	}else{
		while(isdigit(c)){
			result=10*result+c-'0';
			cin.get();
			c=cin.peek();
		}
	}
	return result;
}
