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
#include <time.h>
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
#define tc() int tc; cin >> tc; for(int _tc=0;_tc<tc;_tc++)
#define stop() int _stop; cin >> _stop;

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;

using namespace std;

const int SIZE=210;
int N,tmpN,a[SIZE],Em[SIZE][SIZE][2];
//longest[i]: contain a[i]
//maxlength: not necessarily contain a[i]
//vector<int>vt(0,0);

void prepare()
{
    reset(Em);
    cin>>N>>a[1];
    int j=2;
    for (int i=2;i<=N;i++)
    {
        cin>>a[j];
        if (a[j]==a[j-1])
            j--;
        j++;
    }
    a[j]=1000000000;
    N=j-1;
//    for (int t=1;t<=j;t++) cout<<a[t]<<" ";
//    cout<<endl;
}
//int check=0;
int dpEmail(int start,int finish,int type)//type:0:left, 1:right
{
    if (Em[start][finish][type]!=0) return Em[start][finish][type];
    if (finish<start) return 0;
    int tmp;
    (type==1)? (tmp=finish+1):(tmp=start-1);
    if (start==finish)
    {
        if (a[tmp]==a[start])
            return 0;
        else return 1;
    }
    int MinMove=1000,tmpMove=0;
    for (int i=start;i<=finish;i++)
    {
        tmpMove+=dpEmail(start,i-1,1);
        if (tmpMove>MinMove) continue;
        tmpMove+=dpEmail(i+1,finish,0);
        if (a[tmp]!=a[i]) tmpMove++;
        MinMove=min(MinMove,tmpMove);
        tmpMove=0;
    }
//    check++;
//    cout<<start<<" "<<finish<<" "<<type<<" "<<MinMove<<endl;
    Em[start][finish][type]=MinMove;
    return MinMove;
}
int main()
{
    prepare();
    cout<<dpEmail(1,N,1)<<endl;
//    cout<<check<<endl;
}

/* Each time an amount of a specific type is fixed
 
 */

