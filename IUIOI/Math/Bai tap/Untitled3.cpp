#include <cstdio>
#include <cstdlib>
void sort(int *arr,int size)
{
	int i,j;
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
int main ()
{
	int *arr;
	arr=(int*)malloc(10*sizeof(int));
	int i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,10);
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	
}
