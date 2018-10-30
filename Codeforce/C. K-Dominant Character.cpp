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
string s;
int temp,Ti=1e9;
vector<vi> position;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    position.resize(26);
    up(i,0,s.size()-1){
        position[s[i]-'a'].pb(i);
    }
    up(i,0,25){
        position[i].pb(-1);
        position[i].pb(s.size());
        sort(all(position[i]));
        temp=0;
        up(j,1,(int)position[i].size()-1) temp=max(temp,position[i][j]-position[i][j-1]);
        Ti=min(Ti,temp);
    }
    cout<<Ti<<endl;
    return 0;
}
