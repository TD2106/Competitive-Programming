#include <iostream>
using namespace std;
int main()
{
	int n,i=1;
	cout<<"Nhap n ";
	cin>>n;
	int matrix[n][n],hang=0,cot=0,a=0,e=n;
	
	while(i<=n*n)
	{
		for(cot=a;cot<e;cot++)//trái qua phai
		{
			matrix[hang][cot]=i;
			i++;
			
		}
		if(i>n*n)
		break;
		cot=cot-1;
		for(hang=a+1;hang<e;hang++)//tren xuong duoi
		{
			matrix[hang][cot]=i;
			i++;
			
		}
		hang=hang-1;
		if(i>n*n)
		break;
		for(cot=e-2;cot>=a;cot--)//phai qua trai
		{
			matrix[hang][cot]=i;
			i++;
			
		}
		cot=cot+1;
		if(i>n*n)
		break;
		for(hang=e-2;hang>a;hang--)//duoi len tren
		{
			matrix[hang][cot]=i;
			i++;
		}
		hang=hang+1;
		if(i>n*n)
		break;
		e--;
		a++;
    }
	for(int j=0;j<n;j++)
	{
		for(int k=0;k<n;k++)
		{
			cout<<matrix[j][k]<<" ";
		}
		cout<<endl;
		
	}
	
	
}
