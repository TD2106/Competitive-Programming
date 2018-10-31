#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,k,cnt[26]={0};
string s;
bool Ti=1;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k>>s;
	for(int i=0;i<s.size();i++){
        cnt[s[i]-'a']++;
        if(cnt[s[i]-'a']>k){
            Ti=0;
        }
	}
	if(Ti) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
