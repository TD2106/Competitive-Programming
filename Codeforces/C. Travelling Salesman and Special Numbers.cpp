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
ll C[1005][1005]={0},Ti=0,mod=1e9+7,k,dp[1005]={0},total=0;
string n;
void preCalculate(){
    C[0][0]=1;
    up(i,1,1000){
        up(j,0,i){
            if(j==0) C[j][i]=1;
            else C[j][i]=C[j-1][i-1]+C[j][i-1];
            C[j][i]%=mod;
        }
    }
    dp[1]=1;
    up(i,2,1000){
        int temp = __builtin_popcount(i);
        dp[i] = dp[temp] + 1;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    preCalculate();
    cin>>n>>k;
    if(k==0){
        cout<<1<<endl;
        return 0;
    }
    for(char c:n) if(c=='1') total++;
    up(i,1,1000){
        if(dp[i]==k){
            up(j,1,n.size()-1){
                Ti+=C[i-1][j-1];
                Ti%=mod;
            }
            int curBit = i-1;
            up(j,1,n.size()-1){
                if(curBit<0) break;
                if(n[j]=='1'){
                    Ti+=C[curBit][n.size()-j-1];
                    curBit--;
                    Ti%=mod;
                }
            }
        }
    }
    if(k==1) Ti--;
    Ti+=mod;
    Ti%=mod;
    if(dp[total]==k) Ti++;
    Ti%=mod;
    cout<<Ti<<endl;
    return 0;
}
