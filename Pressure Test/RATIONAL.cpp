#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
vector<int> path;
ll p,q,Ti=1;
char c;
int main(){
	//ios_base::sync_with_stdio(0);
	freopen("RATIONAL.INP","r",stdin);
	freopen("RATIONAL.OUT","w",stdout);
	cin>>p>>c>>q;
	while(p!=1||q!=1){
        //cout<<p<<" "<<q<<endl;
        if(p>q){
            path.push_back(2);
            p=p-q;
        }
        else{
            path.push_back(1);
            q=q-p;
        }
	}
	reverse(path.begin(),path.end());
	for(int i=0;i<path.size();i++){
        if(path[i]==1) Ti=2*Ti;
        else Ti=2*Ti+1;
	}
	cout<<Ti<<endl;
	return 0;
}
