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
const int N = 200000;
ll BIT[N + 5]= {0}, n, T, Ti = 0, currentCandies = 0, a[N + 5] = {0}, totalPrice;
void update(ll x, int idx){
    while(idx <= N){
        BIT[idx] += x;
        idx += (idx & (-idx));
    }
}

ll query(int idx){
    ll sum=0;
    while(idx>0){
        sum += BIT[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

ll range(int l, int r){
    return query(r) - query(l - 1);
}

int firstBiggerPrice(){
    int l = 1, r = n, mid, ans;
    while(l <= r){
        mid = (l + r) / 2;
        if(range(1, mid) > T){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> T;
    up(i, 1, n){
        cin >> a[i];
        update(a[i], i);
    }
    currentCandies = n;
    while(currentCandies != 0 && T > 0){
        totalPrice = range(1, n);
        if(T >= totalPrice){
            Ti += currentCandies * (T / totalPrice);
            T -= totalPrice * (T / totalPrice);
        }else{
            while(T < range(1, n)){
                int index = firstBiggerPrice();
                update(-a[index], index);
                currentCandies -= 1;
            }
        }
    }
    cout << Ti << endl;
    return 0;
}
