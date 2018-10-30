#include <iostream>
using namespace std;
int main()
{
	int n,i[4],tien[4]={1,5,10,20},s;
	cout<<"Nhap so tien n <= 99 : ";
	cin>>n;
	if(n>99)
	{
		cout <<"So vua nhap ko thoa de bai";
		exit(0);
	}
	for(i[0]=0;i[0]<=n/tien[0];i[0]++)
	{
		for(i[1]=0;i[1]<=n/tien[1];i[1]++)
		{
			for(i[2]=0;i[2]<=n/tien[2];i[2]++)
			{
				for(i[3]=0;i[3]<=n/tien[3];i[3]++)
				{
					s=0;
					for(int j=0;j<4;j++)
					s=s+i[j]*tien[j];
					if(s==n)
					{
						cout <<"Dung ";
						for (int j=0;j<4;j++)
						{
							if(i[j]*tien[j]!=0)
							cout<<i[j]<<" to tien "<<tien[j]<<" ";
						}
						cout <<endl;
					}
				}
			}
		}
	}
}
