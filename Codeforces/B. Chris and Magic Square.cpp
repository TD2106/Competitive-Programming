#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,a[505][505]={0},sum,Ti,flag,temp=0;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        sum=0;
        flag=1;
        for(int j=1;j<=n;j++){
            if(a[i][j]==0) flag=0;
            sum+=a[i][j];
        }
        if(flag) break;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==0){
                for(int k=1;k<=n;k++) temp+=a[i][k];
                Ti=sum-temp;
                a[i][j]=Ti;
            }
        }
    }
    if(Ti<=0) cout<<-1<<endl;
    else{
        temp=0;
        for(int i=1;i<=n;i++) temp+=a[i][i];
        if(temp!=sum){
            cout<<-1<<endl;
            return 0;
        }
        temp=0;
        for(int i=1;i<=n;i++) temp+=a[i][n-i+1];
        if(temp!=sum){
            cout<<-1<<endl;
            return 0;
        }
        for(int i=1;i<=n;i++){
            temp=0;
            for(int j=1;j<=n;j++) temp+=a[i][j];
            if(temp!=sum){
                cout<<-1<<endl;
                return 0;
            }
        }
        for(int i=1;i<=n;i++){
            temp=0;
            for(int j=1;j<=n;j++) temp+=a[j][i];
            if(temp!=sum){
                cout<<-1<<endl;
                return 0;
            }
        }
        cout<<Ti<<endl;
    }
	return 0;
}
