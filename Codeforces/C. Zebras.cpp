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
string s;
vector<vi> Ti;
int temp;
set<int> ones,zeros;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    up(i,1,s.size()){
        temp = s[i-1]-'0';
        if(temp==1&&zeros.size()==0){
            cout<<-1<<endl;
            return 0;
        }
        else{
            if(temp==0&&ones.size()==0){
                vi t;
                t.pb(i);
                Ti.pb(t);
                zeros.insert(Ti.size()-1);
            }
            else if(temp==0&&ones.size()!=0){
                temp=*ones.begin();
                ones.erase(temp);
                Ti[temp].pb(i);
                zeros.insert(temp);
            }
            else if(temp==1){
                temp=*zeros.begin();
                zeros.erase(temp);
                Ti[temp].pb(i);
                ones.insert(temp);
            }

        }
    }
    if(ones.size()){
        cout<<-1<<endl;
        return 0;
    }
    cout<<Ti.size()<<endl;
    for(vi t:Ti){
        cout<<t.size()<<' ';
        for(int i:t) cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}
