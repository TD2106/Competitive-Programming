#include <iostream>
#include <utility>
#include <set>
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
pii point(pii a, pii b, pii c){
	return make_pair(a.F+(b.F-c.F),a.S+(b.S-c.S));
}
int main (){
	pii a,b,c;
	set<pii> four;
	cin>>a.F>>a.S>>b.F>>b.S>>c.F>>c.S;
	four.insert(point(a,b,c));
	four.insert(point(a,c,b));
	four.insert(point(b,a,c));
	four.insert(point(b,c,a));
	four.insert(point(c,a,b));
	four.insert(point(c,b,a));
	cout<<four.size()<<endl;
	for(set<pii>::iterator itr=four.begin();itr!=four.end();itr++){
		cout<<itr->first<<" "<<itr->second<<endl;
	}
	return 0;
}

