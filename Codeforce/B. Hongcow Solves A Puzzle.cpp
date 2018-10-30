#include <iostream>
#include <utility>
using namespace std;
char puz[505][505]={0};
int n,m,x=0,first=0;
pair<int,int> u,l;
int main (){
	cin>>n>>m;
	u.first=u.second=500,l.first=l.second=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>puz[i][j];
			if(puz[i][j]=='X'){
				x++;
				u.first=min(u.first,i);
				u.second=min(u.second,j);
				l.first=max(l.first,i);
				l.second=max(l.second,j);
			}
		}
	}
	if(x==0){
		cout<<"NO\n";
		return 0;
	}
	for(int i=u.first;i<=l.first;i++){
		for(int j=u.second;j<=l.second;j++){
			if(puz[i][j]=='.'){
				cout<<"NO\n";
				return 0;
			}
		}
	}
	cout<<"YES\n";
	return 0;
}
