#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,c,Ti=0,prevT,nowT;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>c;
	for(int i=1;i<=n;i++){
        cin>>nowT;
        if(i==1){
            Ti++;
            prevT=nowT;
        }
        else{
            if(nowT-prevT<=c) Ti++;
            else Ti=1;
            prevT=nowT;
        }
	}
	cout<<Ti<<endl;
	return 0;
}
