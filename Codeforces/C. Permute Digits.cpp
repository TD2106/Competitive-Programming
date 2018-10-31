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
string a,b,Ti;
int cnt[10]={0},flag=0;
void go(int i,bool smaller){
    if(i==a.size()){
        cout<<Ti<<endl;
        exit(0);
    }
    if(smaller){
        down(j,9,0){
            if(cnt[j]){
                Ti[i]=j+'0';
                cnt[j]--;
                go(i+1,smaller);
                cnt[j]++;
            }
        }
    }
    else{
        down(j,9,0){
            if(cnt[j]&&j<=(b[i]-'0')){
                Ti[i]=j+'0';
                cnt[j]--;
                if(j<b[i]-'0') smaller=1;
                go(i+1,smaller);
                cnt[j]++;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>a>>b;
    if(b.size()>a.size()){
        Ti=a;
        sort(all(Ti),greater<char>());
        cout<<Ti<<endl;
        return 0;
    }
    else{
        Ti.resize(a.size());
        for(char c:a) cnt[c-'0']++;
        go(0,0);
    }

}
