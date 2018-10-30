#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define endl '\n'
#define bug(x) cout<< #x << " = " << x <<endl
#define reset(a) memset(a,0,sizeof(a))
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
int lps[100005]={0},trie[100005][26]={0},node=0,cnt[100005]={0};
void KMPPrecompute(const string& pattern){
    lps[0]=-1;
    int i=0,j=-1;
    while(i<pattern.size()){
        while(j>=0&&pattern[i]!=pattern[j]) j=lps[j];
        i++;
        j++;
        lps[i]=j;
    }
}
void KMPSearch(const string& text, const string& pattern){
    KMPPrecompute(pattern);
    int i=0,j=0;
    while(i<text.size()){
        while(j>=0&&text[i]!=pattern[j]) j=lps[j];
        i++;
        j++;
        if(j==pattern.size()){
            cout<<i-j<<endl;
            j=lps[j];
        }
    }
}
void addTrie(const string& s){
    int v=0,tmp;
    for(char c:s){
        tmp=c-'a';
        if(trie[v][tmp]==0) trie[v][tmp]=++node;
        v=trie[v][tmp];
    }
    cnt[v]++;
}
int main(){
    ios_base::sync_with_stdio(0);
    return 0;
}
