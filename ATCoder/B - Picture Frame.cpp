#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    char frame[205][205]={0};
    int h,w;
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++) cin>>frame[i][j];
    }
    for(int i=0;i<=w+1;i++) frame[0][i]=frame[h+1][i]='#';
    for(int i=1;i<=h;i++) frame[i][0]=frame[i][w+1]='#';
    for(int i=0;i<=h+1;i++){
        for(int j=0;j<=w+1;j++) cout<<frame[i][j];
        cout<<endl;
    }
	return 0;
}
