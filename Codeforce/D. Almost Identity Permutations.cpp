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
ll Ti=1,n,k,t=0;
vector<int> test;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    down(i,k,2){
        if(i==4) Ti+=(n-3)*(n-2)*(n-1)*n/24*9;
        if(i==3) Ti+=(n-2)*(n-1)*n/6*2;
        if(i==2) Ti+=(n-1)*n/2;
    }
    cout<<Ti<<endl;
    return 0;
}
