#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
map<int,int> mp1,mp2;
map<int,int>::iterator itr;
int n,a,b,games,t1,t2,t;
bool vis[100005]={0},flag;
vector<int> prime;
void sieve(){
    for(ll i=2;i*i<=1e9;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(ll j=i*i;j<=1e5;j+=i) vis[j]=1;
        }
    }
}
void decompose(int &x,map<int,int>& mp){
    for(int i=0;i<prime.size()&&x>=prime[i];i++){
        if(x%prime[i]==0){
            while(x%prime[i]==0){
                mp[prime[i]]++;
                x/=prime[i];
            }
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	sieve();
	cin>>n;
	while(n--){
        cin>>a>>b;
        mp1.clear();
        mp2.clear();
        if(a==1&&b==1){
            cout<<"Yes\n";
            continue;
        }
        decompose(a,mp1);
        decompose(b,mp2);
        if(a!=1||b!=1||mp1.size()!=mp2.size()){
            cout<<"No\n";
            continue;
        }
        flag=1;
        for(itr=mp1.begin();itr!=mp1.end();itr++){
            t=itr->first;
            if(mp2.count(t)==0){
                flag=0;
                break;
            }
            else{
                t1=mp1[t];
                t2=mp2[t];
                if((t1+t2)%3!=0||min(t1,t2)<(t1+t2)/3){
                    flag=0;
                    break;
                }
            }
        }
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
	}
	return 0;
}
