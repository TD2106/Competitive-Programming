#include <iostream>
#include <cstdlib>
using namespace std;
int main ()
{
	int **array;
	array=(int **)malloc(sizeof(int *)*3);
	for(int i=0;i<3;i++)
	{
		array[i]=(int *)malloc(sizeof(int)*4);
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<"Nhap array["<<i<<"]["<<j<<"] ";
			cin>>array[i][j];
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		cout<<array[i][j]<<" ";
		cout<<endl;
		
	}
}
