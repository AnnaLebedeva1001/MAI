#include <stdio.h>
#include <math.h>

double eps=0;
int flag=0;
typedef double (*func) (double);

double Epsylone() 
	{
	double eps = 1.0;
	while ((double)(eps / 2.0 + 1.0) > 1.0) 
	{
	eps = eps / 2.0;
	}	
	return eps;
	}
double F14 (double x)
{
	return tan(x/2)-1/tan(x/2)+x;
}
double F15 (double x)
{
	return 0.4+atan(sqrt(x))-x;
}
double d_F14 (double x)
{
	return 1/(2*cos(x/2)*cos(x/2))+1/(2*sin(x/2)*sin(x/2))+1;
}
double d_F15 (double x)
{
	return 1/(2*(x+1)*sqrt(x))-1;
}
double XF14 (double x)
{
	return 1/tan(x/2)-tan(x/2);
}
double XF15 (double x)
{
	return 0.4+atan(sqrt(x));
}

double iteration_check (func d_F, double a, double b)
{
	int flag=0;
	double i=0;
	double dx=0.000001;
	for (i=a; i<b; i+=dx)
	    if (fabs (d_F(i))>=1)
	    	flag=1;
	return flag;
}
double diho (double a, double b, func F)
{
	double as=0;
	double bs=0;
		while ((fabs(a-b)>eps))
		{
			if ((F(a)*F((a+b)/2))>0)
			{
				as=(a+b)/2;
				bs=b;
			}
			if ((F(b)*F((a+b)/2))>0)
			{
				as=a;
				bs=(a+b)/2;
			}
				a=as;
				b=bs;
			
		}
	return ((a+b)/2);
}

double iteration (func XF, func d_F, double a, double b, double eps)
{
	double zeroX = (a+b)/2, x = a, K=0;
	if (iteration_check(d_F,a,b)==1) return 0;
		while (fabs(x-zeroX)>eps)
			{
				K=zeroX;
				zeroX=x;
				x=XF(K);
			}
	return x;
}
double NewTone (double F(double), double d_F(double), double a, double b, double eps)
{
	double x=(a+b)/2;
		double x1=x+1;
		while(fabs(x-x1)>eps)
		{
			x1=x;
			x=x-F(x)/d_F(x);
		}
		return x;
}

int main ()
{
  double a1 = 0, b1 = 0, a2 = 0, b2 = 0;
  int k=0;
  double d1=0,i1=0,n1=0,d2=0,i2=0,n2=0;
  a1 = 1;
  b1 = 2;
  a2 = 1;
  b2 = 2;
  printf("Epsylone = %e\n", Epsylone());
  printf("Please, inter the number of parts of the segment: ");
  scanf("%d",&k);
  eps = Epsylone() * pow(10, k);
  printf ("Your function 1: tg(x/2)-ctg(x/2)+x \n");
  printf ("Your function 2: 0,4+arctg(x^(1/2))-x \n");
  if (iteration_check(d_F14,a1,b1)==1)
	  printf ("Sorry, but you cannot use method of iterations to your First function and I print @0.0000@ at table :c \n");
  printf ("Table:\n");
     printf ("————————————————————————————————————————————————————————————————————————————————\n");
  printf ("| Function | Dihotomy method | Iteration method | Newton method |\n");
  printf ("————————————————————————————————————————————————————————————————————————————————\n");
  printf ("| tg(x/2)-ctg(x/2)+x    | %.4lf | %.4lf | %.4lf |\n", diho(a1, b1,F14), iteration(XF14,d_F14,a1,b1,eps), NewTone(F14,d_F14,a1,b1,eps));
  printf ("| 0,4+arctg(x^(1/2))-x  | %.4lf | %.4lf | %.4lf |\n", diho(a2, b2, F15),iteration(XF15,d_F15,a2,b2,eps), NewTone(F15,d_F15,a2,b2,eps));
    printf ("————————————————————————————————————————————————————————————————————————————————\n");
  printf ("\n");
  return 0;
}

