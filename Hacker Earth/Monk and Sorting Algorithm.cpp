#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct obj{
	int value,rem,chunk,index;
};
void findchunk(obj &a){
	int sum=0,i=1;
	while(i<=10000){
		sum+=i*(a.rem%10);
		a.rem/=10;
		i*=10;
	}
	a.chunk=sum;
}
bool cmp(obj a,obj b){
	return (a.chunk<b.chunk||(a.chunk==b.chunk)&&(a.index<b.index));
}
int main (){
	ios::sync_with_stdio(false);
	vector<obj> data;
	int n,flag;
	obj temp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp.value;
		temp.rem=temp.value;
		temp.index=i;
		data.push_back(temp);
	}
	while(1){
		flag=1;
		for(int i=0;i<n;i++){
			findchunk(data[i]);
			if(data[i].chunk) flag=0;
		}
		if(flag) break;
		sort(data.begin(),data.end(),cmp);
		for(int i=0;i<n;i++){
			cout<<data[i].value<<" ";
			data[i].index=i;
		}
		cout<<endl;
	}
	return 0;
}
