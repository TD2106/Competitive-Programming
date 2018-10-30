#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct obj
{
	int value;
	int power;
};
bool cmp(obj a,obj b)
{
	return (a.power<b.power);
}
int main ()
{
	int n,m;
	obj temp;
	vector<obj> dathuc1,dathuc2,total,ans;
	cout<<"Nhap so phan tu cua da thuc 1 va da thuc 2: ";
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap gia tri so hang: ";
		cin>>temp.value;
		cout<<"Nhap mu: ";
		cin>>temp.power;
		dathuc1.push_back(temp);
		total.push_back(temp);
	}
	for(int i=0;i<m;i++)
	{
		cout<<"Nhap gia tri so hang: ";
		cin>>temp.value;
		cout<<"Nhap mu: ";
		cin>>temp.power;
		dathuc2.push_back(temp);
		total.push_back(temp);
	}
	sort(total.begin(),total.end(),cmp);
	int start=total[0].power;
	for(int i=0;i<m+n;i++)
	{
		int j=i,sum=0;
		while(j<m+n&&total[j].power==start)
		{
			sum+=total[j].value;
			j++;
		}
		temp.value=sum;
		temp.power=total[j-1].power;
		ans.push_back(temp);
		if(j<m+n)
		start=total[j].power;
		i=--j;
	}
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i].value<0)
		cout<<ans[i].value<<"x^"<<ans[i].power<<" ";
		else
		cout<<"+"<<ans[i].value<<"x^"<<ans[i].power<<" ";
	}
	return 0;
}
