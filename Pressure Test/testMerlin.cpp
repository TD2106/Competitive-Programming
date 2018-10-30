#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
//ifstream fi ("merlin.inp");
//ofstream fo ("merlin.out");
int64_t a[100001],b[100001],d,r;
int n,ans;
int main()
{//clock_t aa=clock();
cin>>n;
for(int i=1;i<=n;++i)cin>>a[i];
sort(a+1,a+n+1);
b[0]=0; for(int i=1;i<=n;++i)b[i]=b[i-1]+a[i];
for(int i=n;i>0;--i)
{
d=a[i]*i-b[i]; r=b[n]-b[i];
if(r>=d){ans=n-i; break;}
}
cout<<ans;
//clock_t bb=clock();
//fo<<"\nTime: "<<(double)(bb-aa)/1000<<" sec";
}
