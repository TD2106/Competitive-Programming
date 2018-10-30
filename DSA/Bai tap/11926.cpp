#include <iostream>
#include <bitset>
using namespace std;
int main ()
{
	int n,m,start,end,interval,period,check,j,check2;
	bitset<1000001> time;
	bitset<1000001> head;
	bitset<1000001> tail;
	//freopen("11926.txt","r",stdin);
	cin>>n>>m;
	while(n||m)
	{
		check=1;
		while(n--)
		{
			cin>>start>>end;
			if(!check)
			continue;
			else
			{
				for(int i=start;i<=end;i++)
				{
					if(time[i])
					{
						if(i==start)
						{
							if(tail[i])
							continue;
							else
							{
								check=0;
								cout<<"CONFLICT\n";
								break;
							}
						}
						else if(i==end)
						{
							if(head[i])
							continue;
							else
							{
								check=0;
								cout<<"CONFLICT\n";
								break;
							}
						}
						else
						{
							check=0;
							cout<<"CONFLICT\n";
							break;
						}
					}
					else
					time[i]=1;
				}
				head[start]=1;
				tail[end]=1;
			}
			
		}
		while(m--)
		{
			cin>>start>>end>>period;
			if(!check)
			continue;
			else
			{
				j=0;
				while(start+period*j<=1000000)
				{
					if(!check)
					break;
					for(int i=start+period*j;i<=end+period*j;i++)
					{
						if(i>1000000)
						break;
						if(time[i])
						{
							if(i==start+period*j)
							{
								if(tail[i])
								continue;
								else
								{
									check=0;
									cout<<"CONFLICT\n";
									break;
								}
							}
							else if(i==end+period*j)
							{
								if(head[i])
								continue;
								else
								{
									check=0;
									cout<<"CONFLICT\n";
									break;
								}
							}
							else
							{
								check=0;
								cout<<"CONFLICT\n";
								break;
							}
						}
						else
						time[i]=1;
					}
					if(start+period*j<=1000000)
					head[start+period*j]=1;
					if(end+period*j<=1000000)
					tail[end+period*j]=1;
					j++;
				}
			}
		}
		if(check)
		cout<<"NO CONFLICT\n";
		cin>>n>>m;
		time.reset();
		head.reset();
		tail.reset();
	}
	return 0;
}
