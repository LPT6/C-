
P140：
5.
#include<stdio.h>
int main()
{
	int a,n,s=0,i;
	printf("输入a,n:\n");
	scanf("%d,%d",&a,&n);
	for(i=0;i<n;i++)
	{
		s=s*10+a;
	}
	printf("结果为%d\n",s); 
	return 0;
} 


6.
#include<stdio.h>
int js(int a);
int main()
{
	int n;
	double f=1,s=0;
	for(n=1;n<=20;n++)
	{
		f*=n;
		s+=f;
	}
	printf("结果为%g\n",s); 
	return 0;
} 


9.
#include <stdio.h>
int main()
{
	int m,s,i;
	for(m=2;m<1000;m++)
	{	s=0;
		for(i=1;i<m;i++)
		{
			if(m%i==0)
			s=s+i;
		}
		if(s==m)
		{
			printf("%d its factors are",m);
			for(i=1;i<m;i++)
				if(m%i==0)
				printf(" %d",i);
			printf("\n");
		}
	}
	return 0;
}

10.
#include <stdio.h>
int main()
{
	int i;
	float s=0,a=1;
	for(i=1;i<=20;i++)
	{
		a=1+1/a;
		s+=a;
	}
	printf("%f\n",s);
	return 0;
}



P168:
2.
#include <stdio.h>
int main()
{
	int a[10],min,i,j,t;
	printf("输入10个整数：\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			min=i;
			if(a[j]<a[min])
			{
				t=a[min];
				a[min]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	return 0;
}


4.
#include <stdio.h>
int main()
{
	int a[10],n,m,i;
		a[0]=2;
	for(i=1;i<10;i++)
		a[i]=a[i-1]+3;
	printf("before:\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
		printf("\n",n);
	printf("input n:\n");
	scanf("%d",&n);
	printf("after:\n");
	if(a[9]<n)
	{
		for(i=0;i<10;i++)
		printf("%d ",a[i]);
		printf("%d\n",n);
	}else
	{
		for(i=0;i<10;i++)
		{
			if(a[i]>n)
			{m=i;break;}
		}
		for(i=0;i<m;i++)
		printf("%d ",a[i]);
		printf("%d",n);
		for(i=m;i<10;i++)
		printf(" %d",a[i]);
		printf("\n",n);
	}
	return 0;
}


5.
#include <stdio.h>
int main()
{
	int a[5],i,j,t;
	printf("按降序输入5个整数：\n");
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	printf("\n");
	j=4;
	for(i=0;i<5;i++)
			if(i<j)
			{
				t=a[i];
			 	a[i]=a[j];
				a[j]=t;
			 	j--;
			}
	for(i=0;i<5;i++)
		printf("%d ",a[i]);
	return 0;
}


13.
#include <stdio.h>
int main()
{
	char s1[10],s2[10];
	printf("输入字符串s1,s2:\n");
	gets(s1); gets(s2); 
	printf("%s%s",s1,s2);
	return 0;
}


15.
#include <stdio.h>
#include <string.h> 
int main()
{
	int i;
	char s1[20],s2[20];
	printf("输入字符串s2:\n");
	gets(s2);
	for(i=0;i<=strlen(s2);i++)
		s1[i]=s2[i];
	printf("字符串s1:\n");	
	printf("%s",s1);
	return 0;
}


P330:
3、4、5合成一个程序
#include <stdio.h>
void input(int n);
void print(int n);
	struct student
	{
		int num;
		char name[10];
		int score[3];
		float sum,average;
	} stu[5],t;
int main()
{
	int i;

	input(5);
	for(i=0;i<5;i++)
		{
			stu[i].sum=0;stu[i].average=0;
			stu[i].sum=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
			stu[i].average=stu[i].sum/3;
		}
	for(i=0;i<5;i++)
		if(stu[i].sum<stu[i+1].sum)
		{
			t=stu[i];
			stu[i]=stu[i+1];
			stu[i+1]=t;
		}
	
print(5);
	return 0;
}

void input(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("输入第%d个学生的信息num,name,english,math,chinese：\n",i+1);
		scanf("%d%s%f%%f%f",&stu[i].num,&stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
	}
} 

void print(int n)
{
	int i;
	printf("学生成绩情况num,name,sum,average：\n");
	for(i=0;i<n;i++)
	{
		printf("%d   %s   %f   %f\n",stu[i].num,stu[i].name,stu[i].sum,stu[i].average);
	}
		printf("最高分学生成绩情况num,name,english,math,chinese,sum,average:\n");
		printf("%d    %s    %f    %f    %f    %f    %f\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].sum,stu[i].average);		
}

P354:
3.
#include <stdio.h>
int main()
{
	int a=1,s=0,i;
	char s1[50];
	FILE *fp;
	fp=fopen("test.txt","w+");
	printf("输入一串字符：\n");
	gets(s1);
	for(i=0;i<50;i++)
	{
		if(s1[i]!='!')
			if(s1[i]>96&&s1[i]<123)
				s1[i]=s1[i]-32;
		putc(s1[i],fp);	
	}
	puts(s1);
	return 0;
}





5、6合成一个程序：

#include <stdio.h>
int main()
{
	int i,j; 
	struct student
	{
		int num;
		char name[10];
		float score[3],sum,average;
	} stu[5],temp;
	for(i=0;i<5;i++)
	{
		printf("please input NO.:\n");
		scanf("%d",&stu[i].num);
		printf("please input Name:\n");
		scanf("%s",&stu[i].name);
		stu[i].sum=0;stu[i].average=0;
		for(j=0;j<3;j++)
		{
			printf("please input Score:\n");
			scanf("%f",&stu[i].score[j]);
			stu[i].sum+=stu[i].score[j];
		}
		stu[i].average=stu[i].sum/3;
	}
	FILE *fp;
	fp=fopen("stud","w+");
	for(i=0;i<5;i++)
		fprintf(fp,"%d %s %d %d %d %d %d \n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].sum,stu[i].average);
	fclose(fp);
	fp=fopen("stud","r");
	for(i=0;i<5;i++)
		fscanf(fp,"%d %s %d %d %d %d %d ",&stu[i].num,&stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2],&stu[i].sum,&stu[i].average);
	for(i=0;i<3;i++)
	{
		if(stu[i].average<stu[i+1].average)
			temp=stu[i];
			stu[i]=stu[i+1];
			stu[i+1]=temp; 
	}
	FILE *fp1;
	fp1=fopen("stu_sort","w+");
	for(i=0;i<5;i++)
		fprintf(fp1,"%d %s %d %d %d %d %d \n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].sum,stu[i].average);
	for(i=0;i<5;i++)
		printf("%d %s %d %d %d %d %d \n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].sum,stu[i].average);
	fclose(fp1);
	return 0;
}





C++

P129：
2.
#include <iostream>
using namespace std;
class Time
{public:
	void set_Time(void)
	{cin>>hour;
	cin>>minute;
	cin>>sec;
	}
	void show_Time(void)
	{
		cout<<hour<<":"<<minute<<":"<<sec<<endl;
	}
private:
	int hour;
	int minute;
	int sec; 
 };
 Time t;
 int main()
 {
 	t.set_Time();
 	t.show_Time();
 	return 0;
 }







6.
#include <iostream>
using namespace std;
class cft
{public:
	int v;
	void set_data()
	{
		cin>>a>>b>>c; 
	}
	void js_data()
	{
		v=a*b*c;
	}
private:
	int a,b,c;
 }c1,c2,c3;
 
 int main()
 {
 	c1.set_data();
 	c2.set_data();
 	c3.set_data();
 	c1.js_data();
 	c2.js_data();
 	c3.js_data();
 	cout<<"体积1："<<c1.v<<endl<<"体积2："<<c2.v<<endl<<"体积3："<<c3.v<<endl;
	 return 0; 
 }




P152:
14.
#include <iostream>
#include <string>
using namespace std;
int main()
{
	const int n=5;
	int i,j;
	string str[n],temp;
	cout<<"输入字符串："<<endl;
	for(i=0;i<n;i++)
		cin>>str[i];
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		if(str[i]>str[j])
		{
			temp=str[i];
			str[i]=str[j];
			str[j]=temp;
		}
	cout<<"排序后:"<<endl;
	for(i=0;i<n;i++)
		cout<<str[i]<<endl;
	return 0;
}



15.
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int i,j;
	string str[5];
	for(i=0;i<5;i++)
	{
		cout<<"输入字符串：";
		cin>>str[i];
		cout<<endl;
		if(str[i].at(0)=='A') 
		cout<<str[i]<<endl;
	}
	return 0;
}




16.
（1）
#include <string>
using namespace std;
int main()
{
	int i,j;
	char a[11],temp;
	cout<<"输入10个字符："<<endl;
	for(i=0;i<10;i++)
		cin>>a[i];
		cout<<"before:"<<endl;
	for(i=0;i<10;i++)
		cout<<a[i];
		cout<<endl;
	for(i=0,j=9-i;i<j;i++,j--)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	cout<<"after:"<<endl;
	for(i=0;i<10;i++)
		cout<<a[i];
	return 0;
}


（2）
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	int n,i;
	char temp;
	cout<<"输入一个字符串："<<endl;
	cin>>str;
	n=str.size();
	for(i=0;i<n/2;i++) 
	{
		temp=str[i];
		str[i]=str[n-i-1];
		str[n-i-1]=temp;
	}
	cout<<"倒序后："<<endl; 
	cout<<str<<endl; 
	return 0;
 }




17.
#include <iostream>
#include <string>
using namespace std;
struct student
{
	string name;
	int num;
	int score;
}s[10];
int main()
{
	int i; 
for(i=0;i<10;i++)
	{
	cout<<"输入第"<<i+1<<"个学生的姓名、学号、成绩：" <<endl; 
	cin>>s[i].name>>s[i].num>>s[i].score;
	}
for(i=0;i<10;i++)
	{
	if(s[i].score<60)
		cout<<s[i].name<<" "<<s[i].num<<" "<<s[i].score<<endl;
	}
return 0; 
}

