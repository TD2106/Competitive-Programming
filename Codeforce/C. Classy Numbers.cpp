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
ll q, l, r, c[25][25] = {0}, powerOfTen[20] = {0}, classyNumberForDigit[20] = {0}, Ti = 0, powerOfNine[3] = {0};
void preCompute(){
    c[0][0] = c[0][1] = c[1][1] = 1;
    powerOfNine[0] = 1;
    powerOfNine[1] = 9;
    powerOfNine[2] = 81;
    up(i,1,20){
        up(j,0,3){
            if(j == 0) c[j][i] = 1;
            else c[j][i] = c[j-1][i-1] + c[j][i-1];
        }
    }
    powerOfTen[0] = 1;
    up(i,1,18){
        powerOfTen[i] = powerOfTen[i-1] * 10LL;
    }
    classyNumberForDigit[1] = 1;
    classyNumberForDigit[2] = 10;
    classyNumberForDigit[3] = 100;
    up(i, 4, 18){
        up(j, 1 , 2){
            classyNumberForDigit[i] += c[j][i - 1] * powerOfNine[j];
        }
    }
}
int numberOfDigit(ll x){
    int result = 0;
    while(x){
        result += 1;
        x /= 10;
    }
    return result;
}
bool isClassy(ll x){
    if(x == 0) return 0;
    int digitNotZero = 0;
    while(x){
        if(x%10 != 0) digitNotZero += 1;
        x /= 10;
    }
    return digitNotZero <= 3;
}
ll classyNumberFromOneTo(ll x){
    ll result = 0;
    int digit = numberOfDigit(x);
    up(i, 1, digit - 1){
        result += 9 * classyNumberForDigit[i];
    }
    stringstream ss;
    string startNum, endNum;
    ss << x;
    ss >> endNum;
    ss.clear();
    ss << powerOfTen[digit - 1];
    ss >> startNum;
    ss.clear();
    int curDigitNotZero = 1, totalDigitNotZero = 0;
    up(i, 0, digit - 1){
        if(curDigitNotZero > 3) break;
        while(startNum[i] < endNum[i]){
            if(startNum[i] != '0') totalDigitNotZero = curDigitNotZero + 1;
            else totalDigitNotZero = curDigitNotZero;
            up(j, 0, 3 - totalDigitNotZero){
                result += c[j][digit - i - 1] * powerOfNine[j];
            }
            startNum[i]++;
        }
    }
    result += int(isClassy(x));
    return result;
}
int main(){
    ios_base::sync_with_stdio(0);
    preCompute();
    cin >> q;
    while(q--){
        cin >> l >> r;
        Ti = classyNumberFromOneTo(r) - classyNumberFromOneTo(l-1);
        cout << Ti << endl;
    }
    return 0;
}
