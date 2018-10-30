#include <stdio.h>
#include <stdlib.h>
int main ()
{
	char *name,*name2;
	name=(char*)malloc(3*sizeof(char));
	name[0]='D';name[1]='u';name[2]='y';
	realloc(name,1*sizeof(char));
	printf("%d",strlen(name));
	return 0;
}
