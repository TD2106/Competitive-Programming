#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n, m, d, dayDrinkCoffee[200005] = {0};
pii arr[200005];
set<pii> minLast;
vector<vi> coffeeBreakInDay;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> d;
    up(i, 1, n){
        cin >> arr[i].fi;
        arr[i].se = i;
    }
    sort(arr + 1, arr + 1 + n);
    up(i, 1, n){
        if(minLast.empty()){
            vi temp;
            temp.pb(arr[i].fi);
            coffeeBreakInDay.pb(temp);
            minLast.insert({arr[i].fi, 0});
            dayDrinkCoffee[arr[i].se] = 1;
        }
        else{
            pii currentMin = *minLast.begin();
            if(arr[i].fi - currentMin.fi - 1 >= d){
                minLast.erase(currentMin);
                minLast.insert({arr[i].fi, currentMin.se});
                coffeeBreakInDay[currentMin.se].pb(arr[i].fi);
                dayDrinkCoffee[arr[i].se] = currentMin.se + 1;
            }
            else{
                minLast.insert({arr[i].fi, coffeeBreakInDay.size()});
                vi temp;
                temp.pb(arr[i].fi);
                coffeeBreakInDay.pb(temp);
                dayDrinkCoffee[arr[i].se] = coffeeBreakInDay.size();
            }
        }
    }
    cout << coffeeBreakInDay.size() << endl;
    up(i, 1, n){
        cout << dayDrinkCoffee[i] << ' ';
    }
    return 0;
}
