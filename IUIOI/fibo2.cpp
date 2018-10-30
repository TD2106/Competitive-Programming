#include <iostream>
#include <algorithm>
using namespace std;
long long result[2][2] = {{1,1},{1,0}};
long long mod=1000000007;
void multiply(long long matrix1[2][2],long long matrix2[2][2])
{
	long long x,y,z,w;
	x=matrix1[0][0]*matrix2[0][0]+matrix1[0][1]*matrix2[1][0];
	y=matrix1[0][0]*matrix2[0][1]+matrix1[0][1]*matrix2[1][1];
	z=matrix1[1][0]*matrix2[0][0]+matrix1[1][1]*matrix2[1][0];
	w=matrix1[1][0]*matrix2[0][1]+matrix1[1][1]*matrix2[1][1];
	matrix1[0][0]=x%mod;
	matrix1[0][1]=y%mod;
	matrix1[1][0]=z%mod;
	matrix1[1][1]=w%mod;
}
void power(long long matrix[2][2],long long n)
{
	long long M[2][2] = {{1,1},{1,0}};
	if(n==1||n==0)
	return;
	power(matrix,n/2);
	multiply(matrix,matrix);
	if(n%2)
	multiply(matrix,M);
}
long long fibo(long long n)
{
	if(n==1||n==0)
	return 1;
	else
	power(result,n-1);
	return result[0][0];
}
int main ()
{
	long long n;
	cin>>n;
	cout<<fibo(n)%mod<<"\n";
	return 0;
}
