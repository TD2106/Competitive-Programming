#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define endl '\n'
#define bug(x) cout<< #x << " = " << x <<endl
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(),a.end()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
int BIT[100005]={0},tree[400005]={0};
void updateBIT(int idx,int val){
    while(idx<=100000){
        BIT[idx]+=val;
        idx+=idx&(-idx);
    }
}
int queryBIT(int idx){
    int res=0;
    while(idx>0){
        res+=BIT[idx];
        idx-=idx&(-idx);
    }
    return res;
}
int rangeBIT(int l,int r){
    return queryBIT(r) - queryBIT(l-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    updateBIT(1,10);
    updateBIT(2,5);
    updateBIT(3,1);
    updateBIT(4,2);
    cout<<rangeBIT(3,4)<<endl;
    updateBIT(4,3);
    cout<<rangeBIT(2,4)<<endl;
    return 0;
}





