#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,a[200005],b[200005],c[200005],Ti=0,mxPlease=0,mxSastisfied=0,m,temp;
map<int,int> cntPeople;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        cntPeople[a[i]]++;
	}
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	for(int i=1;i<=m;i++){
        temp = cntPeople[b[i]];
        if(temp>mxPlease){
            mxPlease=temp;
            mxSastisfied=cntPeople[c[i]];
            Ti=i;
        }
        else if(temp==mxPlease){
            if(cntPeople[c[i]]>mxSastisfied){
                Ti=i;
                mxSastisfied=cntPeople[c[i]];
            }
        }
	}
	if(Ti==0) Ti=1;
    cout<<Ti<<endl;
	return 0;
}
