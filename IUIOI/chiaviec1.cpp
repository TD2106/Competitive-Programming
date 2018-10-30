#include <iostream>
using namespace std;
float mx,m=1.0;
int a[20],n,u[20];
float c[20][20],b[20];
	
void thu(int i);

int main()
{
	int i,j;
	int k,v;
	cin>>n;
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	{
	cin>>c[i][j];
	c[i][j]=c[i][j]/100.0;
	}
	mx=0;m=1;
	for (i=1;i<=n;i++)
	{
	a[i]=1;
	u[i]=1;
}
	thu(1);
	cout<<mx;
}
void thu(int i)
{
	int j;
	for (j=1;j<=n;j++)
	{
		if ((a[i]=1)&&(u[i]=1))
		{
			b[i]=c[j][i];
			a[i]=0;
			u[i]=0;
			m=m*b[i];
			cout<<m<<" "<<b[i]<<endl;
			if ((m>mx)&&(i<n)) thu(i+1);
			if ((i==n)&&(m>mx)) mx=m;
			m=m/b[i];
			a[i]=1;
			u[i]=1;
		}
	}
}

