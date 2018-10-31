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
typedef pair<char,int> pci;
pci command[500005],Ti[3];
int n,bit[10]={0};
int process(char type,int isSet,int toBeProcess){
    if(type=='|'){
         if(isSet) return 1;
         else return toBeProcess;
    }
    else if(type=='^'){
         if(isSet){
            if(toBeProcess==0) return 1;
            else if(toBeProcess==1) return 0;
            else if(toBeProcess==3) return 4;
            else return 3;
         }
         else return toBeProcess;
    }
    else{
         if(isSet) return toBeProcess;
         else return 0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    up(i,0,9) bit[i]=3;
    cin>>n;
    up(i,1,n) cin>>command[i].fi>>command[i].se;
    up(i,1,n){
        up(j,0,9){
            if(command[i].se&(1<<j)) bit[j]=process(command[i].fi,1,bit[j]);
            else bit[j]=process(command[i].fi,0,bit[j]);
        }
    }
    Ti[0].fi='^',Ti[1].fi='|',Ti[2].fi='&';
    up(i,0,9){
        if(bit[i]==1){
            Ti[1].se|=(1<<i);
            Ti[2].se|=(1<<i);
        }
        else if(bit[i]==3) Ti[2].se|=(1<<i);
        else if(bit[i]==4) Ti[2].se|=(1<<i),Ti[0].se|=(1<<i);
    }
//    up(i,0,9) cout<<bit[i]<<endl;
    cout<<3<<endl;
    up(i,0,2) cout<<Ti[i].fi<<' '<<Ti[i].se<<endl;
    return 0;
}
