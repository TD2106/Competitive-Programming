#include <bits/stdc++.h>
#define bug(x) cout<<#x<<'='<<x<<'\n'
#define tc() int tc;cin>>tc;for(int _tc=0;_tc<tc;++_tc)
#define up(i,l,r) for(int i=l;i<=r;++i)
#define rep(i,l,r) for (int i=l;i<r;i++)
#define down(i,r,l) for(int i=r;i>=l;--i)
#define fw(file) freopen(file,"w",stdout)
#define fr(file) freopen(file,"r",stdin)
#define reset(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

string s1,s2;
int cnt1[26],cnt2[26],tc,ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        cin>>s1>>s2;
        //reset(cnt1);
        reset(cnt2);
        ans=0;
        //for(int i=0;i<s1.size();i++) cnt1[s1[i]-'a']++;
        for(int i=0;i<s2.size();i++) cnt2[s2[i]-'a']++;
        //for(int i=0;i<26;i++) ans+=min(cnt1[i],cnt2[i]);
        for(char c : s1)
        {
            if(cnt2[c-'a'])
            {
                cnt2[c-'a']--;
                ans++;
            }
            else break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
