#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define N 3
#define eps 1e-5

double f1( double x[N] )
{	return pow(x[0], 2) - 81* pow((x[1] + 0.1), 2) + sin(x[2]) + 1.06;
}

double f2( double x[N] )
{	return exp(x[0]* x[1]) + 20* x[2] + (10* M_PI-3)/ 3.;
}

double f3( double x[N] )
{	return 3* x[0] - cos(x[1]* x[2]) - 0.5;
}

double h1( double x[N] )
{	return 2* x[0];
}

double h2( double x[N] )
{	return -162* (x[1] + 0.1);
}

double h3( double x[N] )
{	return -cos(x[2]);
}

double h4( double x[N] )
{	return x[1]* exp(x[0]* x[1]);
}

double h5( double x[N] )
{	return x[0]* exp(x[0]* x[1]);
}

double h6( double x[N] )
{	return 20;
}

double h7( double x[N] )
{	return 3;
}

double h8( double x[N] )
{	return x[2]* sin(x[1]* x[2]);
}

double h9( double x[N] )
{	return x[1]* sin(x[1]* x[2]);
}

void main()
{	double x0[N] = {0,0,0}, x1[N], a[N], h[N];
	double norm, norma, g, g1, g2, g3, gradg[N] = {0}, modGradg = 0;
	double (*F[N])() = {f1,f2,f3};
	double (*J[N][N])() = {{h1,h2,h3},{h4,h5,h6},{h7,h8,h9}};
	int i,j;
	
	for( i = 0; i < N; i++ )
		g += pow( F[i](x0), 2);
		
	for( i = 0 ; i < N ; i++ )
	{	for( j = 0 ; j < N ; j++ )
			gradg[i] += 2* J[j][i](x0)* F[j](x0);
		modGradg += pow( gradg[i], 2 );
	}
	modGradg = sqrt( modGradg );
	
	a[0] = 0;
	a[2] = 1;
	
	for( i = 0; i < N; i++ )
	{	x1[i] = x0[i] - a[0]* gradg[i];
	}
	for( i = 0; i < N; i++ )
		g1 += pow( F[i](x1), 2);
			
	for( i = 0; i < N; i++ )
	{	x1[i] = x0[i] - a[2]* gradg[i];
	}
	for( i = 0; i < N; i++ )
		g3 += pow( F[i](x1), 2);
			
	while( g3 > g1 )
	{
		a[2] /= 2;
		
		for( i = 0; i < N; i++ )
		{	x1[i] = x0[i] - a[2]* gradg[i];
		}
		for( i = 0; i < N; i++ )
			g3 += pow( F[i](x1), 2);
		
		if( a[2] < 1e-6 )
			break;
		
	}
	a[1] = a[2]/2;

	
	for( i = 0; i < N; i++ )
	{	x1[i] = x0[i] - a[1]* gradg[i];
	}
	for( i = 0; i < N; i++ )
		g2 += pow( F[i](x1), 2);
	
	printf("g:%f\n||gradg||: %f\n",g, modGradg);
	
	//Calcular os h's -> P(a)
}
		
