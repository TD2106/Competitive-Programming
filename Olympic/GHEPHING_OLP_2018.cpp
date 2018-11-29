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
typedef vector<pii> vpii;
int w, h, n;
bool ans = false;
vpii createNewRectangles(vpii oldRec, bool used[], pii combinedRec){
    vpii result;
    result.pb(combinedRec);
    up(i, 0, oldRec.size() - 1){
        if(!used[i]){
            result.pb(oldRec[i]);
        }
    }
    return result;
}
void recursion(vpii rectangles){
    if(rectangles.size() == 1){
        ans = true;
    }
    if(ans){
        return;
    }
    bool used[rectangles.size()] = {0};
    up(i, 0, rectangles.size() - 1){
        up(j, i + 1, rectangles.size() - 1){
            if(rectangles[i].fi == rectangles[j].fi){
                used[i] = used[j] = true;
                recursion(createNewRectangles(rectangles, used, {rectangles[i].fi, rectangles[i].se + rectangles[j].se}));
                used[i] = used[j] = false;

            }
            if(rectangles[i].fi == rectangles[j].se){
                used[i] = used[j] = true;
                recursion(createNewRectangles(rectangles, used, {rectangles[i].fi, rectangles[i].se + rectangles[j].fi}));
                used[i] = used[j] = false;
            }
            if(rectangles[i].se == rectangles[j].fi){
                used[i] = used[j] = true;
                recursion(createNewRectangles(rectangles, used, {rectangles[i].se, rectangles[i].fi + rectangles[j].se}));
                used[i] = used[j] = false;
            }
            if(rectangles[i].se == rectangles[j].se){
                used[i] = used[j] = true;
                recursion(createNewRectangles(rectangles, used, {rectangles[i].se, rectangles[i].fi + rectangles[j].fi}));
                used[i] = used[j] = false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    while(n--){
        vpii input;
        ans = false;
        up(i, 1, 4){
            cin >> w >> h;
            if(w > h) swap(w, h);
            input.pb({w, h});
        }
        recursion(input);
        if(ans) cout << "YES\n";
        else cout <<"NO\n";
    }
    return 0;
}
