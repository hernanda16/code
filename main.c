#include <stdio.h>

void prima(int angka, int checker, int n, int nmax);

int main()
{
    int N;
    printf("Jumlah bilangan prima N = ");
    scanf ("%d",&N);
    prima(2,2,1,N);
}

void prima(int angka, int checker, int n, int nmax)
{
    if (n == (nmax+1))
    {
        printf("gabisa");
    }
    else if(angka == checker)
    {
        printf("%d ",angka);
        checker = 2;
        prima((angka+1), checker, (n+1),nmax);
    }
    else if(angka%checker != 0)
    {
        prima (angka, (checker+1), n,nmax);
    }
    else if(angka%checker == 0)
    {
        checker =2;
        prima ((angka+1),checker,n,nmax);
    }
}