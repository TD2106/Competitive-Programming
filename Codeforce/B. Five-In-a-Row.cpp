#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
char table[25][25]={0};
int dr[4]={1,0,1,1},dc[4]={1,1,0,-1};
bool check(int r,int c){
    int t1,t2,sum;
    for(int i=0;i<4;i++){
        t1=r,t2=c,sum=0;
        for(int j=0;j<5;j++){
            if(table[t1][t2]=='X') sum++;
            else if(table[t1][t2]=='O'||table[t1][t2]!='.') sum--;
            t1+=dr[i];
            t2+=dc[i];
        }
        if(sum==4) return 1;
        t1=r,t2=c,sum=0;
        for(int j=0;j<5;j++){
            //if(r==10&&table[r][c]=='O'&&i==3) cout<<sum<<endl;
            if(table[t1][t2]=='X') sum++;
            else if(table[t1][t2]=='O'||table[t1][t2]!='.') sum--;
            t1-=dr[i];
            t2-=dc[i];
        }
        if(sum==4) return 1;
    }
    return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>table[i+5][j+5];
        }
	}
	for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            //cout<<table[i][j];
            if(check(i+5,j+5)){
                cout<<"YES\n";
                return 0;
            }
        }
        //cout<<endl;
	}
	cout<<"NO\n";
	return 0;
}
