#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	int n,m,b,check=0;
	cin >>n>>m;
	if(n>m)
	n=n-int(n/m);
	vector<int> a;
	while(1)
	{
		n=n*10;
		if(n%m==0)
		{
			cout<<"Ban nhap 2 so ko hop le ";
			exit(0);
		}
		else
		{
			int temp=n/m;
			a.push_back(temp);
			n=n%m;
		}
		for(int i=1;i<a.size();i++)
		{
			if(a[0]==a[i])
			{
				check=1;
				for(int j=1;j<i;j++)
				{
					if(a[j]!=a[j+i])
					{
						check = 0;
						break;
					}
				}
			}
			if(check==1)
			{
				b=i;
				break;
			}
		}
		if(check==1)
		break;
	}
	for(int i=0;i<b;i++)
	cout<<a[i];
	return 0;
	
}
