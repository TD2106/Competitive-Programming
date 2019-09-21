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

int longestWPI(vector<int>& hours) {
    int n = (int)hours.size(), ans = 0;
    int largerThanEight[n + 1];
    map<int,int> cnt;
    for(int i = 0; i <= n; i++){
        largerThanEight[i] = 0;
    }
    for(int i = 0; i < n; i++){
        largerThanEight[i + 1] = largerThanEight[i] + (hours[i] > 8 ? 1 : -1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    vector<int> vect{ 9,6,9 };
    cout << longestWPI(vect) << endl;
    return 0;
}
