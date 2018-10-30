#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
string s;
int Ti=0;
double sum=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>s;
	if(s=="1") cout<<1<<endl;
	else if(s=="2") cout<<2<<endl;
	else if(s=="6") cout<<3<<endl;
	else if(s=="24") cout<<4<<endl;
	else if(s=="120") cout<<5<<endl;
	else if(s=="720") cout<<7<<endl;
	else if(s=="5760") cout<<8<<endl;
	else if(s=="51840") cout<<9<<endl;
	else{
        while((int)sum+1<s.size()){
            ++Ti;
            sum+=log(Ti*1.0)/log(10.0);
        }
        cout<<Ti<<endl;
	}
	return 0;
}
