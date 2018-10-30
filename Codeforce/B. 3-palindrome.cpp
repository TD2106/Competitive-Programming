#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
string Ti;
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        if(i==0||i==1) Ti+='a';
        else{
            if(Ti[i-2]=='a') Ti+='b';
            else Ti+='a';
        }
    }
    cout<<Ti<<endl;
	return 0;
}
