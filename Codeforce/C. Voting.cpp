#include <iostream>
#include <vector>
#include <list>
#define M 216107
using namespace std;
int main (){
	ios::sync_with_stdio(false);
	list<int> D,R;
	int n;
	list<int>::iterator idxD,idxR,temp;
	char ch;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ch;
		if(ch=='D') D.push_back(i);
		else R.push_back(i);
	}
	idxD=D.begin();
	idxR=R.begin();
	while(!D.empty()&!R.empty()){
		//cout<<*idxD<<" "<<*idxR<<endl;
		if((idxD==D.end())&&(idxR==R.end())){
			idxD=D.begin();
			idxR=R.begin();
		}
		else if(idxD==D.end()) D.erase(D.begin()),idxR++;
		else if(idxR==R.end()) R.erase(R.begin()),idxD++;
		else if(*idxD<*idxR){
			temp=idxR++;
			//cout<<*R.begin()<<endl;
			R.erase(temp);
			idxD++;
		}
		else{
			temp=idxD++;
			//cout<<*D.begin()<<endl;
			D.erase(temp);
			idxR++;
		}
	}
	if(D.empty()) cout<<"R"<<endl;
	else cout<<"D"<<endl;
	return 0;
}
