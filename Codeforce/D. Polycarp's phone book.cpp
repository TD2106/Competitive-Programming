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
int n;
string s[70005],Ti;
unordered_map<string,int> seg,subseg[70005];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	up(i,1,n){
        cin>>s[i];
        up(j,0,8){
            up(k,j,8){
                seg[s[i].substr(j,k-j+1)]++;
                subseg[i][s[i].substr(j,k-j+1)]++;
            }
        }
	}
	up(i,1,n){
	    bool done=0;
        up(j,1,9){
            up(k,0,8-j+1){
                Ti=s[i].substr(k,j);
                int t=seg[Ti]-subseg[i][Ti];
                if(t==0){
                    cout<<Ti<<endl;
                    done=1;
                    break;
                }
            }
            if(done) break;
        }
	}
	return 0;
}
