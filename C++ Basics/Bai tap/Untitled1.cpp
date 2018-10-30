#include<iostream>
using namespace std;
int main()
{
	cout << "\n";
	for (int i = 1; i<=9;i++)
	for (int j = 0; j <= 9; j++)
	if (i*j == 2 * (i + j)) cout << "  " << i * 10 + j;
	cout << "\n "; 
	system("pause");
}
