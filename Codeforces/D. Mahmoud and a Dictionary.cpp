#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
int dsu[200005]={0},n,m,q,t,a,b;
map<string,int> mp;
string s1,s2;
int fn(int x){
    if(x==dsu[x]) return x;
    else return dsu[x]=fn(dsu[x]);
}
void un(int x,int y){
    x=fn(x);
    y=fn(y);
    if(x==y) return;
    if(x<=n) swap(x,y);
    dsu[x]=y;
}
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>s1;
        mp[s1]=i;
        dsu[i]=i;
        dsu[i+n]=i+n;
    }
    for(int i=1;i<=m;i++){
        cin>>t>>s1>>s2;
        a=fn(mp[s1]);
        b=fn(mp[s2]);
        if(t==1){
            if(a==fn(b+n)||b==fn(a+n)) cout<<"NO\n";
            else{
                cout<<"YES\n";
                un(a,b);
                un(a+n,b+n);
            }
        }
        else{
            if(a==b||fn(a+n)==fn(b+n)) cout<<"NO\n";
            else{
                cout<<"YES\n";
                un(a,b+n);
                un(b,a+n);
            }
        }
        //for(int i=1;i<=2*n;i++) cout<<dsu[i]<<" ";
        //cout<<endl;
    }
    while(q--){
        cin>>s1>>s2;
        a=fn(mp[s1]);
        b=fn(mp[s2]);
        if(a==b) cout<<1<<endl;
        else if(a==fn(b+n)||b==fn(a+n)) cout<<2<<endl;
        else cout<<3<<endl;
    }
    return 0;
}



