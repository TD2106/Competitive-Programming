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
#include <iterator>
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
pll data[100005];
ll n,tc,sum=0,idx,check;
set<ll> storeidx;
set<ll>::iterator itr;
int main(){
    cin>>tc;
    while(tc--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>data[i].fi;
            data[i].se=i;
        }
        sort(data+1,data+1+n);
        sum=0;
        idx=1;
        check=2;
        while(idx<=n){
            storeidx.clear();
            if(sum<=data[n].fi&&sum>data[n-1].fi){
                check=1;
                break;
            }
            if(sum>data[n].fi&&sum>data[n-1].fi){
                check=2;
                break;
            }
            data[idx].fi-=sum;
            storeidx.insert(data[idx].se);
            itr=storeidx.find(data[idx].se);
            data[idx].se-=distance(storeidx.begin(),itr);
            //cout<<storeidx.size()<<endl;
            //bug(distance(storeidx.begin(),itr));
            //bug(data[idx].se);
            if(data[idx].fi>=0)
            sum+=(data[idx].fi/data[idx].se+1)*data[idx].se;
            idx++;
        }
        if(check==1) cout<<"Ladia\n";
        else cout<<"Kushagra\n";
    }
    return 0;
}



