#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
pair<pair<int,int>,int> activity[1000005];
int n,last;
vector<int> Ti;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>activity[i].first.second>>activity[i].first.first;
        activity[i].second=i+1;
    }
    sort(activity,activity+n);
    for(int i=0;i<n;i++){
        if(i==0){
            Ti.push_back(activity[i].second);
            last=activity[i].first.first;
        }
        else if(activity[i].first.second>=last){
            Ti.push_back(activity[i].second);
            last=activity[i].first.first;
        }
    }
    cout<<Ti.size()<<endl;
    for(int i=0;i<Ti.size();i++) cout<<Ti[i]<<endl;
	return 0;
}
