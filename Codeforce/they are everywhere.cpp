#include <iostream>
#include <bitset>
using namespace std;
int main ()
{
	int n,array[100001]={0},total=0,be,house=1,mark;
	bool finish=0;
	cin>>n;
	cin.ignore();
	char temp;
	bitset<60> check;
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		if(!check[temp-'A'])
		{
			check[temp-'A']=1;
			array[i]=array[i-1]+1;
			total++;
		}
		else
		array[i]=array[i-1];
		if(array[i]==1)
		be=i;
	}
	for(int i=be;i<=n-1;i++)
	{
		if(array[i]==total)
		break;
		if(array[i]<array[i+1])
		house++;
		else
		{
			if(array[i-1]<array[i])
			house++;
		}
	}
	cout<<house;
	return 0;
}
