#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
int Ti=0;
vi c1,c2;
vector<vi> data;
string s1,s2;
void printVI(vi& a){
    for(int i=0;i<a.size();i++) cout<<char(i+'a')<<a[i]<<" ";
    cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin>>s1>>s2;
    if(s1.size()>s2.size()) swap(s1,s2);
    for(int length=s1.size();length>=1;length--){
        if(Ti) break;
        data.clear();
        c1.clear();
        c2.clear();
        c1.resize(26);
        c2.resize(26);
        for(int i=0;i<length&&i<s2.size();i++) c2[s2[i]-'a']++;
        for(int i=0;i<length&&i<s1.size();i++) c1[s1[i]-'a']++;
        data.push_back(c2);
        for(int i=1;i<s2.size()-length+1;i++){
            c2[s2[i-1]-'a']--;
            c2[s2[i+length-1]-'a']++;
            data.push_back(c2);
        }
        sort(data.begin(),data.end());
        if(binary_search(data.begin(),data.end(),c1)){
            Ti=length;
            break;
        }
        for(int i=1;i<s1.size()-length+1;i++){
            c1[s1[i-1]-'a']--;
            c1[s1[i+length-1]-'a']++;
            if(binary_search(data.begin(),data.end(),c1)){
                Ti=length;
                break;
            }
        }
    }
    cout<<Ti<<endl;
	return 0;
}
