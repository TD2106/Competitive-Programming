#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
int n,cnt1=0,cnt0=0,dp[105]={0},Ti=0,temp;
vector<pii> data;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	data.push_back({0,0});
	for(int i=1;i<=n;i++){
        cin>>temp;
        if(temp==1&&cnt0!=0){
            data.push_back({0,cnt0});
            cnt0=0;
            cnt1++;
        }
        else if(temp==1) cnt1++;
        else if(temp==0&&cnt1!=0){
            data.push_back({1,cnt1});
            cnt1=0;
            cnt0++;
        }
        else cnt0++;
	}
	if(cnt1) data.push_back({1,cnt1});
	else data.push_back({0,cnt0});
	for(int i=1;i<data.size();i++){
        if(data[i].first==0&&data[i-1].first==1){
            dp[i]=dp[i-2]+data[i].second;
        }
        else if(data[i].first==0){
            dp[i]=data[i].second;
        }
        else if(data[i].first==1){
            dp[i]=max(dp[i-1]+data[i].second,dp[max(0,i-2)]+data[i].second);
        }
        Ti=max(Ti,dp[i]);
	}
	cout<<Ti<<endl;
	return 0;
}
