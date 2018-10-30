#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
map<char,char> mp;
string s1,s2,s,Ti;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>s1>>s2>>s;
	for(int i=0;i<26;i++){
        mp[s1[i]]=s2[i];
        mp[s1[i]-32]=s2[i]-32;
	}
	for(char c='0';c<='9';c++) mp[c]=c;
	for(int i=0;i<s.size();i++) Ti+=mp[s[i]];
	cout<<Ti<<endl;
	return 0;
}
