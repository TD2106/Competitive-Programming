#include <iostream>
#include <vector>
using namespace std;
int n,q,type,noti[300010]={0},index[300010]={0},marking[300010]={0},num,t=0,cur=1,ans=0;
int main (){
	ios::sync_with_stdio(false);
	cin>>n>>q;
	while(q--){
		cin>>type>>num;
		if(type==1){
			noti[num]++;
			index[++t]=num;
			ans++;
		}
		else if(type==2){
			ans-=noti[num];
			noti[num]=0;
			marking[num]=t;
		}
		else{
			for(cur;cur<=num;cur++){
				if(noti[index[cur]]&&cur>marking[index[cur]]){
					noti[index[cur]]--;
					ans--;
				}
			}
		}
		cout<<ans<<endl;
	}
	//cout<<ans<<endl;
}
