#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,m;
char flag[105][105]={0};
int color(char c){
    if(c=='R') return 0;
    else if(c=='G') return 1;
    else return 2;
}
bool checkVertical(){
    int l=m/3,used[3]={0},cur;
    for(int st=1;st<=m;st+=l){
        if(used[color(flag[1][st])]) return 0;
        else used[color(flag[1][st])]=1;
        cur = color(flag[1][st]);
        for(int i=st;i<=st+l-1;i++){
            for(int j=1;j<=n;j++){
                if(color(flag[j][i])!=cur) return 0;
            }
        }
    }
    return 1;
}
bool checkHorizontal(){
    int l=n/3,used[3]={0},cur;
    for(int st=1;st<=n;st+=l){
        if(used[color(flag[st][1])]) return 0;
        else used[color(flag[st][1])]=1;
        cur = color(flag[st][1]);
        for(int i=st;i<=st+l-1;i++){
            for(int j=1;j<=m;j++){
                if(color(flag[i][j])!=cur) return 0;
            }
        }
    }
    return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	if(n%3!=0&&m%3!=0){
        cout<<"NO\n";
        return 0;
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>flag[i][j];
        }
	}
	if(n%3==0&&m%3!=0){
        if(checkHorizontal()){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
	}
	else if(n%3!=0&&m%3==0){
        if(checkVertical()){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
	}
	else{
        if(checkHorizontal()||checkVertical()){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
	}
	return 0;
}
