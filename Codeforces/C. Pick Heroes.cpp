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

int n, m, a, b, t, ans, availableChoices = 0, p[2005] = {0}, heroesPower[2005] = {0};
bool taken[2005] = {0};

int findBetterHeroInPair(){
    int result = -1;
    up(i, 1, n){
        if(p[i] && !taken[i]){
            heroesPower[i] < heroesPower[p[i]] ? result = p[i] : result = i;
        }
    }
    return result;
}

int findBestHeroNotInPair(){
    int bestPow = 0, result = -1;
    up(i, 1, n){
        if(!p[i] && !taken[i]){
            if(heroesPower[i] > bestPow){
                bestPow = heroesPower[i];
                result = i;
            }
        }
    }
    return result;
}

void optimalAction(){
    ans = findBetterHeroInPair();
    if(ans == -1){
        ans = findBestHeroNotInPair();
    }
    cout << ans << endl;
    taken[ans] = 1;
    cout.flush();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    n *= 2;
    up(i, 1, n){
        cin >> heroesPower[i];
    }
    up(i, 1 , m){
        cin >> a >> b;
        p[a] = b;
        p[b] = a;
    }
    availableChoices = n;
    cin >> t;
    if(t == 1){
        availableChoices--;
        optimalAction();
    }
    while(availableChoices != 0) {
        cin >> t;
        if(t == -1){
            return 0;
        }
        taken[t] = 1;
        availableChoices--;
        if(availableChoices == 0){
            return 0;
        }
        if(p[t] && !taken[p[t]]){
            cout << p[t] << endl;
            taken[p[t]] = 1;
            cout.flush();
        }else{
            optimalAction();
        }
        availableChoices--;
    }
    return 0;
}
