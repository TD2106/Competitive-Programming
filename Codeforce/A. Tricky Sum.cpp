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
int tc;
ll Ti=0,n,sumOfPowerTwo[40]={0},temp,idx;
int main(){
    ios_base::sync_with_stdio(0);
    temp=1;
    up(i,0,35){
        temp*=2;
        sumOfPowerTwo[i]=temp-1;
    }
    cin>>tc;
    while(tc--){
        cin>>n;
        temp=1;
        idx=0;
        while(temp<=n){
            idx++;
            temp*=2;
        }
        idx--;
        Ti=n*(n+1)/2-2*sumOfPowerTwo[idx];
        cout<<Ti<<endl;
    }
    return 0;
}
