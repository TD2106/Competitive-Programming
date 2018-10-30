#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll p,x,y,Ti=1e18,temp,t,o;
bool isPossible[475]={0};
void precompute(){
    ll point;
    for(ll i=0;i<475;i++){
        point=i;
        for(ll j=0;j<25;j++){
            point=(point*96+42)%475;
            if(26+point==p){
                isPossible[i]=1;
                break;
            }
        }
    }
}
int main(){
    cin>>p>>y>>x;
    precompute();
    if(x>y){
        o+=(x-y)/100;
        y+=(x-y)/100*100;
        if((x-y)%100!=0){
            o++;
            y+=100;
        }
    }
    //cout<<y<<endl;
    for(ll i=0;i<475;i++){
        if(isPossible[i]){
            temp=(y/50)%475;
            if(temp==i){
                //cout<<123<<endl;
                Ti=0;
                cout<<Ti<<endl;
                return 0;
            }
            else{
                t=1;
                while((y-t*50)>=x){
                    if(((y-t*50)/50)%475==i){
                       // cout<<123<<endl;
                        Ti=0;
                        cout<<Ti<<endl;
                        return 0;
                    }
                    else t++;
                }
                t=0;
                if(temp<i){
                    while(temp<i){
                        temp+=2;
                        t++;
                    }
                }
                else{
                    //cout<<i<<endl;
                    while(temp<475){
                        temp+=2;
                        t++;
                    }
                    temp%=475;
                    while(temp<i){
                        temp+=2;
                        t++;
                    }
                }
                //cout<<i<<" "<<o+t<<endl;
                Ti=min(Ti,o+t);
            }
        }
    }
    cout<<Ti<<endl;
	return 0;
}
