#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
stack<char> charStack;
map<char,int> cnt;
string s,Ti;
bool hasBigger(char c){
    for(char i=c-1;i>='a';i--){
        if(cnt[i]) return 1;
    }
    return 0;
}
int main(){
    cin>>s;
    for(int i=0;i<s.size();i++) cnt[s[i]]++;
    for(int i=0;i<s.size();i++){
        charStack.push(s[i]);
        cnt[s[i]]--;
        while(!charStack.empty()&&!hasBigger(charStack.top())){
            Ti+=charStack.top();
            charStack.pop();
        }
    }
    cout<<Ti<<endl;
}
