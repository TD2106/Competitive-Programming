#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
int main ()
{
	int mang1[5]={1,3,4,5,6},mang2[5]={3,4,5,7,8};
	vector<int> kq(100);
	vector<int>::iterator itr;
	itr=std::set_difference(mang1,mang1+5,mang2,mang2+5,kq.begin());
	kq.resize(itr-kq.begin());
	for(int i=0;i<kq.size();i++)
	cout<<kq[i]<<" ";
	return 0;
}
