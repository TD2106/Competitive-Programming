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
map< string,set<string> > personPhone;
vector<string> phoneNumber;
int n,num;
string s,p;
bool isBad[250];
bool isSuffix(const string &a, const string &b){
    if(b.size()<=a.size()) return 0;
    if(b.substr(b.size()-a.size(),a.size())==a) return 1;
    else return 0;
}
void process(){
    reset(isBad);
    vector<string> temp;
    up(i,0,phoneNumber.size()-1){
        up(j,0,phoneNumber.size()-1){
            if(i==j) continue;
            if(isSuffix(phoneNumber[i],phoneNumber[j])){
                isBad[i]=1;
                break;
            }
        }
    }
    up(i,0,phoneNumber.size()-1){
        if(!isBad[i]) temp.pb(phoneNumber[i]);
    }
    phoneNumber = temp;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>s>>num;
        up(j,1,num){
            cin>>p;
            personPhone[s].insert(p);
        }
    }
    cout<<personPhone.size()<<endl;
    for(auto itr:personPhone){
        phoneNumber.clear();
        cout<<itr.fi<<' ';
        for(string temp:itr.se){
            phoneNumber.pb(temp);
        }
        process();
        cout<<phoneNumber.size()<<' ';
        for(string temp:phoneNumber){
            cout<<temp<<' ';
        }
        cout<<endl;
    }
    return 0;
}
