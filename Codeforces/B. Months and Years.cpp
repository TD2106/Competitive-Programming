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
int n,a[30]={0},months[]={31,28,31,30,31,30,31,31,30,31,30,31};
bool leap=0,good;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n) cin>>a[i];
    up(i,0,11){
        int cur=i;
        good=1;
        up(j,1,n){
            if(a[j]==29&&cur==1&&leap==0) leap=1;
            else if(a[j]!=months[cur]){
                good=0;
                break;
            }
            cur++;
            cur%=12;
        }
        if(good){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
    return 0;
}
