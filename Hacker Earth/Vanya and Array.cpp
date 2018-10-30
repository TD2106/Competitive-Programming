#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int a[1000005],BIT[1000005]={0},n,k,cur=0,temp,mx=1e6;
ll Ti=0;
vector<int> data;
vector<int>::iterator itr;
map<int,int> change;
map<int,int>::iterator itrmp;
void update(int x,int idx,int *arr){
    while(idx<=mx){
        arr[idx]+=x;
        idx+=idx&-idx;
    }
}
int query(int idx,int *arr){
    int sum=0;
    while(idx>0){
        sum+=arr[idx];
        idx-=idx&-idx;
    }
    return sum;
}
void convert(int arr[], int n)
{
    int temp[n+1];
    for (int i=1; i<=n; i++)
        temp[i] = arr[i];
    sort(temp+1, temp+1+n);int i;
    for (i=1; i<=n; i++)
    {
        arr[i] = lower_bound(temp+1, temp+1+n, arr[i]) - temp;
    }
}
int main(){
	//ios_base::sync_with_stdio(0);
    //freopen("Vanya and Array.txt","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	convert(a,n);
	for(int i=n;i>=1;i--){
        data.push_back(query(mx,BIT)-query(a[i],BIT));
        update(1,a[i],BIT);
	}
	sort(data.begin(),data.end());
	for(int i=n-1;i>=0;i--){
		int j=lower_bound(data.begin(),data.end(),k-data[i])-data.begin();
		if(j!=n && j<i) Ti+=i-j;
	}
	cout<<Ti<<endl;
	return 0;
}
