#include <iostream>
#include <math.h>
using namespace std;
//Ham check so nguyen to
int songuyento(int n)
{
	int a=1;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			a=0;
			break;
		}
	}
	return a;
}
//Ham check xem co dang 2^p-1 ko
int check(int a,int b)
{
	int c=0;
    int d=pow(2,a)-1;
    if(d==b)
    c=1;
    return c;
}
int main()
{
	int n,a=1,b=0;
	cout<<"Nhap so n: ";
	cin>>n;
	for(int i=1;i<n;i++)
	{
		b=0;
		// Kiem tra so nguyen to be hon n
		if(songuyento(i))
		{
			float x=log((i+1)*1.0)/log(2*1.0);
			x=int(x);
			// Cho chay cac so be hon so nguyen to tim dc
			for(int j=1;j<=x;j++)
			{
				// Check xem so co dang 2^p-1 ko
				if(check(j,i))
				{
					// Kiem tra so p co phai so nguyen to ko
					if(songuyento(j))
					{
						b=1;
						a=0;
					}
					
				}
				if(b)
				{
					cout <<"So nguyen to mersen la: "<<i<<" co dang la 2^"<<j<<"-1"<<endl;
					break;
				}
			}
		}
	}
	if(a)
	cout<<"Ko co so mersen be hon "<<n<<endl;
	return 0;
}
