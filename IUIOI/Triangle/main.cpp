#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
vector<int> keyA,keyB,keyC;
int cntA[1005],cntB[1005],cntC[1005],n,Ti,idx,tc,temp,type;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>tc;
	while(tc--){
        keyA.clear();
        keyB.clear();
        keyC.clear();
        reset(cntA);
        reset(cntB);
        reset(cntC);
        Ti=idx=0;
        cin>>n>>type;
        for(int i=1;i<=n;i++){
            cin>>temp;
            keyA.push_back(temp);
        }
        for(int i=1;i<=n;i++){
            cin>>temp;
            keyB.push_back(temp);
        }
        for(int i=1;i<=n;i++){
            cin>>temp;
            keyC.push_back(temp);
        }
        sort(keyA.begin(),keyA.end());
        sort(keyB.begin(),keyB.end());
        sort(keyC.begin(),keyC.end());
        for(int i=0;i<keyA.size();i++){
            idx=lower_bound(keyA.begin(),keyA.end(),keyA[i])-keyA.begin();
            cntA[idx]++;
        }
        for(int i=0;i<keyB.size();i++){
            idx=lower_bound(keyB.begin(),keyB.end(),keyB[i])-keyB.begin();
            cntB[idx]++;
        }
        for(int i=0;i<keyC.size();i++){
            idx=lower_bound(keyC.begin(),keyC.end(),keyC[i])-keyC.begin();
            cntC[idx]++;
        }
        if(type==1){
            for(int i=0;i<n&&)
        }
        else if(type==2){

        }
        else{

        }
	}
	return 0;
}
