#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool check1(int arr1[],int arr2[]){
	for(int i=0;i<26;i++){
		if(arr1[i]!=arr2[i])
		return 0;
	}
	return 1;
}
bool check2(int arr1[],int arr2[]){
	bool first=0;
	for(int i=0;i<26;i++){
		if(abs(arr1[i]-arr2[i])&&first==0){
			first=1;
		}
		else if(arr1[i]==arr2[i]) continue;
		else return 0;
	}
	return first;
}
bool check3(int arr1[],int arr2[]){
	int count=0;
	for(int i=0;i<26;i++){
		if(arr1[i]==arr2[i]) continue;
		if(abs(arr1[i]-arr2[i])==1){
			count++;
		}
		else return 0;
	}
	return (count==2);
}
int main (){
	int arr1[26]={0},arr2[26]={0};
	string a,b;
	cin>>a>>b;
	if(a>b)
	swap(a,b);
	for(int i=0;i<a.size();i++){
		arr1[a[i]-'a']++;
	}
	for(int i=0;i<b.size();i++){
		arr2[b[i]-'a']++;
	}
	if(a==b){
		cout<<a<<" is identical to "<<b<<endl;
		return 0;
	}
	if(a.size()==b.size()&&check1(arr1,arr2)==1){
		cout<<a<<" is an anagram of "<<b<<endl;
		return 0;
	}
	if(a.size()==b.size()&&check3(arr1,arr2)==1){
		cout<<a<<" is almost an anagram of "<<b<<endl;
		return 0;
	}
	if(abs((int)a.size()-(int)b.size())==1&&check2(arr1,arr2)==1){
		cout<<a<<" is almost an anagram of "<<b<<endl;
		return 0;
	}
	cout<<a<<" is nothing like "<<b<<endl;
	return 0;
}
