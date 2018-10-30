#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int tc,n,k,temp,hi,lo,mid;
vector<int> arr;
int check (int dis){
	int index=0;
	vector<int>::iterator itr;
	int ti=k;
	while(ti--){
		itr=upper_bound(arr.begin(),arr.end(),arr[index]+dis);
		itr--;
		if(itr==arr.end()-1&&ti>0) return 1;
		if(itr==arr.end()-1&&ti==0) return 2;
		index=itr-arr.begin();
	}
	return 3;
}
int main (){
	//freopen("NEWWORLD.txt","r",stdin);
	cin>>tc;
	while(tc--){
		cin>>n>>k;
		arr.clear();
		for(int i=0;i<n;i++){
			cin>>temp;
			arr.push_back(temp);
		}
		sort(arr.begin(),arr.end());
		lo=0;
		for(int i=0;i<n-1;i++)
		lo=max(arr[i+1]-arr[i],lo);
		hi=arr[n-1]-arr[0];
		while(lo<hi){
			mid=(lo+hi)/2; 
			temp=check(mid);
			if(temp==1) hi=mid-1;
			else if(temp==2) hi=mid;
			else lo=mid+1;	
		}
		cout<<lo<<endl;		
	}
	return 0;
}
