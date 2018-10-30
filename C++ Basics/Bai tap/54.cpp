#include <iostream.h>
#include <math.h>
#include <conio.h>
int main ()
{
    int k,i,j,s,a=0;
    printf("Nhap vao so k: ");
    scanf("%d",&k);
    for(i=1;i<k;i++)
    {
                 s=0;
                 for(j=1;j<i;j++)
                 {
                                  if((i%j)==0)
                                  {
                                              
                                              s=s+j;
                                              
                                              
                                  }
                 }
                 if(s==i)
                 {
                 printf("So hoan hao la: %d\n",i);
                 a=1;
                 }
    }
    if(a==0);
    printf("Ko co so tu nhien hoan hao be hon %d",k);
    getch();
}
                 
                                  
