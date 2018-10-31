#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main (){
    int n,k,a[100];
    vector<int> player,temp;
    cin>>n>>k;
    for(int i=0;i<k;i++) cin>>a[i];
    for(int i=0;i<n;i++) player.pb(i+1);
    for(int i=0;i<k;i++){
        temp.clear();
       // cout<<player.size()<<endl;
        if(a[i]<=player.size()-1){
            cout<<player[a[i]]<<endl;
            for(int j=a[i]+1;j<player.size();j++) temp.pb(player[j]);
            for(int j=0;j<a[i];j++) temp.pb(player[j]);
            player=temp;
        }
        else{
            a[i]-=player.size()-1;
           // cout<<a[i]<<endl;
            if(a[i]>player.size()&&a[i]%player.size()!=0) a[i]=a[i]-(a[i]/player.size())*player.size();
            else if(a[i]!=0&&a[i]%player.size()==0) a[i]=player.size();
            //cout<<a[i]<<endl;
            cout<<player[a[i]-1]<<endl;
            for(int j=a[i];j<player.size();j++) temp.pb(player[j]);
            for(int j=0;j<a[i]-1;j++) temp.pb(player[j]);
            player=temp;
        }
    }
    return 0;
}
