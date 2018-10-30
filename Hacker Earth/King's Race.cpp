#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
int main (){
	//freopen("King's Race.txt","r",stdin);
	ll tc,n,k,temp;
	scanf("%lld",&tc);
	while(tc--){
		scanf("%lld%lld",&n,&k);
		vector< pair<ll,ll> > prince;
		vector<ll> level;
		for(int i=0;i<n;i++){
			scanf("%lld",&temp);
			prince.push_back(make_pair(temp,i));
		}		
		for(int i=0;i<k;i++){
			scanf("%lld",&temp);
			level.push_back(temp);
		}
		sort(prince.begin(),prince.end());
		sort(level.begin(),level.end());
		int i,j;
		for(i=k-1;i>=0;i--){
			if(level[i]<prince[n-1].first)
			break;
		}
		if(i==-1){
			printf("0\n");
		}
		else{
			ll ans=2000000000;
			for(j=n-1;j>=0;j--){
				if(prince[j].first>=level[i])
				ans=min(prince[j].second,ans);
				else break;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
