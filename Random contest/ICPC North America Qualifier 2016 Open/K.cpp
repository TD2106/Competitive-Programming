#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int Tix,Tiy,tc,l1,l2,lt,a1,a2,a_t,tempx,tempy;
bool flag,no;
int main(){
	ios_base::sync_with_stdio(0);
//    fr("10_robotopia_secret.in");
	cin>>tc;
	while(tc--){
        cin>>l1>>a1>>l2>>a2>>lt>>a_t;
        flag=0;
        no=0;
        for(int i=1;l1*i<=lt;i++){
            tempx=i;
            tempy=(lt-l1*tempx)/l2;
            if((l1*tempx+l2*tempy==lt)&&(a1*tempx+a2*tempy==a_t)&&tempx>0&&tempy>0){
                if(flag){
                    no=1;
                    break;
                }
                else{
                    flag=1;
                    Tix=tempx;
                    Tiy=tempy;
                }
            }
        }
        if(!no&&flag) cout<<Tix<<" "<<Tiy<<endl;
        else cout<<"?\n";
	}
	return 0;
}
