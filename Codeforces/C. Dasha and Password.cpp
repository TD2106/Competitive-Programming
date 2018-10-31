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
int n,m,Ti=100000,mn[51][3],c[3]={0};
string pas,poi[51];
int main(){
    for(int i=0;i<=50;i++){
        for(int j=0;j<3;j++) mn[i][j]=1000;
    }
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>poi[i];
        pas+=poi[i][0];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(poi[i][j]>='a'&&poi[i][j]<='z'){
                mn[i][0]=min(mn[i][0],min(j-0,m-j));
            }
            if(poi[i][j]>='0'&&poi[i][j]<='9'){
                mn[i][1]=min(mn[i][1],min(j-0,m-j));
            }
            if(poi[i][j]=='*'||poi[i][j]=='#'||poi[i][j]=='&'){
                mn[i][2]=min(mn[i][2],min(j-0,m-j));
            }
        }
    }
    for(int i=0;i<n;i++){
        if(pas[i]>='a'&&pas[i]<='z') c[0]++;
        else if(pas[i]>='0'&&pas[i]<='9') c[1]++;
        else c[2]++;
    }
    if(c[0]&&c[1]&&c[2]){
        cout<<0<<endl;
        return 0;
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(j==i||k==i||j==k) continue;
                    Ti=min(Ti,mn[i][0]+mn[j][1]+mn[k][2]);
                }
            }
        }
        cout<<Ti<<endl;
    }
    return 0;
}



