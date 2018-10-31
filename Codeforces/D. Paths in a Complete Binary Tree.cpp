#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define pb push_back
using namespace std;
typedef long long int ll;

int main(){
    ll n,q,u,layer=0,r,Ti,cur,t;
    vector<ll> trace;
    string s;
    cin>>n>>q;
    t=n;
    while(t) layer++,t/=2;
    r=n/2+1;
    //cout<<layer<<endl;
    while(q--){
        trace.clear();
        cin>>u>>s;
        Ti=r;
        t=(ll)pow(2,layer-2);
        cur=1;
        //cout<<t<<endl;
        while(Ti!=u){
            if(u<Ti) Ti-=t,trace.pb(1);
            else Ti+=t,trace.pb(-1);
            cur++;
            t/=2;
        }
        //cout<<cur<<" "<<t<<endl;
        for(int i=0;i<s.size();i++){
            if((cur==layer&&(s[i]=='R'||s[i]=='L'))||(cur==1&&s[i]=='U')) ;
            else{
                if(s[i]=='R'){
                    Ti+=t;
                    t/=2;
                    cur++;
                    trace.pb(-1);
                }
                else if(s[i]=='L'){
                    Ti-=t;
                    t/=2;
                    cur++;
                    trace.pb(1);
                }
                else{
                    cur--;
                    if(t!=0) t*=2;
                    else t=1;
                    Ti+=trace.back()*t;
                    trace.pop_back();
                }
            }
           // cout<<Ti<<" "<<cur<<" "<<t<<endl;
        }
        cout<<Ti<<endl;
    }
 //   system("pause");
    return 0;
}
