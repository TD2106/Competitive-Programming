#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,m,x1=0,x2=0,y_1=0,y2=0,Ti=0,l;
char table[105][105]={0};
void runTable(int xmn,int xmx,int ymn,int ymx){
    for(int i=xmn;i<=xmx;i++){
        for(int j=ymn;j<=ymx;j++){
            if(table[i][j]!='B') Ti++;
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>table[i][j];
            if(table[i][j]=='B'){
                if(x1==0){
                    x1=x2=i;
                    y_1=y2=j;
                }
                else{
                    x1=min(x1,i);
                    x2=max(x2,i);
                    y_1=min(y_1,j);
                    y2=max(y2,j);
                }
            }
        }
	}
	if(x1==0) cout<<1<<endl;
	else{
        if(x2-x1==y2-y_1){
            runTable(x1,x2,y_1,y2);
            cout<<Ti<<endl;
            return 0;
        }
        else if(x2-x1>y2-y_1){
            l=x2-x1+1;
            if(y_1+l-1<=m) runTable(x1,x2,y_1,y_1+l-1);
            else if(y2-l+1>=1) runTable(x1,x2,y2-l+1,y2);
            else{
                for(int i=1;i<=m-l+1;i++){
                    if(i<=y_1&&i+l-1>=y2){
                        runTable(x1,x2,i,i+l-1);
                        break;
                    }
                }
            }
        }
        else{
            l=y2-y_1+1;
            if(x1+l-1<=n) runTable(x1,x1+l-1,y_1,y2);
            else if(x2-l+1>=1) runTable(x2-l+1,x2,y_1,y2);
            else{
                for(int i=1;i<=n-l+1;i++){
                    if(i<=x1&&i+l-1>=x2){
                        runTable(i,i+l-1,y_1,y2);
                        break;
                    }
                }
            }
        }
        if(Ti==0) Ti=-1;
        cout<<Ti<<endl;
	}
	return 0;
}
