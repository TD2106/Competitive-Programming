#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n;
double p,dp[100005]={0},Ti=0,cur=0,left,temp;
bool flag=0;
struct obj{
    double a,b,t;
}device[100005];
bool cmp(obj a,obj b){
    return a.t<b.t;
}
int main(){
    cin>>n>>p;
    for(int i=0;i<n;i++){
        cin>>device[i].a>>device[i].b;
        device[i].t=device[i].b/device[i].a;
    }
    sort(device,device+n,cmp);
    for(int i=0;i<n;i++){
        if(i==0) dp[i]=device[i].a;
        else dp[i]=dp[i-1]+device[i].a;
    }
    //for(int i=0;i<n;i++) cout<<device[i].t<<endl;
    if(p>=dp[n-1]) cout<<-1<<endl;
    else{
        for(int i=0;i<n;i++){
            if(i==n-1) Ti+=p/dp[n-1];
            else{
                Ti=device[i].t;
                temp=device[i+1].t-device[i].t;
                temp*=dp[i];
                //cout<<temp<<endl;
                if(cur+temp/p>device[i+1].t){
                    Ti+=device[i].b/(dp[i]-p);
                    break;
                }
                else cur+=temp/p;
            }
        }
        cout<<Ti<<endl;
    }
    return 0;
}
