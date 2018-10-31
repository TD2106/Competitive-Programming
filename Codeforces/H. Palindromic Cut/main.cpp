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
vector<string> Ti;
int cnt[305]={0},n,odd=0;
string s;
string build(int length){
    string first,second,res;
    for(int i=0;i<=300&&(first.size()<length/2&&second.size()<length/2);i++){
        while((first.size()<length/2&&second.size()<length/2)&&cnt[i]>=2){
            first+=char(i);
            second+=char(i);
            cnt[i]-=2;
        }
    }
    if(length%2){
        bool flag=1;
        up(i,0,300) if(cnt[i]%2){
            first+=char(i);
            cnt[i]--;
            flag=0;
            break;
        }
        if(flag){
            up(i,0,300) if(cnt[i]){
                first+=char(i);
                cnt[i]--;
                break;
            }
        }
    }
    reverse(all(second));
    res=first+second;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
    for(auto c:s) cnt[c]++;
//    up(i,1,300) cout<<i<<' '<<cnt[i]<<endl;
    up(i,0,300) if(cnt[i]%2) odd++;
    if(odd==0||odd==1){
        Ti.pb(build(n));
    }
    else{
        if(n%odd==0&&(n/odd)%2==1){
            up(i,1,odd) Ti.pb(build(n/odd));
        }
        else{
            int temp;
            up(i,odd,n){
                if(n%i==0&&(n/i)%2==1){
                    temp=i;
                    break;
                }
            }
            up(i,1,temp) Ti.pb(build(n/temp));
        }
    }
    cout<<Ti.size()<<endl;
    for(auto str:Ti) cout<<str<<' ';
    return 0;
}
