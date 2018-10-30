#include <iostream>
#include <vector>
using namespace std;
struct obj{
	int what;
	int pos;
};
void solve(vector<obj> a,vector<obj> b){
	if(a.size()!=b.size()){
		cout<<"No\n";
		return ;
	}
	else {
		for(int i=0;i<a.size();i++){
			if(a[i].what==b[i].what){
				if(a[i].what==0){
					if(a[i].pos<b[i].pos){
						cout<<"No\n";
						return ;
					}
				}
				else{
					if(a[i].pos>b[i].pos){
						cout<<"No\n";
						return ;
					}
				}
			}
			else{
				cout<<"No\n";
				return ;
			}
		}
		cout<<"Yes\n";
		return ;
	}
}
int main (){
	int tc;
	obj temp;
	string s1,s2;
	cin>>tc;
	while(tc--){
		cin>>s1>>s2;
		vector<obj> a,b;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!='#'){
				temp.what=s1[i]-'A';
				temp.pos=i;
				a.push_back(temp);
			}
		}
		for(int i=0;i<s2.size();i++){
			if(s2[i]!='#'){
				temp.what=s2[i]-'A';
				temp.pos=i;
				b.push_back(temp);
			}
		}
		solve(a,b);
	}
	return 0;
}
