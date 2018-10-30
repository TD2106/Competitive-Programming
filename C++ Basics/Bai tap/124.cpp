#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
char check1(int a)
{
	char b;
	if(a==0) b='-';
	else b='+';
	return b;
}
char check(int a)
{
	char b;
	if(a==0) b='-';
	if(a==1) b='\0';
	if(a==2) b='+';
	return b;
}
string delblank(string s)
{
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='\0'||s[i]==' ')
		{
			s.erase(i,1);
			i--;
		}
		
	}
	return s;
}
string cut(string s)
{
	int i=0,a=0;
	while(s[i]!='\0')
	{
		
		if(s[i]<'1'||s[i]>'9')
		a++;
		if(a==2)
		break;
		i++;
	}
	string s1;
	for(int j=0;j<i;j++)
	s1=s1+s[j];
	return s1;
	

}

int main ()
{
	int n,plus,tong=0,boolean=0,b=0;
	cout<<"Nhap so n can tim ";
	cin>>n;
	char temp[15];
	string s1="*1*2*3*4*5*6*7*8*9",s,kq;
	int test[9];
	for(test[0]=0;test[0]<2;test[0]++)
	    for(test[1]=0;test[1]<3;test[1]++)
			for(test[2]=0;test[2]<3;test[2]++)
				for(test[3]=0;test[3]<3;test[3]++)
					for(test[4]=0;test[4]<3;test[4]++)
						for(test[5]=0;test[5]<3;test[5]++)
							for(test[6]=0;test[6]<3;test[6]++)
								for(test[7]=0;test[7]<3;test[7]++)
									for(test[8]=0;test[8]<3;test[8]++)
										{
											tong=0;
											s=s1;
											s[0]=check1(test[0]);
											for(int i=1;i<9;i++)
											s[2*i]=check(test[i]);
											s=delblank(s);
											kq=delblank(s);
											while(s.size()!=0)
											{
												plus=0;
												string s2=cut(s);
												s.erase(0,s2.size());
												for(int i=0;i<s2.size();i++)
												temp[i]=s2[i];
												sscanf(temp,"%d",&plus);
												tong=tong+plus;
												for(int i=0;i<s2.size();i++)
												temp[i]='\0';
											}
											if(tong==n)
											{
												cout<<kq<<"="<<n;
												boolean=1;
												exit(0);
											}
										}
	if(boolean==0)
	cout<<"Ko tim dc ket qua phu hop"<<endl;
	return 0;
	
										
	
}
