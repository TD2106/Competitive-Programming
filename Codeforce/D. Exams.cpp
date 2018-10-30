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
int n,m,d[100005]={0},a[100005]={0},l=1,r,Ti,rem,idx,sub;
bool mark[100005]={0};
bool check(int Ti){
    rem=idx=Ti;
    sub=m;
    while(sub>0&&rem>0&&idx>0){
        while(mark[d[idx]]==1&&idx>0) idx--;
        if(rem>idx) rem=idx;
        /*bug(idx);
        bug(rem);
        bug(sub);*/
        rem-=1+a[d[idx]];
        mark[d[idx]]=1;
        idx--,sub--;
    }
    if(sub==0&&rem>=0) return 1;
    else return 0;
}
int main(){
    cin>>n>>m;
    r=n;
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1;i<=m;i++) cin>>a[i];
    mark[0]=1;
    while(l<r){
        reset(mark);
        mark[0]=1;
        Ti=(l+r)/2;
        if(check(Ti)) r=Ti;
        else l=Ti+1;
    }
    reset(mark);
    mark[0]=1;
    Ti=(l+r)/2;
    if(check(Ti)) cout<<Ti<<endl;
    else cout<<-1<<endl;
    return 0;
}



