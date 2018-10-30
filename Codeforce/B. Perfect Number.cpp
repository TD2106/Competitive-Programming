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
bool check(int x){
    int sum=0;
    while(x){
        sum+=x%10;
        x/=10;
    }
    return sum==10;
}
int k,Ti=10,cnt=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>k;
    while(cnt<k){
        Ti+=9;
        if(check(Ti)) cnt++;
    }
    cout<<Ti<<endl;
    return 0;
}
