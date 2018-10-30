#include <iostream.h>
#include <math.h>
#include <conio.h>
int main ()
{
    int n,i,j,k,z,s=0,a,b;
    printf("Nhap vap so n: ");
    scanf("%d",&n);
    a=sqrt(n);
    for(i=1;i<=a;i++)
    {
                     for(j=1;j<=i;j++)
                     {
                                      for(k=1;k<=j;k++)
                                      {
                                                       for(z=1;z<=k;z++)
                                                       {
                                                                        b=i*i+j*j+k*k+z*z;
                                                                        if(b==n)
                                                                        {
                                                                                                printf("4 so thoa de la %d %d %d %d\n",i,j,k,z);
                                                                                                s=1;
                                                                        }
                                                       }
                                      }
                     }
    }
    if(s==0)
    printf("Ko co 4 so thoa de");
    getch();
}
