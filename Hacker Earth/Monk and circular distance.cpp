#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main (){
	int n,q;
	double x,y,r;
	vector<double> dis;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		dis.push_back(sqrt(x*x+y*y));
	}
	sort(dis.begin(),dis.end());
	cin>>q;
	vector<double>::iterator itr;
	while(q--){
		cin>>r;
		itr=upper_bound(dis.begin(),dis.end(),r);
		cout<<itr-dis.begin()<<endl;
	}
	return 0;
}
