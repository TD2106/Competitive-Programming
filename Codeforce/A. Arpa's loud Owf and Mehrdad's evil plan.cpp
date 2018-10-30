#include <iostream>
#include <vector>
using namespace std;
int n,cnt,rela[105]={0},ans=1;
bool visited[105]={0};
int gcd(int a,int b){
	if(a*b==0) return a+b;
	else return gcd(b,a%b);
}
int lcm(int a,int b){
	return a*b/gcd(a,b);
}
void cycle(int start,int end){
	if(end==start){
		cnt++;
		return;
	}
	else{
		if(visited[end]){
			cnt=-1;
			return;
		}
		else{
			visited[end]=1;
			cnt++;
			cycle(start,rela[end]);
		}
	}
}
int main (){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>rela[i];
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			visited[i]=1;
			cnt=0;
			cycle(i,rela[i]);
			if(cnt==-1){
				cout<<-1<<endl;
				return 0;
			}
			else if(cnt%2) ans=lcm(ans,cnt);
			else ans=lcm(ans,cnt/2);
		}
	}
	cout<<ans<<endl;
}

