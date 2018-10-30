#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <cmath>
#include <vector>
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,char> piece;
pll king,t;
vector<piece> pos;
bool cmp(piece a,piece b){
	ll t1,t2;
	t1=(a.F.F-king.F)*(a.F.F-king.F)+(a.F.S-king.S)*(a.F.S-king.S);
	t2=(b.F.F-king.F)*(b.F.F-king.F)+(b.F.S-king.S)*(b.F.S-king.S);
	//cout<<t1<<" "<<t2<<endl;
	return (t1<t2);
}
bool check(pll t){
	return (abs(t.F-king.F)==abs(t.S-king.S));
}
ll checkB(pll t){
	if(check(t)){
		if(t.F>king.F&&t.S>king.S) return 1;
		else if(t.F>king.F&&t.S<king.S) return 2;
		else if(t.F<king.F&&t.S<king.S) return 3;
		else if(t.F<king.F&&t.S>king.S) return 4;
	}
	else return 0;
}
int main (){
	ios::sync_with_stdio(false);
	ll n,d;
	piece temp;
	set<ll> markingB,markingRx,markingRy;
	cin>>n>>king.F>>king.S;
	for(int i=0;i<n;i++){
		cin>>temp.S>>temp.F.F>>temp.F.S;
		pos.push_back(temp);
	}
	sort(all(pos),cmp);
	//cal(pos[0],pos[1]);
	//for(int i=0;i<n;i++){
	//	cout<<pos[i].S<<" "<<pos[i].F.F<<" "<<pos[i].F.S<<endl;
	//}
	for(int i=0;i<n;i++){
		t=pos[i].F;
		//cout<<i<<" "<<pos[i].S<<endl;
		if(pos[i].S=='B'){
			//cout<<i<<endl;
			//cout<<checkB(t)<<endl;
			if(check(pos[i].F)&&!markingB.count(checkB(t))){
				//cout<<pos[i].F.F<<" "<<pos[i].F.S<<endl;
				cout<<"YES\n";
				return 0;
			}
			//cout<<pos[i].F.F<<" "<<pos[i].F.S<<endl;
			markingB.insert(checkB(t));
			markingRx.insert(pos[i].F.F);
			markingRy.insert(pos[i].F.S);
		}
		else if(pos[i].S=='R'){
			if(!markingRx.count(pos[i].F.F)){
				if(pos[i].F.F==king.F){
					cout<<"YES\n";
					return 0;
				}
				markingRx.insert(pos[i].F.F);
			}
			if(!markingRy.count(pos[i].F.S)){
				if(pos[i].F.S==king.S){
					cout<<"YES\n";
					return 0;
				}
				markingRy.insert(pos[i].F.S);
			}
			markingB.insert(checkB(t));
		}
		else{
			if(check(pos[i].F)&&markingB.count(checkB(t))==0){
				//cout<<pos[i].F.F<<" "<<pos[i].F.S<<endl;
				cout<<"YES\n";
				return 0;
			}
			if(!markingRx.count(pos[i].F.F)){
				if(pos[i].F.F==king.F){
					cout<<"YES\n";
					return 0;
				}
				markingRx.insert(pos[i].F.F);
			}
			if(!markingRy.count(pos[i].F.S)){
				if(pos[i].F.S==king.S){
					cout<<"YES\n";
					//cout<<i<<endl;
					return 0;
				}
				markingRy.insert(pos[i].F.S);
			}
			markingB.insert(checkB(t));
		}
	}
	cout<<"NO\n";
	return 0;
}
