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
string s;
int n, x, y, Ti = -1, leftV, rightV, mid, u[200005] = {0}, d[200005] = {0}, l[200005] = {0}, r[200005] = {0}, desX = 0, desY = 0, temp;
bool check(int length){
    int tempX, tempY;
    up(i, length, n){
        tempY = desY - (u[i] - u[i - length]) + (d[i] - d[i - length]);
        tempX = desX - (r[i] - r[i - length]) + (l[i] - l[i - length]);
        temp = abs(x - tempX) + abs(y - tempY);
        if(length >= temp && (length - temp) % 2 == 0){
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> s >> x >> y;
    up(i, 1, n){
        switch(s[i - 1]){
        case 'U' :
            u[i] = 1;
            desY++;
            break;
        case 'D' :
            d[i] = 1;
            desY--;
            break;
        case 'L' :
            l[i] = 1;
            desX--;
            break;
        case 'R' :
            r[i] = 1;
            desX++;
            break;
        }
        u[i] += u[i - 1];
        d[i] += d[i - 1];
        l[i] += l[i - 1];
        r[i] += r[i - 1];
    }
    leftV = 0, rightV = n;
    while(leftV <= rightV){
        mid = (leftV + rightV) / 2;
        if(check(mid)){
            Ti = mid;
            rightV = mid - 1;
        }else{
            leftV = mid + 1;
        }
    }
    cout << Ti << endl;
    return 0;
}
