#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<iostream>
using namespace std;
long long n, m, res;

int main() 
{
    //freopen("TROCHOI.INP","r", stdin);
	//freopen("TROCHOI.OUT","w", stdout);
    scanf("%lld %lld", &n, &m);
    res = n * m;
    while(res > n) 
	{
		res += (res - n - 1) / (m - 1) - n;
    }
    printf("%lld", res);
	return 0;
}