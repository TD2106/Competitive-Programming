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
int n,Ti;
void take(int l,int r){
    while(l<=r){
        cout<<l<<' '<<r<<' ';
        l+=2;
        r-=2;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    if(n%4==0) Ti=0;
    else if(n%4==1) Ti=1;
    else if(n%4==2) Ti=1;
    else Ti=0;
    cout<<Ti<<endl;
    if(n%4==0){
        cout<<n/2<<' ';
        take(1,n);
    }
    else if(n%4==1){
        cout<<(n-1)/2+1<<' ';
        cout<<1<<' ';
        take(2,n);
    }
    else if(n%4==2){
        cout<<n/2<<' ';
        cout<<1<<' ';
        take(3,n);
    }
    else{
        cout<<(n-3)/2+2<<' ';
        cout<<1<<' '<<2<<' ';
        take(4,n);
    }
    return 0;
}
