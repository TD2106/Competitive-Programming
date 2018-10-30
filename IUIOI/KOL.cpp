#include <iostream>
using namespace std;
int main ()
{
	bool check;
	int arr[30001]={0};
	int N,M,Z,U,V,W,temp;
	cin>>N>>M>>Z;
	while(Z--)
	{
		check=1;
		cin>>U>>V>>W;
		for(int i=U;i<V;i++)
		{
			arr[i]+=W;
			if(arr[i]>M)
			{
				check=0;
				for(int j=i;j>=U;j--)
				arr[j]-=W;
				cout<<"N\n";
				break;
			}
		}
		if(check)
		cout<<"T\n";
	}
	return 0;
}
