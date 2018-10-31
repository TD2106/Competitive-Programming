#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define inf "inf"
using namespace std;
typedef long long int ll;
set<ll> bad;
ll b,q,l,m,t,Ti=0;
int main(){
    cin>>b>>q>>l>>m;
    for(int i=0;i<m;i++){
        cin>>t;
        bad.insert(t);
    }
    if(b*q==0){
        if(bad.count(0)&&bad.count(b)||abs(b)>l) cout<<0<<endl;
        else if(bad.count(0)) cout<<1<<endl;
        else cout<<inf<<endl;
    }
    else if(q==1){
        if(bad.count(b)||abs(b)>l) cout<<0<<endl;
        else cout<<inf<<endl;
    }
    else if(q==-1){
        if((bad.count(b)&&bad.count(-b))||abs(b)>l) cout<<0<<endl;
        else cout<<inf<<endl;
    }
    else{
        t=1;
        while(abs(b*t)<=l){
            if(!bad.count(b*t)) Ti++;
            t*=q;
        }
        cout<<Ti<<endl;
    }
    return 0;
}
