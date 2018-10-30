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
int n,k,pos=-1;
char Ti[100005]={0};
string s;
char mn=127,mx=0;
bool vis[26]={0};
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k>>s;
    up(i,0,n-1){
        mn=min(mn,s[i]);
        mx=max(mx,s[i]);
        vis[s[i]-'a']=1;
    }
    if(k>n){
        up(i,0,n-1) Ti[i]=s[i];
        up(i,n,k-1) Ti[i]=mn;
    }
    else{
        down(i,k-1,0){
            if(s[i]<mx){
                pos=i;
                break;
            }
        }
        up(i,0,pos-1) Ti[i]=s[i];
        up(i,s[pos]-'a'+1,26){
            if(vis[i]){
                Ti[pos]=i+'a';
                break;
            }
        }
        up(i,pos+1,k-1) Ti[i]=mn;
    }
    up(i,0,k-1) cout<<Ti[i];
    return 0;
}
