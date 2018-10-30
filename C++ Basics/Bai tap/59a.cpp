#include <iostream>
#include <math.h>
#include <conio.h>
#include <vector>
using namespace std;
int main ()
{
	int n,i,j,s=0,d=0,e,f;
	printf("Nhap so n vao: ");
	scanf("%d",&n);
	int a [n],b [n], c[10];
	for (i=0;i<n;i++)
	{
		printf("Nhap vao so a[%d] ",i);
		scanf("%d",&a[i]);
		printf("Nhap vao so b[%d] ",i);
		scanf("%d",&b[i]);
		
		
	}
	printf(" Giao cua 2 day so la: ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]==b[j])
			{
				c[d]=a[i];
				d++;
				s=1;
				printf(" %d ",a[i]);
			}
		
		}
	}
	if(s==0)
	printf("ko ton tai.");
	cout<<endl;
	vector<int> hoi;
	int check1,check2;
	for(int i=0;i<n;i++)
	{
		check1=1;
		check2=1;
		for(int j=0;j<hoi.size();j++)
		{
			if(a[i]==hoi[j])
			check1=0;
			if(b[i]==hoi[j])
			check2=0;
		}
		if(a[i]==b[i])
		check2=0;
		if(check1)
		hoi.push_back(a[i]);
		if(check2)
		hoi.push_back(b[i]);
	}
	cout<<"Hoi cua 2 day la: ";
	for(int i=0;i<hoi.size();i++)
	cout<<hoi[i]<<" ";
	getch();
}
