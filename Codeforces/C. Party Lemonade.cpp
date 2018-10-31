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
struct bottle{
    ll price;
    ll volume;
    double perL;
} bottles[50];
ll l,r,n,need,temp,Ti;
bool cmp(bottle a,bottle b){
    return (a.perL<b.perL);
}
bool check(ll x){
    ll tempNeed = need;
    up(i,1,n){
        temp = tempNeed/bottles[i].volume;
        if(x<(temp*bottles[i].price)){
            return 0;
        }
        x-=temp*bottles[i].price;
        tempNeed-=temp*bottles[i].volume;
        if(x>=bottles[i].price){
            return 1;
        }
        if(tempNeed==0){
            return 1;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>need;
    temp=1;
    up(i,1,n){
        cin>>bottles[i].price;
        bottles[i].volume=temp;
        bottles[i].perL=((double)bottles[i].price/(double)bottles[i].volume);
        temp*=2;
    }
    l=1,r=1e18;
    sort(bottles+1,bottles+1+n,cmp);
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            r=mid-1;
            Ti=mid;
        }
        else l=mid+1;
    }
    cout<<Ti<<endl;
    return 0;
}
