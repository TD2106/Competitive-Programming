#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main (){
	int hpy,atky,dfy,hpm,atkm,dfm,h,a,d,ans,t1,t2,da1,da2,sa=0,i,j,k;
	cin>>hpy>>atky>>dfy>>hpm>>atkm>>dfm>>h>>a>>d;
	da1=max(0,atky-dfm);
	da2=max(0,atkm-dfy);
	if(da2==0&&da1>0){
		//cout<<123<<endl;
		cout<<0<<endl;
		return 0;
	}
	if(da2==0&&da1==0){
		cout<<a*(dfm+1-atky)<<endl;
		return 0;
	}
	if(da2>0&&da1==0) sa=a*(dfm+1-atky),atky=dfm+1,da1=1;
	t1=ceil(hpm*1.0/da1),t2=ceil(hpy*1.0/da2);
	if(t1<t2) cout<<0<<endl;
	else{
		//cout<<t2<<" "<<t1<<endl;
		ans=d*(atkm-dfy);
		for(i=atky;i<=200;i++){
			for(k=dfy;k<atkm;k++){
				//cout<<j<<endl;
				//cout<<l<<" "<<u<<" "<<j<<endl;
				t1=(int)ceil(hpm*1.0/(i-dfm)),t2=(int)ceil(hpy*1.0/(atkm-k));
				if(t1<t2) ans=min(ans,a*(i-atky)+d*(k-dfy));
				else{
					j=(t1)*(atkm-k)+1;
					//cout<<j<<endl;
					ans=min(ans,a*(i-atky)+h*(j-hpy)+d*(k-dfy));
				}
			}
		}
		cout<<ans+sa<<endl;
	}
	return 0;
}
