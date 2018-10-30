#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int x1,x2,y_1,y2,x,y,t1,t2;
int main(){
    cin>>x1>>y_1>>x2>>y2>>x>>y;
    t1=abs((x2-x1)/x);
    t2=abs((y2-y_1)/y);
    if((x2-x1)%x==0&&(y2-y_1)%y==0&&t1%2==t2%2) cout<<"YES";
    else cout<<"NO";
	return 0;
}
