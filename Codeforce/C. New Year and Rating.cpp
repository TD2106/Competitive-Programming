#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
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
    int n,c[216107]={0},d[216107]={0},Ti=0,st=0,minpos=-1000000000,t=0;
    bool im=0,in=1,flag=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c[i]>>d[i];
        if(d[i]==2) in=0;
        if(d[i]==2&&flag==0) st=i,flag=1;
        if(i!=0) if(d[i]==2&&c[i-1]>=0&&d[i-1]==1||d[i]==1&&c[i-1]<=0&&d[i-1]==2) im = 1;
    }
    for(int i=0;i<st;i++) t+=c[i];
    //bug(t);
    if(in) cout<<"Infinity\n";
    else if(im) cout<<"Impossible\n";
    else{
        if(st!=0&&d[st-1]==1) minpos=1900+t;
        if(minpos>=1900){
            cout<<"Impossible\n";
            return 0;
        }
        Ti=1899+c[st];
        minpos+=c[st];
        //bug(minpos);
        for(int i=st+1;i<n;i++){
            if(d[i]==1&&Ti>=1900) Ti+=c[i],minpos=1900+c[i];
            else if(d[i]==1&&Ti<1900){
                im=1;
                break;
            }
            else if(d[i]==2&&Ti>=1900&&minpos<1900) Ti=1899+c[i],minpos+=c[i];
            else if(d[i]==2&&Ti>=1900&&minpos>=1900){
                im=1;
                break;
            }
            else if(d[i]==2&&Ti<1900) Ti+=c[i],minpos+=c[i];
        }
        if(im) cout<<"Impossible\n";
        else cout<<Ti<<endl;
    }
    return 0;
}



