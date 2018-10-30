#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,m,Ti=0,hourDigit,minuteDigit;
vector<int> digit;
bool used[7]={0};
void process(){
    int hour=0,minute=0;
    for(int i=0;i<hourDigit;i++){
        hour*=7;
        hour+=digit[i];
    }
    for(int i=hourDigit;i<digit.size();i++){
        minute*=7;
        minute+=digit[i];
    }
    if(hour<n&&minute<m) Ti++;
}
void generatePermutation(int i,int totalSize){
    if(i==totalSize) process();
    else{
        for(int j=0;j<7;j++){
            if(!used[j]){
                used[j]=1;
                digit.push_back(j);
                generatePermutation(i+1,totalSize);
                digit.pop_back();
                used[j]=0;
            }
        }
    }
}
int getSizeBase7(int x){
    int ans=0;
    if(x==0) return 1;
    while(x){
        ans++;
        x/=7;
    }
    return ans;
}
int main(){
    cin>>n>>m;
    hourDigit=getSizeBase7(n-1);
    minuteDigit=getSizeBase7(m-1);
    if(hourDigit+minuteDigit>7) cout<<0<<endl;
    else{
        generatePermutation(0,hourDigit+minuteDigit);
        cout<<Ti<<endl;
    }
	return 0;
}
