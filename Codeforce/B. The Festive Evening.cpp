#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
string s;
vector<pii> seg;
pii arr[26];
int n,k,Ti=0,cur,t;
bool used[26]={0};
int check(){
    for(int i=0;i<seg.size();i++){
        if(used[i]==0){
            return i;
        }
    }
    return -1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k>>s;
	for(int i=0;i<s.size();i++){
        if(arr[s[i]-'A'].F==0){
            arr[s[i]-'A'].F=arr[s[i]-'A'].S=i+1;
        }
        else arr[s[i]-'A'].S=i+1;
	}
	for(int i=0;i<26;i++){
        if(arr[i].F!=0) seg.pb(arr[i]);
	}
	sort(seg.begin(),seg.end());
	t=check();
	while(t!=-1){
        cur=seg[t].S;
        used[t]=1;
        Ti++;
        for(int i=t+1;i<seg.size();i++){
            if(seg[i].F>cur){
                used[i]=1;
                cur=seg[i].S;
            }
        }
        t=check();
	}
	if(Ti>k) cout<<"YES";
	else cout<<"NO";
	return 0;
}
