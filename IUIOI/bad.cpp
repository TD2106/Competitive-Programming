#include <iostream>
using namespace std;
int max (int a, int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int main ()
{
	int arr[40],temp,inl,exl,count=0;
	while(cin>>temp)
	{
		arr[count]=temp;
		count++;
	}
	inl=arr[0];
	exl=arr[count-1];
	for(int i=1;i<count-1;i++)
	{
		temp=inl;
		inl=max(exl+arr[i],inl);
		exl=temp;
	}
	cout<<max(inl,exl);
	return 0;
}
