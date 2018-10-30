#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int tc;
    double delta,a,b,c,k,x;
    cin>>tc;
    while(tc--){
    	cin>>a>>b>>c>>k;
    	delta=b*b-4*a*(c-k);
    	if(delta<=0) cout<<0<<endl;
		else{
			x=(-b-sqrt(delta))/(2*a);
			if(x>=0)
			cout<<0<<endl;
			else{
				x=(-b+sqrt(delta))/(2*a);
				if(x<0) cout<<0<<endl;
				else cout<<ceil(x)<<endl;
			}
		}
    }
}
