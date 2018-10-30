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
int n,Ti[200005]={0},cnt[200005]={0};
bool canMiss[200005];
set<int> needIns;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    memset(canMiss,1,sizeof(canMiss));
    up(i,1,n) cin>>Ti[i],cnt[Ti[i]]++;
    up(i,1,n) if(cnt[i]==0) needIns.insert(i);
    cout<<needIns.size()<<endl;
    up(i,1,n){
        if(cnt[Ti[i]]>=2){
            auto itr=needIns.lower_bound(Ti[i]);
            if(itr==needIns.begin()){
                if(canMiss[Ti[i]]) canMiss[Ti[i]]=0;
                else{
                    cnt[Ti[i]]--;
                    Ti[i]=*itr;
                    needIns.erase(*itr);
                }
            }
            else{
                cnt[Ti[i]]--;
                Ti[i]=*needIns.begin();
                needIns.erase(Ti[i]);
            }
        }
    }
    up(i,1,n) cout<<Ti[i]<<' ';
    return 0;
}
