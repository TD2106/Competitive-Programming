#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    int x,y;
    map<int,int> mp;
    cin>>x>>y;
    for(int i=1;i<=12;i++){
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12) mp[i]=1;
        else if(i==2) mp[i]=2;
        else mp[i]=3;
    }
    if(mp[x]==mp[y]) cout<<"Yes";
    else cout<<"No";
	return 0;
}
