#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdio>
using namespace std;
int main ()
{
	int index;
	bitset<32005> primecheck;
	vector<int> prime;
	primecheck[1]=1;
	string numstring,min,temp;
	for(int i=2;i<=32000;i++)
	{
		if(i<=sqrt(32000)&&primecheck[i]==0)
		{
			for(int j=i*i;j<=32000;j+=i)
			primecheck[j]=1;
		}
		if(!primecheck[i])
		prime.push_back(i);
	}
	int n,key,power;
	cin>>n;
	for(int i=1;i<=n;i++)
	{	
		cin>>key;
		for(int j=0;j<prime.size()&&prime[j]<=key;j++)
		{
			power=0;
			if(key%prime[j]==0)
			{
				while(key%prime[j]==0)
				{
					power++;
					key/=prime[j];
				}
				numstring=static_cast<ostringstream*>( &(ostringstream() << prime[j]) )->str();;
				temp+=numstring;
				numstring=static_cast<ostringstream*>( &(ostringstream() << power) )->str();
				temp+=numstring;
			}
		}
		if(key!=1)
		{
			numstring=static_cast<ostringstream*>( &(ostringstream() << key) )->str();;
			temp+=numstring;
			temp+="1";
		}
		if(i==1)
		{
			min=temp;
			index=1;
		}
		else
		{
			if(temp<min)
			{
				min=temp;
				index=i;
			}
		}
		temp.clear();
	}
	cout<<index;
	return 0;
}
