#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;
struct object
{
	int value;
	int index;
};
bool mycmp(const object &a, const object &b)
{
	return (a.value<b.value);
}
int main ()
{
	int n,tempvalue;
	vector<object> card;
	object tempcard;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>tempvalue;
		tempcard.index=i;
		tempcard.value=tempvalue;
		card.push_back(tempcard);
	}
	sort(card.begin(),card.end(),mycmp);
	for(int i=0;i<n/2;i++)
	{
		cout<<card[i].index<<" "<<card[n-1-i].index<<"\n";
	}
	return 0;
}
