#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    string s;
    int Ti=0;
    cin>>s;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]) Ti++;
    }
    if(Ti==0&&s.size()%2==1) cout<<"YES\n";
    else if(Ti!=1) cout<<"NO\n";
    else cout<<"YES\n";
    return 0;
}
