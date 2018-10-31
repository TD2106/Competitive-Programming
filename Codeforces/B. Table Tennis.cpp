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
ll n,k,a[505],cnt[505]={0},cur=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    up(i,1,n) cin>>a[i];
    if(k>=n-1){
        cout<<n<<endl;
        return 0;
    }
    up(i,1,n){
        if(a[i]==n){
            cout<<n<<endl;
            return 0;
        }
        if(i==1){
            cur=a[i];
            up(j,i+1,n){
                if(a[j]<a[i]){
                    cnt[a[i]]++;
                    if(cnt[a[i]]==k){
                        cout<<a[i]<<endl;
                        return 0;
                    }
                }
                else break;
            }
        }
        else{
            if(a[i]<cur) continue;
            cnt[a[i]]++;
            cur=a[i];
            up(j,i+1,n){
                if(a[j]<a[i]){
                    cnt[a[i]]++;
                    if(cnt[a[i]]==k){
                        cout<<a[i]<<endl;
                        return 0;
                    }
                }
                else break;
            }
        }
    }
    return 0;
}
