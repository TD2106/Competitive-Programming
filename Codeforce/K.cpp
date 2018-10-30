#include <iostream>
using namespace std;
int main (){
	long long tc,l1,l2,a1,a2,lt,at,x,y,d,dx,dy;
	cin>>tc;
	while(tc--){
		cin>>l1>>a1>>l2>>a2>>lt>>at;
		d=(l1*a2-a1*l2);
		dx=(-l2*at+a2*lt);
		dy=(l1*at-a1*lt);
		if(d==0){
			cout<<"?\n";
		}
		else{
			x=dx/d;
			y=dy/d;
			if(x>=1&&y>=1&&dx%d==0&&dy%d==0){
				cout<<x<<" "<<y<<endl;
			}
			else cout<<"?\n";
		}
	}
	return 0;
}
