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
typedef pair<pii,int> piii;
ll Ti[105]={0};
piii queries[105];
int tc;
void compute(){
    stringstream ss,sss;
    string s1,s2;
    int temp,start=1;
    char c;
    up(i,1,100){
        ss.clear();
        ss<<i;
        ss>>s1;
        s2=s1;
        c=s2[s1.size()-1];
        s2.pop_back();
        s2=c+s2;
        while(s1!=s2){
            if(s1<s2){
                sss.clear();
                sss<<s2;
                sss>>temp;
                up(j,start,tc){
                    if(queries[j].fi.se>=temp&&queries[j].fi.fi<=i) Ti[queries[j].se]++;
                }
            }
            c=s2[s1.size()-1];
            s2.pop_back();
            s2=c+s2;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>tc;
    up(i,1,tc){
        cin>>queries[i].fi.fi>>queries[i].fi.se;
        queries[i].se=i;
    }
    sort(queries+1,queries+1+tc);
    compute();
    up(i,1,tc) cout<<Ti[i]<<endl;
    return 0;
}
