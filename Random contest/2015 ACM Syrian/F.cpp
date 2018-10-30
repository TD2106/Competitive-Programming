#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
#define fr(a) freopen(a,"r",stdin);
#define fw(a) freopen(a,"w",stdout);
#define tc() int tc;cin >> tc; for(int _tc=1;_tc<=tc;_tc++)
#define up(i,l,r) for (int i=l;i<=r;i++)
#define down(i,r,l) for (int i=r;i>=l;i--)
#define rep(i,l,r) for (int i=l;i<r;i++)
#define pb push_back
#define mp make_pair
#define ins insert
#define fi first
#define se second
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

/****************************************************/
void printArr(int a[], int l, int r)
{ up(i,l,r) cout << a[i] << " \n"[i==r]; }

void printMtx(int a[][1010],int n, int m)
{ up(i,1,n) up(j,1,m) cout << a[i][j] << " \n"[j==m]; }
/****************************************************/
string s;
bool level[15];
bool check(){
    int cnt=0;
    up(i,1,5){
        if(level[i]) cnt++;
    }
    return (cnt==5);
}
int main()
{
    ios_base::sync_with_stdio(0);
    tc(){
        bool ok=0;
        cin>>s;
        reset(level);
        up(i,0,6){
            int t=s[i]-'A'+1;
            level[t]=1;
        }
        if(check()){
            cout<<"YES\n";
            continue;
        }
        reset(level);
        up(i,0,6){
            up(j,0,6){
                if(i==j) continue;
                reset(level);
                int t=(s[i]-'A'+1)+(s[j]-'A'+1);
                level[t]=1;
                up(k,0,6){
                    if(k!=i&&k!=j){
                        level[s[k]-'A'+1]=1;
                    }
                }
                if(check()){
                    ok=1;
                }
            }
        }
        if(ok){
            cout<<"YES\n";
            continue;
        }
        up(i,0,6){
            up(j,0,6){
                up(k,0,6){
                    up(l,0,6){
                        if(i==j||i==k||i==l||j==k||j==l||k==l) continue;
                        reset(level);
                        int t1=(s[i]-'A'+1)+(s[j]-'A'+1),t2=(s[k]-'A'+1)+(s[l]-'A'+1);
                        level[t1]=1;
                        level[t2]=1;
                        up(m,0,6){
                            if(m!=i&&m!=j&&m!=k&&m!=l){
                                level[s[m]-'A'+1]=1;
                            }
                        }
                        if(check()){
                            ok=1;
                        }
                    }
                }
            }
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
