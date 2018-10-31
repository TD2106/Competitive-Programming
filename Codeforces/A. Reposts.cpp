#include <bits/stdc++.h>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
queue<string> q;
string s1,s2,s3;
map<string,int> dp,vis;
map< string,vector<string> > g;
int Ti=0,n;
void bfs(string st){
    vis[st]=1;
    dp[st]=1;
    q.push(st);
    while(!q.empty()){
        s1=q.front();
        q.pop();
        for(int i=0;i<g[s1].size();i++){
            if(!vis[g[s1][i]]){
                vis[g[s1][i]]=1;
                q.push(g[s1][i]);
                dp[g[s1][i]]=1+dp[s1];
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s1>>s2>>s3;
        transform(s1.begin(),s1.end(),s1.begin(),::tolower);
        transform(s3.begin(),s3.end(),s3.begin(),::tolower);
        g[s1].pb(s3);
        g[s3].pb(s1);
    }
    bfs("polycarp");
    map<string,int>::iterator itr;
    for(itr=dp.begin();itr!=dp.end();itr++) Ti=max(Ti,itr->second);
    cout<<Ti<<endl;
    return 0;
}



