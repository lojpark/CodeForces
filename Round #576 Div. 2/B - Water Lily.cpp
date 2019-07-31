#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
	double h, l;
	scanf("%lf%lf", &h, &l);

	printf("%.10lf", ((l * l) - (h * h)) / (2 * h));

	return 0;
}