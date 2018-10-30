#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n[3],p[3],need[3],totalNeed=0,Ti=0,r,t,m=1e9;
string s;
int main(){
    cin>>s;
    for(int i=0;i<3;i++) cin>>n[i];
    for(int i=0;i<3;i++) cin>>p[i];
    cin>>r;
    for(int i=0;i<s.size();i++){
        if(s[i]=='B') need[0]++,totalNeed+=p[0];
        else if(s[i]=='S') need[1]++,totalNeed+=p[1];
        else need[2]++,totalNeed+=p[2];
    }
    for(int i=0;i<3;i++){
       // cout<<need[i]<<endl;
        if(need[i]==0) continue;
        else m=min(m,n[i]/need[i]);
    }
    Ti+=m;
    cout<<Ti<<endl;
    for(int i=0;i<3;i++){
        if(need[i]==0) n[i]=0;
        else n[i]-=m*need[i];
       // cout<<n[i]<<endl;
    }

    //cout<<Ti<<endl;
    while(1){
        bool flag=1;
        t=0;
        for(int i=0;i<3;i++){
            if(n[i]) flag=0;
            if(n[i]>=need[i]) n[i]-=need[i];
            else{
                t+=(need[i]-n[i])*p[i];
                n[i]=0;
            }
        }
        if(flag) break;
        //cout<<t<<endl;
        if(r>=t) r-=t,Ti++;
        else{
            r=0;
            break;
        }
    }
    Ti+=r/totalNeed;
    cout<<Ti<<endl;
    return 0;
}
