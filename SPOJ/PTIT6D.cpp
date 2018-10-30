#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
	vector<int> card;
	int temp;
	for(int i=0;i<4;i++)
	{
		cin>>temp;
		card.push_back(temp);
	}
	sort(card.begin(),card.end());
	cin.ignore();
	char magic;
	for(int i=0;i<3;i++)
	{
		cin>>magic;
		if(magic=='+')
		{
			temp=0;
			temp+=card.back();
			card.pop_back();
			temp+=card.back();
			card.pop_back();
			card.push_back(temp);
		}
		else if (magic=='*')
		{
			temp=1;
			temp*=card.front();
			card.erase(card.begin());
			temp*=card.back();
			card.erase(card.end()-1);
			card.push_back(temp);
			sort(card.begin(),card.end());
		}
	}
	cout<<card[0];
	return 0;
}
