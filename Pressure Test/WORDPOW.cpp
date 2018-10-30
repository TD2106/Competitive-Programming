#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int dp[1005][35],Ti=0,n,m;
string cow[1005],good[105];
bool check(string s1,string s2){
    int idx1=0,idx2=0;
    while(idx1<s1.size()&&idx2<s2.size()){
        if(s2[idx2]==s1[idx1]) idx2++,idx1++;
        else idx1++;
    }
    return (idx2==s2.size());
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("WORDPOW.INP");
	fw("WORDPOW.OUT");
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>cow[i];
	for(int i=1;i<=m;i++) cin>>good[i];
	for(int i=1;i<=n;i++){
        for(int j=0;j<cow[i].size();j++){
            cow[i][j]=tolower(cow[i][j]);
        }
	}
	for(int i=1;i<=m;i++){
        for(int j=0;j<good[i].size();j++){
            good[i][j]=tolower(good[i][j]);
        }
	}
	for(int i=1;i<=n;i++){
        Ti=0;
        for(int j=1;j<=m;j++){
            if(check(cow[i],good[j])) Ti++;
        }
        cout<<Ti<<endl;
	}
	return 0;
}
