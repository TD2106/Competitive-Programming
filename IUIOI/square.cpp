#include <iostream>
using namespace std;
int main ()
{
	int tc,ans[1001]={0},index;
	for(int i=1;i<1000;i++)
	{
		int temp=i*i;
		ans[i]=(ans[i-1]%10+temp%10)%10;
	}
	cin>>tc;
	while(tc--)
	{
		cin>>index;
		cout<<ans[index]<<"\n";
	}
	return 0;
}
