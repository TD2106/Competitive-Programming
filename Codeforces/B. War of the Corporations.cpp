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
int b[100005]={0},Ti=0,cur=-1e5,n,m;
string txt,pat;
vector<int> pos;
void kmpPreprocess() {
    int i=0,j=-1;
    b[0]=-1;
    while(i<m){
        while(j>=0&&pat[i]!=pat[j]) j=b[j];
        i++,j++;
        b[i]=j;
    }
}
void kmpSearch(){
    int i=0,j=0;
    while(i<n){
        while(j>=0&&txt[i]!=pat[j]) j=b[j];
        i++,j++;
        if(j==m){
            Ti++;
            j=0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>txt>>pat;
    n=txt.size();
    m=pat.size();
    kmpPreprocess();
    kmpSearch();
    cout<<Ti<<endl;
    return 0;
}
