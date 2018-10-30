#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
void processarr(int arr[],char check)
{
	switch(check)
	{
		case 'a':
			{
				if(arr[1]==9)
				arr[1]=0;
				else
				arr[1]++;
				if(arr[2]==9)
				arr[2]=0;
				else
				arr[2]++;
				if(arr[4]==9)
				arr[4]=0;
				else
				arr[4]++;
				break;
			}
		case 'b':
			{
				if(arr[1]==9)
				arr[1]=0;
				else
				arr[1]++;
				if(arr[2]==9)
				arr[2]=0;
				else
				arr[2]++;
				if(arr[5]==9)
				arr[5]=0;
				else
				arr[5]++;
				if(arr[3]==9)
				arr[3]=0;
				else
				arr[3]++;
				break;
			}
		case 'c':
			{
				if(arr[2]==9)
				arr[2]=0;
				else
				arr[2]++;
				if(arr[6]==9)
				arr[6]=0;
				else
				arr[6]++;
				if(arr[3]==9)
				arr[3]=0;
				else
				arr[3]++;
				break;
			}
		case 'd':
			{
				if(arr[1]==9)
				arr[1]=0;
				else
				arr[1]++;
				if(arr[4]==9)
				arr[4]=0;
				else
				arr[4]++;
				if(arr[5]==9)
				arr[5]=0;
				else
				arr[5]++;
				if(arr[7]==9)
				arr[7]=0;
				else
				arr[7]++;
				break;
			}
		case 'e' :
			{
				if(arr[2]==9)
				arr[2]=0;
				else
				arr[2]++;
				if(arr[4]==9)
				arr[4]=0;
				else
				arr[4]++;
				if(arr[5]==9)
				arr[5]=0;
				else
				arr[5]++;
				if(arr[6]==9)
				arr[6]=0;
				else
				arr[6]++;
				if(arr[8]==9)
				arr[8]=0;
				else
				arr[8]++;
				break;
			}
		case 'f' :
			{
				if(arr[6]==9)
				arr[6]=0;
				else
				arr[6]++;
				if(arr[3]==9)
				arr[3]=0;
				else
				arr[3]++;
				if(arr[9]==9)
				arr[9]=0;
				else
				arr[9]++;
				if(arr[5]==9)
				arr[5]=0;
				else
				arr[5]++;
				break;
			}
		case 'g' :
			{
				if(arr[4]==9)
				arr[4]=0;
				else
				arr[4]++;
				if(arr[7]==9)
				arr[7]=0;
				else
				arr[7]++;
				if(arr[8]==9)
				arr[8]=0;
				else
				arr[8]++;
				break;
			}
		case 'h' :
			{
				if(arr[5]==9)
				arr[5]=0;
				else
				arr[5]++;
				if(arr[9]==9)
				arr[9]=0;
				else
				arr[9]++;
				if(arr[7]==9)
				arr[7]=0;
				else
				arr[7]++;
				if(arr[8]==9)
				arr[8]=0;
				else
				arr[8]++;
				break;
			}
		case 'i' :
			{
				if(arr[6]==9)
				arr[6]=0;
				else
				arr[6]++;
				if(arr[9]==9)
				arr[9]=0;
				else
				arr[9]++;
				if(arr[8]==9)
				arr[8]=0;
				else
				arr[8]++;
				break;
			}
	}
}
int main ()
{
	char s[256];
	int count=1;
	//freopen("12398.txt","r",stdin);
	while(fgets(s,256,stdin) != NULL)
	{
		int arr[10]={0};
		if(s[0]=='\n')
		{
			cout<<"Case #"<<count<<":\n";
			cout<<"0 0 0\n";
			cout<<"0 0 0\n";
			cout<<"0 0 0\n";
		}
		else
		{
			int end=strlen(s)-1;
			for(int i=end;i>-1;i--)
			{
				processarr(arr,s[i]);
			}
			cout<<"Case #"<<count<<":\n";
			for(int i=1;i<10;i+=3)
			{
				cout<<arr[i]<<" "<<arr[i+1]<<" "<<arr[i+2]<<"\n";
			}
		}
		count++;
	}
	return 0;
}
