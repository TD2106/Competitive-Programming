#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int size,x;
	//freopen("10920.txt","r",stdin);
	cin>>size>>x;
	while(size)
	{
		int a=ceil(size/2.0),check;
		if(x==1)
		cout<<"Line = "<<ceil(size/2.0)<<", column = "<<ceil(size/2.0)<<".\n";
		else
		{
			check=ceil(sqrt(x*1.0));
			if(check%2==0)
			check++;
			int temp=(check-1)/2;
			int left=a-temp,right=a+temp,up=a+temp,down=a-temp;
			int test=pow(check-2,2)+1;
			if(x>=test&&x<=test+check-2)
			cout<<"Line = "<<up<<", column = "<<right-1-x+test<<".\n";
			if(x>test+check-2&&x<=test+check-2+check-1)
			cout<<"Line = "<<up-(x-(test+check-2))<<", column = "<<left<<".\n";
			if(x>test+check-2+check-1&&x<=test+check-2+check-1+check-1)
			cout<<"Line = "<<down<<", column = "<<left+(x-(test+check-2+check-1))<<".\n";
			if(x>test+check-2+check-1+check-1&&x<=test+check-2+check-1+check-1+check-1)
			cout<<"Line = "<<down+(x-(test+check-2+check-1+check-1))<<", column = "<<right<<".\n";
		}
		cin>>size>>x;
	}
	return 0;
}
