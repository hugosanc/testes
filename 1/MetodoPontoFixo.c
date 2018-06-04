#include<stdio.h>
#include<math.h>

#define N 3
#define eps 1e-5

double f1( double x[N] )
{	return cos(x[1]* x[2])/ 3. + (1./6.);
}

double f2( double x[N] )
{	return sqrt( pow(x[0], 2) + sin(x[2]) + 1.06)/ 9 - 0.1;
}

double f3( double x[N] )
{	return -(1./20.)* exp(-x[0]* x[1]) - (10* M_PI - 3)/ 60;
}

void main()
{	double x[N] = {0}, xa[N] = {1,-1,1};
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
