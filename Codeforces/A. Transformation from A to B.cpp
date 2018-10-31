#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
vi Ti;
int main(){
    int a,b;
    cin>>a>>b;
    while(b>=a){
        Ti.pb(b);
        if(b==a) break;
        if(b%10==1) b/=10;
        else if(b%2==0) b/=2;
        else{
            cout<<"NO\n";
            return 0;
        }
    }
    if(Ti[Ti.size()-1]!=a){
        cout<<"NO\n";
    }
    else{
        reverse(all(Ti));
        cout<<"YES\n";
        cout<<Ti.size()<<endl;
        for(int i=0;i<Ti.size();i++) cout<<Ti[i]<<" ";
    }
    return 0;
}
