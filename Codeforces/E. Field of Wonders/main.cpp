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
int Ti=0,n,m;
bool isReveal[26]={0};
string s,know[1005];
vector< set<char> > sets;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
    cin>>m;
    up(i,1,m) cin>>know[i];
    up(i,1,n){
        if(s[i-1]!='*'){
            isReveal[s[i-1]-'a']=1;
        }
    }
    up(i,1,m){
        bool flag=1;
        set<char> possible;
        up(j,1,n){
            if(s[j-1]=='*'&&isReveal[know[i][j-1]-'a']||s[j-1]!='*'&&know[i][j-1]!=s[j-1]){
                flag=0;
                break;
            }
            else if(s[j-1]=='*') possible.insert(know[i][j-1]);
        }
        if(flag) sets.pb(possible);
    }
    for(char c='a';c<='z';c++){
        bool flag=1;
        for(auto st:sets){
            if(!st.count(c)){
                flag=0;
                break;
            }
        }
        if(flag) Ti++;
    }
    cout<<Ti<<endl;
    return 0;
}

