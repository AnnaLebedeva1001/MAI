#include <math.h>
#include <stdio.h>


double Epsylone() 
{
	//calc machine EPS
	double eps = 1.0;
	while ((double)(eps / 2.0 + 1.0) > 1.0) 
	{
	eps = eps / 2.0;
	}	
	return eps;
}
double Pow(double a, int n)
{
	if (n == 0)
		return 1;
		if (n == 1)
		return a;
		if (n % 2 == 0)
		return Pow(a * a, n / 2);
		else
		return a * Pow(a, n - 1); 
}
int main()
{
int k;
printf("Please, inter the number of parts of the segment: ");
scanf("%d", &k);
double x, d, S = 0, eps;
eps = Epsylone();
double a = 0.1;
double b = 0.6;
double h = (b - a) / (double)k;
int n;
printf("\n Machine eps= %.17f\n", eps);
printf("-------------------------------------------------------------\n");
printf("|   x   |          S           |(2 * x - 3) /(x - 1)^2|  n |\n");
printf("|-------|----------------------|----------------------|----|\n");
for (x = a; (x - b) < eps; x += h)
	{
	n = 1;
	double base_element = -3.0;
	double power_element;
	S = 0;
	d = base_element;
	while (fabs(d) > eps)
	{
		power_element = Pow(x, n);
		double factor = -(n + 3.0);
		d = base_element + factor * power_element;
		S += d;
		n++;
		base_element = 0;
		
	}
	printf("| %.3f | %2.17f | %2.17f | %2d |\n", x, S, (2.0 * x - 3.0) / ((x - 1.0) * (x - 1.0)), n);
}
printf("--------------------------------------------------------------\n");
return 0;
}
