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
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
int tc,ans;
vector<string> mirrorSubstr;
string s,temp;
bool dp[1005][1005]={0};
bool good[26]={0};
int longestPalindrome(string input){
    int res=1;
    for(int i=0;i<input.size();i++){
        dp[i][i]=1;
    }
    for(int l=2;l<=input.size();l++){
        for(int i=0;i<input.size()-l+1;i++){
            int j=i+l-1;
            if(l==2){
                if(input[i]==input[j]) dp[i][j]=1;
                else dp[i][j]=0;
            }
            else{
                if(dp[i+1][j-1]==1&&input[i]==input[j]) dp[i][j]=1;
                else dp[i][j]=0;
            }
            if(dp[i][j]) res=max(res,l);
        }
    }
//    for(int i=0;i<input.size();i++){
//        for(int j=0;j<input.size();j++) cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
//    fr("in.INP");
//    fw("out.OUT");
    temp="AHIMOTUVWXY";
    for(int i=0;i<temp.size();i++) good[temp[i]-'A']=1;
    cin>>tc;
    while(tc--){
        cin>>s;
        temp.clear();
        mirrorSubstr.clear();
        ans=0;
        for(int i=0;i<s.size();i++){
            if(good[s[i]-'A']) temp+=s[i];
            else{
                if(temp.size()) mirrorSubstr.push_back(temp);
                temp.clear();
            }
        }
        if(temp.size()) mirrorSubstr.push_back(temp);
        for(int i=0;i<mirrorSubstr.size();i++){
//            cout<<mirrorSubstr[i]<<endl;
            ans=max(ans,longestPalindrome(mirrorSubstr[i]));
        }
        cout<<ans<<endl;
    }
}
