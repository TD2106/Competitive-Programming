#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main ()
{
	int n;
	cin>>n;
	int mang[n];
	for(int i=0;i<n;i++)
	{
		mang[i]=i+1;
		cout<<mang[i]<<" ";
	}
	cout<<endl;
	int check;
	while(1)
	{
		check=0;
		for(int i=n-2;i>=0;i--)
		{
			if(mang[i]<mang[i+1])
		    {
		    	check=1;
			    for(int j=n-1;j>i;j--)
			    {
			    	if(mang[j]>mang[i])
			    	{
			    		swap(mang[j],mang[i]);
			    		break;
					}
				}
				int dem=n-1;
				for(int j=i+1;j<(n+i+1)/2;j++)
				{
					swap(mang[j],mang[dem]);
					dem--;
				}
				break;
		    }
	    }
	    if(check==0)
	    break;
	    for(int i=0;i<n;i++)
	    cout<<mang[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
