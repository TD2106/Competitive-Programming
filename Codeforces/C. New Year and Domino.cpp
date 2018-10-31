#include <bits/stdc++.h>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
char tab[505][505]={0};
int h,w,q,r1,r2,c1,c2,hori[505][505]={0},vert[505][505]={0},Ti;
int main(){
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++) cin>>tab[i][j];
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<w;j++){
            if(tab[i][j]=='.'&&tab[i][j+1]=='.') hori[i][j]=hori[i][j-1]+1;
            else hori[i][j]=hori[i][j-1];
        }
    }
    for(int i=1;i<=w;i++){
        for(int j=1;j<h;j++){
            if(tab[j][i]=='.'&&tab[j+1][i]=='.') vert[j][i]=vert[j-1][i]+1;
            else vert[j][i]=vert[j-1][i];
        }
    }
    /*for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cout<<vert[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cin>>q;
    while(q--){
        cin>>r1>>c1>>r2>>c2;
        Ti=0;
        for(int i=r1;i<=r2;i++){
            Ti+=hori[i][c2-1]-hori[i][c1-1];
        }
        for(int i=c1;i<=c2;i++){
            Ti+=vert[r2-1][i]-vert[r1-1][i];
        }
        cout<<Ti<<endl;
    }
    return 0;
}



