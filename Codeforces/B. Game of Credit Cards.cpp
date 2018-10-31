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
    string s,m;
    int n,Ti1=0,Ti2=0,cnt2[10]={0},t,temp[10]={0};
    bool flag;
    cin>>n>>s>>m;
    for(int i=0;i<n;i++) cnt2[m[i]-'0']++,temp[m[i]-'0']=cnt2[m[i]-'0'];
    for(int i=0;i<n;i++){
        t=s[i]-'0';
        //cout<<t<<endl;
        flag=1;
        for(int j=t;j<=9;j++){
            //cout<<j<<" "<<temp[j]<<endl;
            if(temp[j]){
                temp[j]--;
                flag=0;
                break;
            }
        }
        if(flag){
            for(int j=0;j<t;j++){
                if(temp[j]){
                    temp[j]--;
                    Ti1++;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        t=s[i]-'0';
        flag=1;
        for(int j=t+1;j<=9;j++){
            if(cnt2[j]){
                cnt2[j]--;
                Ti2++;
                flag=0;
                break;
            }
        }
        if(flag){
            for(int j=0;j<=t;j++){
                if(cnt2[j]){
                    cnt2[j]--;
                    break;
                }
            }
        }
    }
    cout<<Ti1<<endl<<Ti2<<endl;
    return 0;
}



