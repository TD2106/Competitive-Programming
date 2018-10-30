#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
string n,Ti;
int main(){
    cin>>n>>Ti;
    if(n=="12"){
        if(Ti[0]>n[0]||(n[0]==Ti[0]&&Ti[1]>n[1])) Ti[0]='0';
        if(Ti[3]>'6'||Ti[3]=='6'&&Ti[4]>='0') Ti[3]='0';
        if(Ti[0]=='0'&&Ti[1]=='0') Ti[0]='1';
    }
    else{
        if(Ti[0]>n[0]||(n[0]==Ti[0]&&Ti[1]>=n[1])) Ti[0]='0';
        if(Ti[3]>'6'||Ti[3]=='6'&&Ti[4]>='0') Ti[3]='0';
    }
    cout<<Ti<<endl;
	return 0;
}
