#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,flag=0;
string Ti[1000];
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>Ti[i];
    for(int i=0;i<n;i++){
        if(Ti[i][0]=='O'&&Ti[i][1]=='O'&&flag==0) Ti[i][0]=Ti[i][1]='+',flag=1;
        else if(Ti[i][3]=='O'&&Ti[i][4]=='O'&&flag==0) Ti[i][3]=Ti[i][4]='+',flag=1;
    }
    if(!flag) cout<<"NO\n";
    else{
        cout<<"YES\n";
        for(int i=0;i<n;i++) cout<<Ti[i]<<endl;
    }
	return 0;
}
