#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int a=0,i=0,j[4];
	while(a<2)
	{
		i++;
		a=0;
		for(j[0]=1;j[0]<=sqrt(i);j[0]++)
		{
			for(j[1]=1;j[1]<=j[0];j[1]++)
			{
				for(j[2]=1;j[2]<=j[1];j[2]++)
				{
					for(j[3]=1;j[3]<=j[2];j[3]++)
					{
						if(pow(j[0],2)+pow(j[1],2)+pow(j[2],2)+pow(j[3],2)==i)
						a=a+1;
					}
				}
			}
		}
		
	}
	cout<<"Ket qua la "<<i<<endl;
}
