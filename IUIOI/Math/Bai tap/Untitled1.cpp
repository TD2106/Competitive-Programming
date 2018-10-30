#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main ()
{
	char *str,*str2;
	str=(char*)malloc(20*sizeof(char));
	strcpy(str,"Le Vo Thanh Duy");
	printf("%s",str);
	str2=(char*)realloc(str,5*sizeof(char));
	printf("\n%s",str2);
	return 0;
}
