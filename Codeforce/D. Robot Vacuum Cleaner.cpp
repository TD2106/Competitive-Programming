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
ll n,Ti=0,curS=0;
struct Noise{
    string str;
    ll s,h,f;
    Noise(){
        s=h=f=0;
    }
    void preCalculate(){
        for(char c:str){
            if(c=='s') s++;
            else h++;
        }
    }
    void calculateF(){
        this->preCalculate();
        ll temp=h;
        for(char c:str){
            if(c=='s') f+=temp;
            else temp--;
        }
    }
}t[100005];
bool cmp(const Noise &a,const Noise &b){
    return (a.s*b.h)>(a.h*b.s);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>t[i].str;
        t[i].calculateF();
    }
    sort(t+1,t+1+n,cmp);
    up(i,1,n){
        Ti+=t[i].f;
        Ti+=curS*t[i].h;
        curS+=t[i].s;
    }
    cout<<Ti<<endl;
    return 0;
}
