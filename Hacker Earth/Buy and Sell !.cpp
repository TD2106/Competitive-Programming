#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 100005
using namespace std;
typedef long long int ll;
map<string,int> price;
map<string,int> amount;
int n,BIT[M]={0},p,q,Ti,mx=100000;
string s;
char type;
void update(int idx,int x){
    while(idx<=mx){
        BIT[idx]+=x;
        idx+=idx&-idx;
    }
}
int query(int idx){
    int sum=0;
    while(idx>0){
        sum+=BIT[idx];
        idx-=idx&-idx;
    }
    return sum;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>s>>p;
        price[s]=p;
        amount[s]==0;
	}
	cin>>q;
	while(q--){
        cin>>type;
        if(type=='+'){
            cin>>s;
            amount[s]++;
            update(price[s],1);
        }
        else if(type=='-'){
            cin>>s;
            if(amount[s]){
                amount[s]--;
                update(price[s],-1);
            }
        }
        else{
            cin>>p;
            Ti=query(mx)-query(p);
            cout<<Ti<<endl;
        }
	}
	return 0;
}
