#include <iostream>
#include <stdlib.h>
#include <unistd.h>

double func(double x)
{
	return (4 / (1 + x * x));
}
double integration(double a, double b, int n)
{
	double H = (b - a) / n;
	double S = (func(a) + func(b)) / 2;
	for (int i = 1; i < n; i++)
	{
		S += func(a + i * H);
	}
	return H * S;
}

int main(int argc, char *argv[])
{
	pid_t pid;
	int file_des[2], count, n, i;
	double pi_part, pi = 0, k, step, m;

	if (argc != 3)
	{
		perror("Wrong arguments");
		return -1;
	}

	count = atoi(argv[1]);
	n = atoi(argv[2]);
	step = 1.0 / n;

	if (pipe(file_des) == -1)
	{
		perror("pipe error ");
		return -1;
	}

	for (i = 0; i < count; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			pi_part = integration(i * 1.0 / count, (i + 1) * 1.0 / count, n);
			close(file_des[0]);
			write(file_des[1], &pi_part, sizeof(pi_part));
			close(file_des[1]);
			return 0;
		}
	}
	if (pid != 0)
	{
		close(file_des[1]);
		while (read(file_des[0], &m, sizeof(m)))
			pi += m;
		printf("%lf\n", pi);
		close(file_des[0]);
	}
}
