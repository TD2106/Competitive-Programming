#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <cmath>
#include <vector>
#define M 1000000001
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,char> piece;
piece pos[8];
pll king;
bool cmp(piece a,piece b){
	ll t1,t2;
	t1=(a.F.F-king.F)*(a.F.F-king.F)+(a.F.S-king.S)*(a.F.S-king.S);
	t2=(b.F.F-king.F)*(b.F.F-king.F)+(b.F.S-king.S)*(b.F.S-king.S);
	return (t1<t2);
}
ll checkB(piece t){
	if(t.F.F>king.F&&t.F.S>king.S) return 0;
	else if(t.F.F>king.F&&t.F.S<king.S) return 1;
	else if(t.F.F<king.F&&t.F.S<king.S) return 2;
	else if(t.F.F<king.F&&t.F.S>king.S) return 3;
}
ll checkR(piece t){
	if(t.F.F==king.F&&t.F.S>king.S) return 4;
	else if(t.F.F==king.F&&t.F.S<king.S) return 5;
	else if(t.F.F>king.F&&t.F.S==king.S) return 6;
	else if(t.F.F<king.F&&t.F.S==king.S) return 7;
}
int main (){
	ios::sync_with_stdio(false);
	ll n;
	piece t;
	cin>>n>>king.F>>king.S;
	pos[0].F.F=pos[0].F.S=M;
	pos[1].F.F=M,pos[1].F.S=-M;
	pos[2].F.F=-M,pos[2].F.S=-M;
	pos[3].F.F=-M,pos[3].F.S=M;
	pos[4].F.F=king.F,pos[4].F.S=M;
	pos[5].F.F=king.F,pos[5].F.S=-M;
	pos[6].F.F=M,pos[6].F.S=king.S;
	pos[7].F.F=-M,pos[7].F.S=king.S;
	while(n--){
		cin>>t.S>>t.F.F>>t.F.S;
		if(abs(t.F.F-king.F)==abs(t.F.S-king.S)){
			//cout<<n<<" "<<1<<endl;
			//cout<<cmp(t,pos[checkB(t)])<<" "<<checkB(t)<<endl;
			if(cmp(t,pos[checkB(t)])) pos[checkB(t)]=t;
		}
		if(t.F.F==king.F||t.F.S==king.S){
			//cout<<n<<" "<<2<<endl;
			//cout<<cmp(t,pos[checkR(t)])<<" "<<checkR(t)<<endl;
			if(cmp(t,pos[checkR(t)])) pos[checkR(t)]=t;
		}
	}
	for(int i=0;i<8;i++){
		if(pos[i].F.F==M||pos[i].F.S==M) continue;
		if(i<4&&(pos[i].S=='Q'||pos[i].S=='B')){
			cout<<"YES\n";
			return 0;
		}
		if(i>=4&&(pos[i].S=='Q'||pos[i].S=='R')){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}
