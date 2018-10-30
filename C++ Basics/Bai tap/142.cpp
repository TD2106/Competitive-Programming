#include <iostream>
using namespace std;
int main()
{
	int m,n=0;
	cout<<"Nhap m ";
	cin>>m;
	for(int i=1;i<=m-1;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			cout<<i<<" va "<<j<<" la 1 cap khac nhau"<<endl;
			n++;
		}
	}
	cout<<"Co "<<n<<" cap doi mot khac nhau"<<endl;
	return 0;
	
}
