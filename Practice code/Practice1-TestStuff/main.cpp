#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define endl '\n'
#define bug(x) cout<< #x << " = " << x <<endl
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
class Compare{
public:
    bool operator()(int a,int b){
        return a>b;
    }
};
class Compare1{
public:
    bool operator() (int a,int b){
        return a>b;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
//    up(i,1,10) cout<<i<<endl;
//    down(i,10,1) cout<<i<<endl;
//    vi test;
//    down(i,10,1) test.pb(i);
//    sort(all(test));
//    for(int i:test) cout<<i<<endl;
//    orderedSet testSet;
//    testSet.insert(1);
//    testSet.insert(3);
//    if(testSet.find_by_order(10)==testSet.end()) cout<<1<<endl;
//    cout<<*testSet.lower_bound(2)<<endl;
//    ll a = LLONG_MIN;
//    cout<<pow(2,10)<<endl;
//    cout<<a<<endl;
//    cout<<(6^(1<<1))<<endl;
    vi test;
    up(i,1,10) test.pb(i);
    sort(all(test),Compare1());
    priority_queue<int,vi,Compare1> pq;
    up(i,1,10) pq.push(i);
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    map<int,int,Compare1> myMap;
    return 0;
}
