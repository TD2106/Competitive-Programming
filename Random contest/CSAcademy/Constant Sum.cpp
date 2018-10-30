#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,q,t,idx;
double a[100005],p[100005]={0},m=0,s;
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(q--){
        cin>>t;
        if(!t){
            cin>>idx>>s;
            p[idx]+=s+s/(n-1);
            m+=s/(n-1);
        }
        else{
            cin>>idx;
            cout<<fixed<<setprecision(9)<<a[idx]+p[idx]-m<<endl;
        }
    }
	return 0;
}
