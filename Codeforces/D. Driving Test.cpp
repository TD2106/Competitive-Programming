#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,type,s,overtake=0,speedLimit[200005],curSpeed,Ti=0,idx=1;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	speedLimit[1]=400;
	for(int i=1;i<=n;i++){
        cin>>type;
        if(type==1){
           cin>>s;
           curSpeed=s;
           while(speedLimit[idx]<curSpeed){
                Ti++;
                idx--;
           }
        }
        else if(type==2){
            Ti+=overtake;
            overtake=0;
        }
        else if(type==3){
            cin>>s;
            speedLimit[++idx]=s;
            while(speedLimit[idx]<curSpeed){
                Ti++;
                idx--;
           }
        }
        else if(type==4){
            overtake=0;
        }
        else if(type==5){
            speedLimit[++idx]=400;
        }
        else{
            overtake++;
        }
	}
	cout<<Ti<<endl;
	return 0;
}
