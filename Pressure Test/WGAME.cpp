#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int n,Ti[26]={0},temp1[26],temp2[26];
string s1,s2;
int main(){
	ios_base::sync_with_stdio(0);
	fr("WGAME.INP");
	fw("WGAME.OUT");
	cin>>n;
	while(n--){
        cin>>s1>>s2;
        reset(temp1);
        reset(temp2);
        for(int i=0;i<s1.size();i++) temp1[s1[i]-'a']++;
        for(int i=0;i<s2.size();i++) temp2[s2[i]-'a']++;
        for(int i=0;i<26;i++) Ti[i]+=max(temp1[i],temp2[i]);
	}
	for(int i=0;i<26;i++) cout<<Ti[i]<<endl;
	return 0;
}
