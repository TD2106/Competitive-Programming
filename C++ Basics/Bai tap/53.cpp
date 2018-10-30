#include <iostream.h>
#include <conio.h>
#include <math.h>
int main ()
{
    int n,m,i,j,k,s=0,a=0;
    printf("Nhap vao so n ");
    scanf("%d",&n);
    printf("Nhap vao so m ");
    scanf("%d",&m);
    for(i=1;i<n;i++)
    {
                     s=0;
                     k=i;
                     while(k>=1)
                     {
                                j=k%10;
                                s=s+j*j;
                                k=k/10;
                                
                     }
                     if(s==m)
                     {
                             printf("So thoa de bai la: %d\n",i);
                             a=1;
                     }
                     
    }
    if(a==0)
    printf("Ko co so thoa man de bai");
    getch();
}
    
    
