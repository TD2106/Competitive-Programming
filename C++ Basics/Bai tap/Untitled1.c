# include <stdio.h>
# include <conio.h>
# include <math.h>
# define PI 3.14159265
main ()
{
     float R,P,a ;
     int n;
    
     printf (" Nhap so canh cua da giac : ");
     scanf ("%d", &n);
     printf (" Nhap ban kinh cua duong tron noi tiep : ");
     scanf ("%f", &R);
     a=2*tan(PI/n)*R;
     P=a*n;
     
     printf (" Chu vi la %f ", P);
     getch();
}
