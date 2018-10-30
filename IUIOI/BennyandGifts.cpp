#include <iostream>
#include <algorithm>
using namespace std;
struct obj
{
	int row;
	int col;
};
bool cmp(obj a,obj b)
{
	return (a.row<b.row||(a.row==b.row&&a.col<b.col));
}
int main ()
{
	char c;
	obj arr[100000];
	int size=1,fall=0,row=0,col=0;
	arr[0].row=row;
	arr[0].col=col;
	while(cin>>c)
	{
		if(c=='L')
		col--;
		if(c=='R')
		col++;
		if(c=='U')
		row--;
		if(c=='D')
		row++;
		arr[size].col=col;
		arr[size].row=row;
		size++;
	}
	sort(arr,arr+size,cmp);
	for(int i=0;i<size;i++)
	{
		int j=i+1;
		while(j<size&&arr[j].col==arr[i].col&&arr[j].row==arr[i].row)
		{
			fall++;
			j++;
		}
		i=--j;
	}
	cout<<fall;
	return 0;
}
