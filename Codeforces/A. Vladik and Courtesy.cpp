#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    int n1,n2,b1,b2;
    cin>>n1>>n2;
    int i=1;
    while(i*i<=n1) i++;
    b1=i-1;
    i=1;
    while(i*(i+1)<=n2) i++;
    b2=i-1;
    if(b1>b2) cout<<"Valera";
    else cout<<"Vladik";
	return 0;
}
