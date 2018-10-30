#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    int n,p[100],Ti[100]={0};
    string s[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];
    cin.ignore();
    for(int i=0;i<n;i++) getline(cin,s[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].size();j++){
            if(s[i][j]=='a'||s[i][j]=='e'||s[i][j]=='i'||s[i][j]=='u'||s[i][j]=='o'||s[i][j]=='y') Ti[i]++;
        }
       // cout<<Ti[i]<<endl;
    }
    for(int i=0;i<n;i++){
        if(Ti[i]!=p[i]){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
	return 0;
}
