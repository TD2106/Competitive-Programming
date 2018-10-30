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
ll k,d,t,cycle;
double Ti,powerInCycle=0,temp;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>k>>d>>t;
    if(k%d==0){
        cout<<t<<endl;
        return 0;
    }
    cycle = (k/d+(bool)k%d)*d;
    powerInCycle = k + (cycle-k)*0.5;
    Ti+=floor(t/powerInCycle)*cycle;
    temp=(double)t-floor(t/powerInCycle)*(double)powerInCycle;
    if(temp<=(double)k) Ti+=temp;
    else{
        Ti+=k;
        temp-=k;
        Ti+=temp*2;
    }
    cout<<fixed<<setprecision(10)<<Ti<<endl;
    return 0;
}
