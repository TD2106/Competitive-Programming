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
#define MAX 100005
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n, a[MAX], b[MAX], possibleMin = 0, currentUnusedColor = 1, numZero = 0;
map<int, pii> currentAvailableChoices;
bool isPossible = true;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    up(i, 1, n){
        cin >> a[i];
        numZero += (int)(a[i] == 0);
    }
    if(numZero != 0 && numZero != n){
        cout << "Impossible\n";
        return 0;
    }
    up(i, 1, n){
        if(currentAvailableChoices.count(a[i])){
            b[i] = currentAvailableChoices[a[i]].fi;
            currentAvailableChoices[a[i]].se = currentAvailableChoices[a[i]].se - 1;
            if(!currentAvailableChoices[a[i]].se){
                currentAvailableChoices.erase(a[i]);
            }
        } else {
            if(a[i] >= possibleMin){
                b[i] = currentUnusedColor;
                if(a[i] != n - 1){
                    currentAvailableChoices[a[i]] = {currentUnusedColor, n - a[i] - 1};
                }
                possibleMin += n - a[i];
                currentUnusedColor++;
            }else{
                isPossible = false;
                break;
            }
        }
    }
    if(isPossible){
        cout << "Possible\n";
        up(i, 1, n){
            cout << b[i] << ' ';
        }
    }else{
        cout << "Impossible\n";
    }
    return 0;
}
