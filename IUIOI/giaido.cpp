#include <iostream>
#include <cmath>
using namespace std;
struct position
{
	int row;
	int column;
};
int main()
{
	int index,difficulty=0;
	char temp;
	position initial[16];
	for(int i=0;i<4;i++)
	{
		initial[i].row=0;
		initial[i].column=i;
		initial[i+4].row=1;
		initial[i+4].column=i;
		initial[i+8].row=2;
		initial[i+8].column=i;
		initial[i+12].row=3;
		initial[i+12].column=i;
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>temp;
			if(temp!='.')
			{
				index=temp-65;
				difficulty=difficulty+int(abs(initial[index].row-i))+int(abs(initial[index].column-j));
			}
		}
	}
	cout<<difficulty;
	return 0;	
}
