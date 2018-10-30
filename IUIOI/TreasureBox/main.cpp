#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll tc,n,k,Ti;
vector<ll> toBeAdded;
vector<ll>::iterator itr;
int main()
{
    cin>>tc;
    while(tc--){
        cin>>n>>k;
        if(k<=1e5){
            Ti=n;
            while(k--)
            Ti=Ti+Ti%100;
        }
        else{
			toBeAdded.clear();
            Ti=n;
            toBeAdded.push_back(n%100);
            n+=n%100;
            itr=find(toBeAdded.begin(),toBeAdded.end(),n%100);
            while(itr==toBeAdded.end()){
                toBeAdded.push_back(n%100);
                n+=n%100;
                itr=find(toBeAdded.begin(),toBeAdded.end(),n%100);
            }
            for(int i=0;i<(itr-toBeAdded.begin())&&k>0;i++){
                Ti+=toBeAdded[i];
                k--;
            }
            toBeAdded.erase(toBeAdded.begin(),itr);
            ll sum=0;
            for(int i=0;i<toBeAdded.size();i++) sum+=toBeAdded[i];
            Ti+=sum*(k/toBeAdded.size());
            k%=toBeAdded.size();
            for(int i=0;i<k;i++) Ti+=toBeAdded[i];
            //cout<<Ti<<endl;
        }
        cout<<Ti<<endl;
    }
    return 0;
}
