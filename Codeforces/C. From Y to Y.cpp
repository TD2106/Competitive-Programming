#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
string Ti;
vector<int> res;
int k;
int nearestResult(int x){
    int l=1,r=1e3,res,mid;
    while(l<=r){
        mid=(l+r)/2;
        if((mid-1)*mid/2<=x){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>k;
    if(k==0){
        cout<<"ti";
        return 0;
    }
    while(k){
        int temp=nearestResult(k);
        k-=temp*(temp-1)/2;
        res.pb(temp);
    }
    up(i,0,res.size()-1){
        up(j,1,res[i]) Ti+=('a'+i);
    }
    cout<<Ti<<endl;
    return 0;
}
