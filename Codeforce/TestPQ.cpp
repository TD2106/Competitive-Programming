#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
struct obj{
    int a,b,c;
    void print(){
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
};
class Compare{
public:
    bool operator()(int a,int b){
        return a<b;
    }
};
int main(){
	ios_base::sync_with_stdio(0);
	priority_queue<int,vector<int>,Compare> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    cout<<pq.top()<<endl;
    obj test;
    test.a=1;
    test.b=2;
    test.c=3;
    test.print();
    string s="ILPL ILPL";
    s.erase(0,5);
    cout<<s<<endl;
	return 0;
}
