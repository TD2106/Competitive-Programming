#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
struct Node{
    int open,close,optimal;
    Node(){};
    Node (int open,int close,int optimal){
        this->open=open;
        this->close=close;
        this->optimal=optimal;
    }
}tree[4*1000005];
Node operator + (const Node& left, const Node& right){
    int temp=min(left.open,right.close);
    Node result = Node(left.open+right.open-temp,left.close+right.close-temp,left.optimal+right.optimal+2*temp);
    return result;
}
string s;
int q,u,v,Ti;
void build(int id,int l,int r){
    if(l>r) return;
    if(l==r){
        //cout<<l<<" "<<id<<endl;
        if(s[l]=='(') tree[id]=Node(1,0,0);
        else tree[id]=Node(0,1,0);
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=tree[id*2]+tree[id*2+1];
}
int query(int x,int y,int l,int r,int id){
    if(x>r||y<l) return 0;
    if(x<=l&&r<=y) return tree[id].optimal;
    int mid=(l+r)/2;
    return query(x,y,l,mid,id*2)+query(x,y,mid+1,r,id*2+1);
}
int main(){
	ios_base::sync_with_stdio(0);
    cin>>s;
    build(1,0,s.size()-1);
    cin>>q;
    while(q--){
        cin>>u>>v;
        u--,v--;
        Ti=query(u,v,1,s.size()-1,1);
        cout<<Ti<<endl;
    }
	return 0;
}
