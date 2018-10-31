#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
set< pair<vi,vi> > vis;
int n,k1,k2,t,game=0;
void process(vi a,vi b){
    int t1,t2;
    if(a.size()==0){
        cout<<game<<" "<<2<<endl;
        exit(0);
    }
    if(b.size()==0){
        cout<<game<<" "<<1<<endl;
        exit(0);
    }
    if(vis.count(mp(a,b))){
        cout<<-1<<endl;
        exit(0);
    }
    vis.insert(mp(a,b));
    game++;
    if(a[0]>b[0]){
        t1=a[0];
        t2=b[0];
        a.erase(a.begin());
        b.erase(b.begin());
        a.pb(t2);
        a.pb(t1);
    }
    else{
        t1=a[0];
        t2=b[0];
        a.erase(a.begin());
        b.erase(b.begin());
        b.pb(t1);
        b.pb(t2);
    }
    process(a,b);
}
int main(){
    vi f,s;
    cin>>n;
    cin>>k1;
    while(k1--){
        cin>>t;
        f.pb(t);
    }
    cin>>k2;
    while(k2--){
        cin>>t;
        s.pb(t);
    }
    process(f,s);
	return 0;
}
