#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <climits>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define repn(a,b) for(int i=a;i<b;i++)
#define rep(a,b) for(int i=a;i<=b;i++)
#define reset(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<ll,ll>pii;
typedef vector<int> vi;
typedef vector<ll> vii;

ll nNum;
ll tab[210][210];
ll num[210];

void calTab(){
    for(ll i=0;i<nNum;i++) tab[i][i] = 1;
    for(ll len=1;len<nNum;len++){
        for(ll i=0;i<nNum-len;i++){
            ll j = i+len;
            tab[i][j] = LLONG_MAX;
            for(ll k=i;k<j;k++){
                tab[i][j] = min(tab[i][j],tab[i][k]+tab[k+1][j]);
            }
            if(num[i]==num[j]) tab[i][j]--;
        }
    }
    return;
}

int main(){
    //fr("in.txt");
    //fw("out.txt");

    cin >> nNum;
    for(ll i=0;i<nNum;i++) cin >> num[i];
    calTab();
    cout << tab[0][nNum-1] << endl;

    return 0;
}




