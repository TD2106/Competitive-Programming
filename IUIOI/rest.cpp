#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
	int num[10],tc,input,i;
	cin>>tc;
	while(tc--)
	{
		bool check=0;
		i=1;
		memset(num,0,sizeof(num));
		cin>>input;
		int temp=input;
		while(temp)
		{
			num[i]=temp%10;
			i++;
			temp/=10;
		}
		while(--i)
		{
			if(num[i]==2&&num[i-1]==1)
			check=1;
		}
		if(check||input%21==0)
		cout<<"The streak is broken!\n";
		else
		cout<<"The streak lives still in our heart!\n";
	}
	return 0;
}
