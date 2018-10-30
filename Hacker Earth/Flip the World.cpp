#include <iostream>
#include <cstring>
using namespace std;
bool table[25][25];
int tc,n,m,ti;
int main (){
	cin>>tc;
	string s;
	while(tc--){
		ti=0;
		cin>>n>>m;
		memset(table,0,sizeof(table));
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=1;j<=m;j++) table[i][j]=s[j-1]-'0';
		}
		for(int i=n;i>0;i--){
			for(int j=m;j>0;j--){
				if(table[i][j]==0){
					ti++;
					for(int x=1;x<=i;x++){
						for(int y=1;y<=j;y++){
							if(table[x][y]) table[x][y]=0;
							else table[x][y]=1;
						}
					}
				}
			}
		}
		cout<<ti<<endl;
	}
}
