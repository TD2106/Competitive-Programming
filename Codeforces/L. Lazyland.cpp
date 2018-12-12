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
ll Ti = 0;
int n, k, cnt[100005] = {0}, remainingJobs = 0;
pii timeJob[100005];
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    up(i, 1, n){
        cin >> timeJob[i].se;
        cnt[timeJob[i].se]++;
    }
    up(i, 1, n){
        cin >> timeJob[i].fi;
    }
    up(i, 1, k){
        if(cnt[i] == 0){
            remainingJobs++;
        }
    }
    sort(timeJob + 1, timeJob + 1 + n);
    up(i, 1, n){
        if(remainingJobs && cnt[timeJob[i].se] > 1){
            cnt[timeJob[i].se]--;
            remainingJobs--;
            Ti += timeJob[i].fi;
        }
    }
    cout << Ti << endl;
    return 0;
}
