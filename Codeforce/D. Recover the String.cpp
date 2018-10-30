#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
string Ti;
ll a00,a01,a10,a11,c0,c1,fr,bk,mid=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>a00>>a01>>a10>>a11;
	c0=ceil((-1.0+sqrt(1.0+4.0*a00))/2.0);
	c1=ceil((-1.0+sqrt(1.0+4.0*a11))/2.0);
	while(c0*(c0-1)/2<a00) c0++;
	while(c1*(c1-1)/2<a11) c1++;
	if(c0*(c0-1)/2!=a00||c1*(c1-1)/2!=a11){
        cout<<"Impossible"<<endl;
        return 0;
	}
	if(a00==0&&a11!=0){
        if(a10+a01==0) c0=0;
        else if(a10+a01==c1) c0=1;
        else{
            cout<<"Impossible"<<endl;
            return 0;
        }
	}
	else if(a00!=0&&a11==0){
        if(a10+a01==0) c1=0;
        else if(a10+a01==c0) c1=1;
        else{
            cout<<"Impossible"<<endl;
            return 0;
        }
	}
	else if(a00==0&&a11==0&&a10==0&&a01==0){
        cout<<1<<endl;
        return 0;
	}
	else if(a00==0&&a11==0&&a10==1&&a01==0){
        cout<<10<<endl;
        return 0;
	}
	else if(a00==0&&a11==0&&a10==0&&a01==1){
        cout<<"01"<<endl;
        return 0;
	}
	else if(a00==1&&a11==0&&a10==0&&a01==0){
        cout<<00<<endl;
        return 0;
	}
	else if(a00==0&&a11==1&&a10==0&&a01==0){
        cout<<11<<endl;
        return 0;
	}
	if(a01+a10!=c1*c0){
        cout<<"Impossible"<<endl;
        return 0;
	}
	if(c1==0){
        for(int i=0;i<c0;i++) cout<<0;
        return 0;
	}
	else if(c0==0){
        for(int i=0;i<c1;i++) cout<<1;
        return 0;
	}
    bk=a10/c1;
    if(a10%c1) mid=a10%c1;
    fr=c0-bk-bool(mid);
    for(int i=0;i<fr;i++) Ti+='0';
    for(int i=0;i<c1;i++){
        if(i==mid&&mid!=0) Ti+='0';
        Ti+='1';
    }
    for(int i=0;i<bk;i++) Ti+='0';
    cout<<Ti<<endl;
	return 0;
}
