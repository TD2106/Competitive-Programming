#include <iostream>
#include <vector>
using namespace std;
struct obj
{
	float x;
	float y;
};
int main ()
{
	int n,cnt=0;
	cin>>n;
	cin.ignore();
	char temp;
	obj input;
	vector<obj> pos;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>temp;
			if(temp!='.')
			{
				input.x=(float)i;
				input.y=(float)j;
				pos.push_back(input);
			}
		}
	}
	/*for(int i=0;i<pos.size();i++)
	{
		cout<<pos[i].x<<" "<<pos[i].y<<endl;
	}*/
	for(int i=0;i<pos.size()-2;i++)
	{
		for(int j=i+1;j<pos.size()-1;j++)
		{
			for(int k=j+1;k<pos.size();k++)
			{
				float line1=pos[i].x-pos[j].x,line2=pos[i].y-pos[j].y,line3=pos[i].x-pos[k].x,line4=pos[i].y-pos[k].y;
				float divide1=line1*1.0/line2,divide2=line3*1.0/line4;
				if(divide1==divide2)
				{
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
