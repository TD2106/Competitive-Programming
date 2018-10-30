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
#include <ctime>

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
#define fu(i,m,n) for(int i=m, _n = n;i<=_n;i++)
#define fd(i,m,n) for(int i=m, _n = n;i>=_n;i--)
using namespace std;
typedef long double lf;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef unsigned long long ull;
/*
 * Code begins here
 */

int k,h,d,x,y,mi,ss,ma,res,c,i;
ll m,n;
const int N=100100;
int st[100]= {0,1,1,1,2,1,2,2,2,3};
int sc[100]= {1,1,1,1,2,1,2,1,1,3};
int main()
{
    /*string _t[] = {"1","2","3","4","5","6","7","8","9","10",
                   "11","12","13","14","15","16","17","18","19","20",
                   "21","22","23","24","25","26","27","28","29","30",
                   "31","32","33","34","35","36","37","38","39","40",
                   "41","42","43","44","45","46","47","48","49"};


    //for(int i=0;i<5;i++){
        string _test = "49";

        string in = _test + ".in";
        string out = _test + ".ans";

        freopen(in.c_str(),"r",stdin);
        freopen(out.c_str(),"w",stdout);*/

        ios_base::sync_with_stdio(false);
        cin>>n>>c;
        if(n%1000!=0) cout<<0;
        else
        {
            ss=1;
            m=n/1000;
            i=0;
            while(m>0)
            {
                if(i<c)
                {
                    i++;
                    k=m%10;
                    res+=st[k];
                    ss*=sc[k];
                    m/=10;
                }
                else
                {
                    if(m<5)
                    {
                        res+=st[m];
                        ss*=sc[m];
                        break;
                    }
                    else
                    {
                        res+=(m/5)-1;
                        k=m%5 + 5;
                        res+=st[k];
                        ss*=sc[k];
                        break;
                    }
                }
            }
            cout << res << " " << ss << endl;;
        }
    //}
    return 0;
}


