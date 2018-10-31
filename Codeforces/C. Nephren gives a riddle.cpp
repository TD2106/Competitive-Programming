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
ll length[100005]={0},q,x,y;
string f0="What are you doing at the end of the world? Are you busy? Will you save us?",first="What are you doing while sending \"",second="\"? Are you busy? Will you send \"",third="\"?";
char result(ll a,ll b){
    if(a==0){
        if(b>=length[a]) return '.';
        return f0[b];
    }
    if(b>=length[a]) return '.';
    if(b<first.size()) return first[b];
    b-=first.size();
    if(b<length[a-1]) return(result(a-1,b));
    b-=length[a-1];
    if(b<second.size()) return second[b];
    b-=second.size();
    if(b<length[a-1]) return(result(a-1,b));
    b-=length[a-1];
    if(b<third.size()) return third[b];
    b-=third.size();
}
int main(){
    ios_base::sync_with_stdio(0);
    length[0]=f0.size();
    up(i,1,100000){
        if(length[i-1]>=1e18) length[i]=LLONG_MAX;
        else length[i]=first.size()+length[i-1]+second.size()+length[i-1]+third.size();
    }
    cin>>q;
    while(q--){
        cin>>x>>y;
        y--;
        cout<<result(x,y);
    }
    return 0;
}
