#include<stdio.h>
#include<math.h>

#define N 3
#define eps 1e-5

double f1( double x[N] )
{	return sqrt( 8* pow( x[1], 2) - 10* x[2] );
}

double f2( double x[N] )
{	return pow( x[0], 2)/ ( 7* x[2] );
}

double f3( double x[N] )
{	return ( pow( x[0], 2 ) + 2* pow( x[1], 2 ) - x[1] );
}

void main()
{	double x[N] = {0}, xa[N] = {1,1,1};
	double norm, norma;
	double (*equacao[N])() = {f1,f2,f3};
	int i;

	do
	{	norma = norm = 0;
		for( i = 0; i < N; i++ )
		{	x[i] = equacao[i](xa);
			norm += pow( xa[i], 2);
			norma += pow( x[i], 2);
			xa[i] = x[i];
		}
	}while( eps < sqrt(fabs(norma-norm)));

	for( i = 0; i < N; i++ )
		printf("x[%d]: %lf\n", i, xa[i]);
}
