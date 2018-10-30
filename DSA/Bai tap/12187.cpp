#include <iostream>
#include <algorithm>
using namespace std;
int arr1[105][105],arr2[105][105];
void initial(int arr1[][105])
{
	for(int i=0;i<105;i++)
	for(int j=0;j<105;j++)
	arr1[i][j]=-1;
}
void inputarr(int arr1[][105], int row, int column)
{
	for(int i=1;i<=row;i++)
	for(int j=1;j<=column;j++)
	cin>>arr1[i][j];
}
void copyarr(int arr1[][105],int arr2[][105], int row, int column)
{
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=column;j++)
		arr1[i][j]=arr2[i][j];
	}
}
void battle(int arr1[][105],int arr2[][105], int row, int column,int N)
{
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=column;j++)
		{
			int a=i+1,b=i-1,c=j+1,d=j-1;
			if(arr1[i][j]){
			if((arr1[a][j]==arr1[i][j]-1||arr1[b][j]==arr1[i][j]-1||arr1[i][d]==arr1[i][j]-1||arr1[i][c]==arr1[i][j]-1))
			arr2[i][j]=arr1[i][j]-1;
			}
			if(arr1[i][j]==0){
			if((arr1[a][j]==N-1||arr1[b][j]==N-1||arr1[i][d]==N-1||arr1[i][c]==N-1)&&arr1[i][j]==0)
			arr2[i][j]=N-1;
			}
		}
	}
}
void print(int arr1[][105],int row, int column)
{
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=column;j++)
		{
			if(j!=column)
			cout<<arr1[i][j]<<" ";
			else
			cout<<arr1[i][j];
		}
		cout<<"\n";
	}
}
int main ()
{
	int N,R,C,K;
	//freopen("12187.txt","r",stdin);
	cin>>N>>R>>C>>K;
	while(N)
	{
		initial(arr1);
		inputarr(arr1,R,C);
		copyarr(arr2,arr1,R,C);
		while(K--)
		{
			battle(arr1,arr2,R,C,N);
			copyarr(arr1,arr2,R,C);
		}
		print(arr1,R,C);
		cin>>N>>R>>C>>K;
	}
	return 0;
}
