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
string s,name[]={"Danil", "Olya", "Slava", "Ann" , "Nikita"};
int cnt[5]={0},flag=0;
void process(int x){
    size_t found=s.find(name[x]);
    while(found!=string::npos){
        cnt[x]++;
        found=s.find(name[x],found+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    up(i,0,4) process(i);
    up(i,0,4){
        if(cnt[i]>=2||cnt[i]>=1&&flag){
            cout<<"NO";
            return 0;
        }
        if(cnt[i]==1) flag=1;
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}