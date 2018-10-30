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
set<int> lps;
int n,m,y[1000005]={0},dp[1000005]={0},b[1000005]={0},cur=-1e9,temp;
ll Ti=0,mod=1e9+7;
string pat;
void precompute(){
    int patLen=pat.size(),i=0,j=-1;
    b[0]=-1;
    while(i<patLen){
        while(j>=0&&pat[i]!=pat[j]) j=b[j];
        i++,j++;
        b[i]=j;
    }
    i=b[patLen];
    while(i>0){
        lps.insert(i);
        i=b[i];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>pat;
    precompute();
    up(i,1,m) cin>>y[i];
    up(i,1,m){
        if(y[i]>cur+(int)pat.size()-1) cur=y[i];
        else{
            temp=cur+(int)pat.size()-1-y[i]+1;
            if(lps.count(temp)) cur=y[i];
            else{
                cout<<Ti<<endl;
                return 0;
            }
        }
    }
    Ti=1;
    up(i,1,m){
        dp[y[i]]++;
        dp[y[i]+(int)pat.size()]--;
    }
    up(i,1,n) dp[i]+=dp[i-1];
    up(i,1,n){
        if(dp[i]==0){
            Ti*=26;
            Ti%=mod;
        }
    }
    cout<<Ti<<endl;
    return 0;
}
