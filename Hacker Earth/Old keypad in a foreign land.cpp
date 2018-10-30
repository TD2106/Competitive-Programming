#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main (){
	int n,keySize,ans=0,totalKey=0,fre[50]={0},key[50]={0},status[50]={0};
	cin>>n;
	for(int i=0;i<n;i++) cin>>fre[i];
	sort(fre,fre+n,cmp);
	cin>>keySize;
	for(int i=0;i<keySize;i++){
		cin>>key[i];
		status[i]=1;
		totalKey+=key[i];
	}
	sort(key,key+keySize,cmp);
	if(totalKey<n) cout<<"-1";
	else{
		int index=0;
		for(int i=0;i<n;i++){
			if(key[index]==0)
			index=0;
			ans+=status[index]*fre[i];
			status[index]++;
			key[index]--;
			index++;
		}
		cout<<ans;
	}
}
