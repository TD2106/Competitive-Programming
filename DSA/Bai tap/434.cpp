#include <iostream>
#include <algorithm>
using namespace std;
//so sanh giua hai so
int smaller(int a, int b)
{
	if(a>b)
	return b;
	else
	return a;
}
//tim cot cao nhat
int biggest(int arr[],int size)
{
	int big=arr[0];
	for(int i=1;i<size;i++)
	if(arr[i]>big)
	big=arr[i];
	return big;
}
//tim min gach
//thuat toan o day la dung tat ca cac cot theo hang doc truoc, sau do check xem so cot da dung co ung voi so cot can o hang ngang ko, neu vuot qua thi cong them
//sau do tim nhung con so chua xuat hien o hang ngang roi cong them vao
int min (int arr1[],int arr2[],int size,int big)
{
	int sum=0,array1[big+1]={0},array2[big+1]={0};
	for(int i=0;i<size;i++)
	{
		sum=sum+arr1[i];
		array1[arr1[i]]++;
	}
	for(int i=0;i<size;i++)
	{
		if(array1[arr2[i]])
		{
			if(array2[arr2[i]]>=array1[arr2[i]])
			sum=sum+arr2[i];
			array2[arr2[i]]++;
		}
	}
	for(int i=0;i<size;i++)
	{
		if(array1[arr2[i]]==0)
		{
			sum=sum+arr2[i];
		}
	}
	return sum;
}
int max (int arr1[],int arr2[],int size)
{
	int sum=0;
	for(int i=0;i<size;i++)
	{
		if(arr1[i]==0)
		continue;
		for(int j=0;j<size;j++)
		{
			sum=sum+smaller(arr1[i],arr2[j]);
		}
	}
	return sum;
}
int main ()
{
	int cases,n;
	//freopen("434.txt","r",stdin);
	cin>>cases;
	while(cases--)
	{
		int column[8],row[8];
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>row[i];
		for(int i=0;i<n;i++)
		cin>>column[i];
		int a=min(column,row,n,biggest(row,n)),b=max(column,row,n);
		
		cout<<"Matty needs at least "<<a<<" blocks, and can add at most "<<b-a<<" extra blocks."<<endl;
	}
	return 0;
}
