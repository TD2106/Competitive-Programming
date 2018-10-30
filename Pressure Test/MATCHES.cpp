#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdio>
#include <cmath>
using namespace std;

// base and base_digits must be consistent
typedef vector<int> lnum;
const int base = 1000 * 1000 * 1000;
void Output(lnum& a) {
  printf("%d", a.empty() ? 0 : a.back());
  for (int i = (int) a.size() - 2; i >= 0; --i)
     printf("%09d", a[i]);
}
void Addition(lnum& a, lnum& b) {
    int carry = 0;
    for (size_t i = 0; i < max(a.size(),
                b.size()) || carry; ++i) {
        if (i == a.size()) a.push_back(0);
        a[i] += carry + (i < b.size() ? b[i] :0);
        carry = a[i] >= base;
        if (carry) a[i] -= base;
    }
}
void Input(string s, lnum& a) {
  for (int i = (int)s.length(); i>0; i-=9) {
   if (i < 9)
     a.push_back(atoi(s.substr(0,i).c_str()));
   else
     a.push_back(atoi(s.substr(i-9, 9).c_str()));
  }
   while (a.size() > 1 && a.back() == 0)
     a.pop_back();
} //Remove leading 0s

// random tests
int main() {
    int n;
    lnum dp[2005],Ti;

    int cost[10] = {6,2,5,5,4,5,6,3,7,6};
    cin>>n;
    for(int i=0;i<=n;i++){
        Input("0",dp[i]);
        if(i==0) Input("1",dp[i]);;
        //cout<<dp[i]<<endl;
        for(int j=0;j<10;j++){
            if(i==0&&j==0) continue;
            if(i+cost[j]<=n){
                //cout<<i<<" "<<j<<endl;
                Addition(dp[i+cost[j]],dp[i]);
            }
        }
    }
    for(int i=1;i<=n;i++) Addition(Ti,dp[i]);
    if(n>=6) Addition(Ti,dp[0]);
    Output(Ti);
}
