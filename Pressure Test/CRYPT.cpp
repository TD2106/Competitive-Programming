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
string s,Ti="impossible",syllable="aeiouy";
bool isCode[10005]={0},flag=0;
int n;
map<char,bool> isSyllable;
int main(){
	ios_base::sync_with_stdio(0);
	fr("CRYPT.INP");
	fw("CRYPT.OUT");
	cin>>s;
	n=s.size();
	s="#"+s;
	s+="##";
	for(char c:syllable) isSyllable[c]=1;
	up(i,1,n){
        if(s[i]=='f'&&s[i+1]=='a'){
            if(isSyllable[s[i-1]]&&(!isCode[i-1])){
                isCode[i]=isCode[i+1]=1;
            }
        }
	}
	up(i,1,n){
        if(isSyllable[s[i]]&&(!isCode[i])){
            if(!(s[i+1]=='f'&&s[i+2]=='a')){
                flag=1;
                break;
            }
        }
	}
	if(flag) cout<<Ti<<endl;
	else{
        Ti.clear();
        up(i,1,n){
            if(!isCode[i]) Ti+=s[i];
        }
        cout<<Ti<<endl;
	}
	return 0;
}
