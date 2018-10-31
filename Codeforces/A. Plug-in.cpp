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
stack<char> myStack;
string s,Ti;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    for(char c:s){
        if(myStack.empty()) myStack.push(c);
        else if(myStack.top()==c) myStack.pop();
        else myStack.push(c);
    }
    while(!myStack.empty()){
        Ti+=myStack.top();
        myStack.pop();
    }
    reverse(Ti.begin(),Ti.end());
    cout<<Ti<<endl;
    return 0;
}
