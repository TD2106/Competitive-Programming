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
ll powerOf3[50] = {0}, M, currentIndex = 0;
vi minusWeight, plusWeight;
void preCompute(){
    powerOf3[0] = 1;
    up(i, 1, 39){
        powerOf3[i] = powerOf3[i - 1] * 3;
    }
}

bool isPowerOf3(ll x){
    up(i, 0 , 39){
        if(x == powerOf3[i]){
            return true;
        }
    }
    return false;
}

int findPowerOf3(ll x){
    up(i, 0 , 39){
        if(x == powerOf3[i]){
            return i;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    preCompute();
    cin >> M;
    while(!isPowerOf3(M)){
        if(M % 3 == 0){
            currentIndex++;
            M /= 3;
        }else if(M % 3 == 1){
            M--;
            plusWeight.pb(currentIndex);
        }else if(M % 3 == 2){
            M++;
            minusWeight.pb(currentIndex);
        }
    }
    plusWeight.pb(currentIndex + findPowerOf3(M));
    if(minusWeight.size() == 0) cout << -1 << endl;
    else{
        for(int i : minusWeight) cout << i << " ";
        cout << endl;
    }
    for(int i : plusWeight) cout << i << " ";
    cout << endl;
    return 0;
}
