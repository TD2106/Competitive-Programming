#include <iostream>
#include <vector>
using namespace std;

struct INFO
{
	string name;
	string add;
	string ticket;
};

void print(INFO print)
{
	cout<<"Ten: "<<print.name<<endl;
	cout<<"Dia chi: "<<print.add<<endl;
	cout<<"So ve: "<<print.ticket<<endl;
	cout<<endl;
}

int main ()
{
	int n;
	cout<<"Nhap so nguoi mua ve ";
	cin>>n;
	vector <INFO> tin;
	INFO i;
	for(int j=1;j<=n;j++)
	{	
		fflush(stdin);
		cout<<"Nhap ten nguoi thu "<<j<<": "; 
		getline(cin,i.name);
		cout<<"Nhap dia chi nguoi thu "<<j<<": ";
		fflush(stdin);
		getline(cin,i.add);
		cout<<"Nhap so ve nguoi thu "<<j<<" mua : ";
		fflush(stdin);
		cin>>i.ticket;
		tin.push_back(i);
	}
	for(int i=0;i<n;i++)
	print(tin[i]);
	return 0;
}
