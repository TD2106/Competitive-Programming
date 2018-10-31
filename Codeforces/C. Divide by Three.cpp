#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
string s,sc,Ti;
int a[3]={0},mn=1e9,temp,sum=0,t,c=0;
int main(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        temp=s[i]-'0';
        a[temp%3]++;
        sum+=temp;
        sum%=3;
    }
    if(sum==0){
        cout<<s<<endl;
        return 0;
    }
    sc=s;
    a[(s[0]-'0')%3]--;
    if((sum==2&&a[2])){
        for(int i=1;i<sc.size();i++){
            temp = sc[i] - '0';
            if(temp%3==2){
                sc.erase(i,1);
                break;
            }
        }
        mn=1;
        Ti=sc;
    }
    else if(sum==1&&a[1]){
        for(int i=1;i<sc.size();i++){
            temp = sc[i] - '0';
            if(temp%3==1){
                sc.erase(i,1);
                break;
                }
            }
        mn=1;
        Ti=sc;
    }
    else if(sum==1&&a[1]==0){
        t=4;
        for(int i=1;i<sc.size()&&t!=0;i++){
            temp = sc[i] - '0';
            if(temp%3==2){
                sc.erase(i,1);
                i--;
                t-=2;
                c++;
            }
        }
        if(t==0) Ti=sc,mn=c;
    }
    else {
        t=sum;
        for(int i=1;i<sc.size()&&t!=0;i++){
            temp = sc[i] - '0';
            if(temp%3==1){
                sc.erase(i,1);
                i--;
                t--;
                c++;
            }
        }
        if(t==0) Ti=sc,mn=c;
    }
    a[(s[0]-'0')%3]++;
    if(sum==2&&a[2]){
        for(int i=0;i<s.size();i++){
            temp = s[i] - '0';
            if(temp%3==2){
                s.erase(i,1);
                c=1;
                break;
            }
        }
        while(s.size()!=1&&s[0]=='0') c++,s.erase(0,1);
        if(c<mn) Ti=s,mn=c;
    }
    else if(sum==1&&a[1]){
        for(int i=0;i<s.size();i++){
            temp = s[i] - '0';
            if(temp%3==1){
                s.erase(i,1);
                c=1;
                break;
            }
        }
        while(s.size()!=1&&s[0]=='0') c++,s.erase(0,1);
        if(c<mn) Ti=s,mn=c;
    }
    else if(sum==1&&a[1]==0){
        t=4;
        for(int i=0;i<s.size()&&t!=0;i++){
            temp = s[i] - '0';
            if(temp%3==2){
                s.erase(i,1);
                i--;
                t-=2;
                c++;
            }
        }
        while(s.size()!=1&&s[0]=='0') c++,s.erase(0,1);
        if(c<mn) Ti=s,mn=c;
    }
    else {
       // cout<<123<<endl;
        t=sum;
      //  cout<<t<<endl;
        for(int i=0;i<s.size()&&t!=0;i++){
            temp = s[i] - '0';
            if(temp%3==1){
              //  cout<<123<<endl;
                s.erase(i,1);
                i--;
                t--;
                c++;
            }
        }
        //cout<<s<<endl;
        while(s.size()!=1&&s[0]=='0') c++,s.erase(0,1);
        //cout<<s<<endl;
        if(c<mn) Ti=s,mn=c;
    }
    if(Ti.size()==0) cout<<-1<<endl;
    else cout<<Ti<<endl;
    return 0;
}
