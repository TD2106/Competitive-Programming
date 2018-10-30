#include <iostream>
using namespace std;
int main ()
{
	int n,k;
	cout <<"Nhap n va k "<<endl;
	cin>>n>>k;
	int mang[k+1];
	cout <<"Tap con la : ";
	for(int i=1;i<k+1;i++)
	{
		mang[i]=i;
		cout <<mang[i]<<" ";
	}
	cout<<endl;
	int check=0;
	while(check!=1)
	{
		check=1;
		for(int i=k;i>=1;i--)
	    {
	    	if(mang[i]!=n-k+i)
	    	{
	    		mang[i]=mang[i]+1;
	    	    for(int j=i;j<k;j++)
	    	    mang[j+1]=mang[j]+1;
	    	    check=0;
	    	    break;
			}
		}
		if(check==1)
		break;
		cout<<"Tap con la : ";
		for(int j=1;j<=k;j++)
		cout<<mang[j]<<" ";
		cout<<endl;
		
	}
	return 0;
}
