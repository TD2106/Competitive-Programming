#include <bits/stdc++.h>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int main(){
    set<string> person;
    string s1,s2;
    int n;
    cin>>s1>>s2>>n;
    cout<<s1<<" "<<s2<<endl;
    person.ins(s1);
    person.ins(s2);
    for(int i=0;i<n;i++){
        cin>>s1>>s2;
        person.erase(s1);
        person.ins(s2);
        for(set<string>::iterator itr=person.begin();itr!=person.end();itr++){
            cout<<*itr<<" ";
        }
        cout<<endl;
    }
    return 0;
}



