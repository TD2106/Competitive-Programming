#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define mod 1000000007
using namespace std;
typedef long long int ll;
ll curB=0,Ti=0;
int main(){
    string s;
    cin>>s;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='a'){
            Ti+=curB;
            Ti%=mod;
            curB*=2;
            curB%=mod;
        }
        else curB++;
    }
    cout<<Ti<<endl;
	return 0;
}
