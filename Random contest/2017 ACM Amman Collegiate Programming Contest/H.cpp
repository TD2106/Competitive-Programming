#include <bits/stdc++.h>
#define bug(x) cout<<#x<<'='<<x<<'\n'
#define tc() int tc;cin>>tc;for(int _tc=0;_tc<tc;++_tc)
#define up(i,l,r) for(int i=l;i<=r;++i)
#define down(i,r,l) for(int i=r;i>=l;--i)
#define fw(file) freopen(file,"w",stdout)
#define fr(file) freopen(file,"r",stdin)
#define reset(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

int n,s,st,en;
string ans;

int main()
{
    ios_base::sync_with_stdio(0);
    tc()
    {
       cin>>n>>s;
       if((s%2==1&&n%2==0)||(s>9*n)){
            cout<<-1<<'\n';
            continue;
       }
       ans.clear();
       ans.resize(n);
       for(int i=0;i<n;i++) ans[i]='0';
       st=0,en=n-1;
       while(st<en){
            int temp=min(9,s/2);
            ans[st]+=temp;
            ans[en]+=temp;
            s-=temp*2;
            st++;
            en--;
       }
       if(n%2) ans[st]+=s;
       if(ans[0]=='0'){
            cout<<-1<<endl;
            continue;
       }
       cout<<ans<<'\n';
    }
}
