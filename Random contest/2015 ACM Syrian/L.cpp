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
int dp[100005]={0};
bool isPrime[35]={0};
int main()
{
    memset(isPrime,1,sizeof(isPrime));
    isPrime[0]=isPrime[1]=0;
    up(i,2,30){
        if(isPrime[i]){
            for (int j=i*i; j<=30;j+=i) {
                isPrime[j]=0;
            }
        }
    }
    up(i,1,100000){
        int cnt=0;
        up(j,0,20){
            if((i>>j)&1) cnt++;
        }
        if(isPrime[cnt]) dp[i]=dp[i-1]+1;
        else dp[i]=dp[i-1];
    }
    ios_base::sync_with_stdio(0);
    tc(){
        int l,r;
        cin>>l>>r;
        cout<<dp[r]-dp[l-1]<<endl;
    }
}
