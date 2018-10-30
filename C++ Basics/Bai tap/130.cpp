#include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Nhap so n >=5 : ";
	cin>>n;
	if(n<5)
	exit (0);
	int i[5],s;
	for(i[0]=1;i[0]<n;i[0]++)
	{
		for(i[1]=1;i[1]<=i[0];i[1]++)
		{
			for(i[2]=1;i[2]<=i[1];i[2]++)
			{
				for(i[3]=1;i[3]<=i[2];i[3]++)
				{
					for(i[4]=1;i[4]<=i[3];i[4]++)
					{
						s=0;
						s=i[0]+i[1]+i[2]+i[3]+i[4];
						if(s==n)
						{
							for (int j=0;j<5;j++)
							{
								cout <<i[j]<<" ";
							}
							cout <<endl;
						}
					}
				}
			}
		}
	}
}
