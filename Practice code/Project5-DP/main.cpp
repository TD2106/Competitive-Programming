#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define endl '\n'
#define bug(a) cout<< #a << " = " << a <<endl
#define all(a) a.begin(),a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define tc() int tc;cin>>tc;up(_tc,1,tc)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
int countPalindrome(const string& s){
    bool dp[505][505]={0};
    int result = 0;
    up(i,0,s.size()-1) dp[i][i]=1;
    up(length,2,s.size()){
        up(i,0,s.size()-length){
            int j=i+length-1;
            if(length == 2 ){
                if(s[i]==s[j]) dp[i][j]=1;
            }
            else{
                if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
            }
        }
    }
    up(i,0,s.size()-1) up(j,i,s.size()-1) result+=dp[i][j];
    return result;
}
int lcs(const string& a,const string & b){
    int dp[505][505]={0};
    up(i,1,a.size()){
        up(j,1,b.size()){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(a[i-1]==b[j-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    return dp[a.size()][b.size()];
}
int main(){
    ios_base::sync_with_stdio(0);
    return 0;
}
