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

int main(){
    int m,s,t;
    string Tin,Tix;
    cin>>m>>s;
    if((s==0&&m!=1)||s>9*m){
        cout<<"-1 -1\n";
        return 0;
    }
    t=s;
    for(int i=0;i<m;i++){
        for(int j=9;j>=0;j--){
            if(t-j>=0){
                char temp='0'+j;
                Tix+=temp;
                t-=j;
                break;
            }
        }
    }
    t=s;
    for(int i=0;i<m;i++){
        for(int j=0;j<=9;j++){
            if(i==0&&j==0&&m!=1) continue;
            if(t-j>=0&&(t-j)<=9*(m-i-1)){
                char temp='0'+j;
                Tin+=temp;
                t-=j;
                break;
            }
        }
    }
    cout<<Tin<<" "<<Tix<<endl;
    return 0;
}



