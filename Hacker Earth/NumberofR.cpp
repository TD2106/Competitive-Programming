#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int a[1000010];
int main (){
	int tc,ans,total;
	cin>>tc;
	while(tc--){
		total=0;
		memset(a,0,sizeof(a));
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(s[i]=='R'){
				a[i]=-1;
				total++;
			}
			else
			a[i]=1;
		}
		ans=0;
		int n=s.size();
		if(total==n){
			cout<<total-1<<endl;
		}
		else{
			int maxsofar=0;
			for(int i=0;i<n;i++){
				maxsofar+=a[i];
				if(maxsofar<0)
				maxsofar=0;
				ans=max(maxsofar,ans);
			}
			cout<<ans+total<<endl;
		}
	}
	return 0;
}

