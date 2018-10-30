#include <iostream>
using namespace std;
int main ()
{
	char house[2510];
	int position[2501]={0};
	int repaint=0,n,i,j=0;
	cin>>n;
	cin.ignore();
	for(i=0;i<n;i++)
	{
		cin>>house[i];
		if(i)
		{
			if(house[i]==house[i-1]&&position[j]==0)
			position[j]=2;
			else
			{
				if(house[i]==house[i-1]&&position[j]!=0)
				position[j]++;
				else if(house[i]!=house[i-1]&&position[j]!=0)
				j++;
			}
		}
	}
	for(int k=0;k<=j;k++)
	repaint=repaint+position[k]/2;
	cout<<repaint;
}
