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
int Ti=24,t;
vector<vi> original(3),input(3);
void rotateVector(vector<vi> &a,int x){
    if(x==0){
        t=a[0][0];
        a[0][0]=a[1][0];
        a[1][0]=a[2][0];
        a[2][0]=a[2][1];
        a[2][1]=a[1][2];
        a[1][2]=a[0][1];
        a[0][1]=t;
    }
    else{
        t=a[0][1];
        a[0][1]=a[1][1];
        a[1][1]=a[2][1];
        a[2][1]=a[2][2];
        a[2][2]=a[1][3];
        a[1][3]=a[0][2];
        a[0][2]=t;
    }
}
void go(int times,int x,vector<vi> a){
    if(times>Ti) return;
    if(times==0){
        go(times+1,0,a);
        go(times+1,1,a);
    }
    else{
        rotateVector(a,x);
        if(a==original){
            Ti=min(Ti,times);
            return;
        }
        go(times+1,1,a);
        go(times+1,0,a);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    original[0].pb(1),original[0].pb(2),original[0].pb(3);
    original[1].pb(8),original[1].pb(0),original[1].pb(0),original[1].pb(4);
    original[2].pb(7),original[2].pb(6),original[2].pb(5);
    up(i,0,2){
        if(i==1){
            up(j,0,3) cin>>t,input[i].pb(t);
        }
        else{
            up(j,0,2) cin>>t,input[i].pb(t);
        }
    }
    go(0,0,input);
    cout<<Ti<<endl;
    return 0;
}
