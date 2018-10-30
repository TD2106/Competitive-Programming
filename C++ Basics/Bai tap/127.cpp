#include <iostream>

using namespace std;

int main ()
{
	int k,can[10];
	cout<<"Nhap khoi luong k: ";
	cin>>k;
	for(int i=0;i<10;i++)
	{
		cout<<"Nhap khoi luong qua can thu "<<i+1<<": ";
	    cin>>can[i];
	}
	int j=k,nhiphan[10],s;
	j=0;
	while(j<=10)
	{
		for(int i1=0;i1<=1;i1++)
		{
			for(int i2=0;i2<=1;i2++)
		    {
		    		for(int i3=0;i3<=1;i3++)
		    		{
		    			for(int i4=0;i4<=1;i4++)
		    			{
		    				for(int i5=0;i5<=1;i5++)
		    				{
		    					for(int i6=0;i6<=1;i6++)
		    					{
		    						for(int i7=0;i7<=1;i7++)
		    						{
		    							for(int i8=0;i8<=1;i8++)
		    							{
		    								for(int i9=0;i9<=1;i9++)
		    								{
		    									for(int i10=0;i10<=1;i10++)
		    									{
		    										s=0;
		    										s=can[0]*i1+can[1]*i2+can[2]*i3+can[3]*i4+can[4]*i5+can[5]*i6+can[6]*i7+can[7]*i8+can[8]*i9+can[9]*i10;
		    										if(s==k)
		    										{
		    											j=j+1;
													    cout<<"Dung "<<i1<<" qua can "<<can[0]<<", "<<i2<<" qua can "<<can[1]<<", "<<i3<<" qua can "<<can[2]<<", "<<i4<<" qua can "<<can[3]<<", "<<i5<<" qua can "<<can[4]<<", "<<i6<<" qua can "<<can[5]<<", "<<i7<<" qua can "<<can[6]<<", "<<i8<<" qua can "<<can[7]<<", "<<i9<<" qua can "<<can[8]<<", "<<i10<<" qua can "<<can[9]<<endl;
													    
													}
													if(j==10)
													exit(0);
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
	}
}
