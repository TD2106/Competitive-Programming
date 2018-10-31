#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
string Ti;
bool flag=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>Ti;
	for(int i=0;i<Ti.size();i++){
        if(Ti[i]!='a'){
            for(int j=i;j<Ti.size()&&Ti[j]!='a';j++) Ti[j]=Ti[j]-1;
            flag=1;
            break;
        }
	}
	if(flag) cout<<Ti<<endl;
	else Ti[Ti.size()-1]='z',cout<<Ti<<endl;
	return 0;
}
