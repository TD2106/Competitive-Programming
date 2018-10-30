#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int a,b,c,n,t;
ll Ti=0;
map<int,ll> banknote;
map<int,ll>::iterator itr;
int main(){
    cin>>a>>b>>c>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        banknote[t]++;
    }
    itr=banknote.upper_bound(b);
    while(itr!=banknote.end()&&(itr->first)<c){
        Ti+=itr->second;
        itr++;
    }
    cout<<Ti<<endl;
	return 0;
}
