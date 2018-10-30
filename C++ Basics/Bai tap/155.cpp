#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	int n;
	cout<<"Nhap n ";
	cin>>n;
	int T[n];
	vector<int> P(n,0);
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap t["<<i+1<<"] ";
		cin>>T[i];
		int a=i+1;
		if(T[i]>n-a)
		{
			cout<<"Ban nhap so sai vui long chay lai chuong trinh";
			exit(0);
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		int a=i+1,temp=0;
		if(i==n-1)
		P[0]=a;
		else
		{
			for(int j=0;j<n;j++)
			{
				if(temp==T[i])
				{
					P.insert(P.begin()+j,a);
					P.pop_back();
					break;
				}
				if(P[j]>a)
				temp++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<P[i]<<" ";
	}
	return 0;
}
