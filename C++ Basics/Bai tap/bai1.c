# include <stdio.h>
# include <conio.h>
# include <math.h>
main ()
{
     float T, l, g=918, pi=3.14159 ;
     printf (" Nhap chieu dai day (cm) : ");
     scanf ("%f", &l);
     T=2*pi*sqrt(l/g);
     printf (" Chu ki la %f ", T);
     getch();
}
