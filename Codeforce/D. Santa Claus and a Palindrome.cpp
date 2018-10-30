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
map<string,vi> palin;
map<string,vi> regular;
int main (){
    string s,re;
    int n,k,Ti=0,point,temp,mid=0,mn=0;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> s >> point;
        re=s;
        reverse(all(re));
        if(re==s) palin[s].pb(point);
        else regular[s].pb(point);
    }
    map<string,vi>::iterator itr,itr2;
    for(itr=palin.begin();itr!=palin.end();itr++){
        sort(all((itr->second)));
    }
    for(itr=regular.begin();itr!=regular.end();itr++){
        sort(all((itr->second)));
    }
    //bug(regular.size());
    for(itr=regular.begin();itr!=regular.end();itr++){
        s=re=itr->first;
        reverse(all(re));
        if(regular.count(re)!=0){
            while(regular[s][regular[s].size()-1]+regular[re][regular[re].size()-1]>0&&!regular[s].empty()&&!regular[re].empty()){
                temp=regular[s][regular[s].size()-1]+regular[re][regular[re].size()-1];
                Ti+=temp;
                regular[s].pop_back();
                regular[re].pop_back();
            }
        regular.erase(re);
        }
    }
    //bug(palin.size())
    for(itr=palin.begin();itr!=palin.end();itr++){
        //cout << 1<<endl;
        s=itr->first;
        //bug(s);
        for(int i=palin[s].size()-1;i>0;i-=2){
            //bug(i);
            //bug(i-1);
            if(palin[s][i]>=0&&palin[s][i-1]>=0)
            Ti+=palin[s][i]+palin[s][i-1];
            else if(palin[s][i]>=0&&palin[s][i-1]<0){
                temp=palin[s][i]+palin[s][i-1];
                if(temp>=0){
                    Ti+=temp;
                    if(palin[s][i]-temp>mid) mid=palin[s][i]-temp;
                }
            }
            else break;
        }
        if(palin[s].size()%2&&palin[s][0]>=0) mn=max(palin[s][0],mn);
    }
    if(mn>mid) Ti+=mn;
    else Ti+=mid;
    cout << Ti <<endl;
}

