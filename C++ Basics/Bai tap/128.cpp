#include <iostream>

using namespace std;

int main ()
{
	int k,tien[10];
	cout<<"Nhap so tien k: ";
	cin>>k;
	for(int i=0;i<10;i++)
	{
		cout<<"Nhap menh gia to tien thu "<<i+1<<": ";
	    cin>>tien[i];
	}
	int j,s,i[10];
	j=0;
	for(i[0]=0;i[0]<=k/tien[0];i[0]++)
	{
		for(i[1]=0;i[1]<=k/tien[1];i[1]++)
		{
			for(i[2]=0;i[2]<=k/tien[2];i[2]++)
			{
				for(i[3]=0;i[3]<=k/tien[3];i[3]++)
				{
					for(i[4]=0;i[4]<=k/tien[4];i[4]++)
					{
						for(i[5]=0;i[5]<=k/tien[5];i[5]++)
						{
							for(i[6]=0;i[6]<=k/tien[6];i[6]++)
							{
								for(i[7]=0;i[7]<=k/tien[7];i[7]++)
								{
									for(i[8]=0;i[8]<=k/tien[8];i[8]++)
									{
										for(i[9]=0;i[9]<=k/tien[9];i[9]++)
										{
											s=0;
											for(int e=0;e<10;e++)
										    s=s+i[e]*tien[e];
										    if(s==k)
										    {
										    	j++;
										    	cout<<"Dung ";
										    	for(int e=0;e<10;e++)
										    	{
										    		if(i[e]*tien[e]!=0)
													cout<<i[e]<<" to tien "<<tien[e]<<" ";
												}
												cout<<endl;
											}
											if(j==10)
											exit (0);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(j==0)
	cout<<"Ko co cach tra tien thoa de bai";
}
