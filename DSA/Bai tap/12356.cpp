#include <iostream>
#include <vector>
//#include <cstdio>
using namespace std;
int main ()

{
	int left[100005],right[100005];
	int S,B,l,r;
	//freopen("12356.txt","r",stdin);
	while(1)
	{
		cin>>S>>B;
		if(S==0&&B==0)
		break;
		for(int i=1;i<=S;i++)
		{
			left[i]=i-1;
			right[i]=i+1;
		}
		right[S]=0;
		left[0]=right[0]=0;
		while(B--)
		{
			int check=0;
			cin>>l>>r;
			left[right[r]]=left[l];
			if(left[l])
			cout<<left[l]<<" ";
			else
			cout<<"* ";
			right[left[l]]=right[r];
			if(right[r])
			cout<<right[r]<<endl;
			else
			cout<<"*"<<endl;
		}
		cout<<"-"<<endl;
	}
	return 0;
	
}
