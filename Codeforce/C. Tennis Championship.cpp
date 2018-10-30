#include <iostream>
using namespace std;
typedef long long ll;
int main (){
	ll arr[100]={0},n,i=0;
	arr[0]=1;
	arr[1]=2;
	for(i=2;i<=92;i++) arr[i]=arr[i-2]+arr[i-1];
	cin>>n;
	i=0;
	while(n>=arr[i]) i++;
	cout<<i-1<<endl;
}
