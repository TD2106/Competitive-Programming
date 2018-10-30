#include <iostream.h>
#include <math.h>
#include <conio.h>
int main ()
{
    int n,i,j,k,a=0;
    float s;
    
    printf("Nhap vao so n: ");
    scanf("%d",&n);
    s=pow(n,1/3);
    for(i=1;i<=s;i++)
    {
                              for(j=1;j<=i;j++)
                              {
                                               for(k=1;k<=j;k++)
                                               {
                                                                s= i*i*i + j*j*j + k*k*k ;
                                                                if(s==n)
                                                                {
                                                                        printf("Ba so thoa man dieu kien la %d, %d, %d\n",i,j,k);
                                                                        a=1;
                                                                }
                                               }
                              }
    }
    if(a==0)
    printf("Ko co 3 so thoa de bai");
    getch();
}
