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
string vowel="aeiou";
bool isConsonant[26],Ti[3005]={0};
string s;
int main(){
	ios_base::sync_with_stdio(0);
	memset(isConsonant,1,sizeof(isConsonant));
	for(auto c:vowel) isConsonant[c-'a']=0;
	cin>>s;
	for(int i=2;i<s.size();i++){
        if(isConsonant[s[i]-'a']&&isConsonant[s[i-1]-'a']&&isConsonant[s[i-2]-'a']){
            if(!(s[i]==s[i-1]&&s[i]==s[i-2])){
                Ti[i]=1;
                i++;
            }
        }
	}
	up(i,0,s.size()-1){
        if(Ti[i]) cout<<' ';
        cout<<s[i];
	}
	return 0;
}
