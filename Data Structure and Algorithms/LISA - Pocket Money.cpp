#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;

int main(){
    string s;
    stringstream ss;
    vector<ll> number;
    vector<char> expression;
    ll tc,t,n;
    char c;
    cin>>tc;
    while(tc--){
        cin>>s;
        number.clear();
        expression.clear();
        ss<<s;
        ss>>t;
        number.push_back(t);
        while(ss>>c){
            expression.push_back(c);
            ss>>t;
            number.push_back(t);
        }
        n=number.size();
        ll **Ti;
        Ti=(ll**)malloc(n*sizeof(ll*));
        for(int i=0;i<n;i++) Ti[i]=(ll*)malloc(n*sizeof(ll));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) Ti[i][j]=0;
        }
        for(int i=0;i<n;i++) Ti[i][i]=number[i];
        //cout<<123<<endl;
        for(int L=2;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j=L+i-1;
                for(int k=i;k<j&&k<n;k++){
                    if(expression[k]=='+'){
                        Ti[i][j]=max(Ti[i][j],Ti[i][k]+Ti[k+1][j]);
                    }
                    else{
                        Ti[i][j]=max(Ti[i][j],Ti[i][k]*Ti[k+1][j]);
                    }
                }
            }
        }
        cout<<Ti[0][n-1]<<" ";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) Ti[i][j]=1e18;
        }
        for(int i=0;i<n;i++) Ti[i][i]=number[i];
        //cout<<123<<endl;
        for(int L=2;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j=L+i-1;
                for(int k=i;k<=j&&k<n;k++){
                    if(expression[k-1]=='+'){
                        Ti[i][j]=min(Ti[i][j],Ti[i][k]+Ti[k+1][j]);
                    }
                    else{
                        Ti[i][j]=min(Ti[i][j],Ti[i][k]*Ti[k+1][j]);
                    }
                }
            }
        }
        cout<<Ti[0][n-1]<<endl;
    }
	return 0;
}
