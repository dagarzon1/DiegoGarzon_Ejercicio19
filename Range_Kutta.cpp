#include<iostream>
#include<string.h>

using namespace std;

double fun(double x, double y);
double funZ(double x, double y);
void primer_orden(double * y, int a, int b, double in);
void segundo_orden(double * y, int a, int b, double in, double in_d);
int main(int argc, char ** argv)
{
	if(strcmp(argv[1],"primera")==0)
	{
		int a=0;
		int b=3;
		double * y;
		primer_orden(y,a,b,1.0);
	}
	if(strcmp(argv[1],"segunda")==0)
	{
		int a=0;
		int b=10;
		double * y;
		segundo_orden(y,a,b,1.0, 0.0);
	}
	return 0;
}
double fun(double x,double y)
{
	return (-1)*y;
}
double funZ(double x, double y)
{
	return y;
}
void primer_orden(double * y, int a, int b, double in)
{
	double h=0.01;
	int N=(b-a)/h;
	double x=a;
	y= new double[N];
	y[0]=in;
	cout << x << " " << y[0] << endl;
	double k_1,k_2,k_3,k_4;
	for(int i=1;i<N;i++)
	{
		x=x+h;
		k_1=fun( x,y[i-1] );
		k_2=fun( x + (h/2.0), y[i-1]+ ( ( h * k_1 ) / 2.0) );
		k_3=fun( x + (h/2.0), y[i-1]+ ( ( h * k_2 ) / 2.0) );
		k_4=fun( x+h,y[i-1]+( h * k_3 ) );
		y[i]=y[i-1]+( h/6.0 * ( k_1+k_4+( 2 * k_2)+( 2 * k_3 )) );
		cout << x << " " << y[i] << endl;
	}
}
void segundo_orden(double * y, int a, int b, double in, double in_d)
{
	double h=0.01;
	int N=(b-a)/h;
	double x=a;
	double * z=new double[N];
	y= new double[N];
	y[0]=in;
	z[0]=in_d;
	cout << x << " " << y[0] << " " << z[0] << endl;
	double zk_1,zk_2,zk_3,zk_4;
	double k_1,k_2,k_3,k_4;
	for(int i=1;i<N;i++)
	{
		x=x+h;

		zk_1=fun( x,y[i-1] );
		zk_2=fun( x + (h/2.0), y[i-1]+ ( ( h * zk_1 ) / 2.0) );
		zk_3=fun( x + (h/2.0), y[i-1]+ ( ( h * zk_2 ) / 2.0) );
		zk_4=fun( x+h,y[i-1]+( h * zk_3 ) );
		
		k_1=funZ( x,z[i-1] );
		k_2=funZ( x + (h/2.0), z[i-1]+ ( ( h * k_1 ) / 2.0) );
		k_3=funZ( x + (h/2.0), z[i-1]+ ( ( h * k_2 ) / 2.0) );
		k_4=funZ( x+h,z[i-1]+( h * k_3 ) );

		z[i]=z[i-1]+( h/6.0 * ( zk_1+zk_4+( 2 * zk_2)+( 2 * zk_3 )) );
		y[i]=y[i-1]+( h/6.0 * ( k_1+k_4+( 2 * k_2)+( 2 * k_3 )) );
		
		cout << x << " " << y[i] << " " << z[i] << endl;
	}
	
}
