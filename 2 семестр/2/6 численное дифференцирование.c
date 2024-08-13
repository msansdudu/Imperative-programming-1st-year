#include <stdio.h>
#include <stdlib.h>

double Function(double x);

double der(double x){
	if (1 - x < 0.0000001){
		return (Function(x - 0.0000001) - Function(x)) / (-0.0000001);
	}
	return (Function(x + 0.0000001) - Function(x)) / 0.0000001;
}

int main(int argc, char **argv)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m;
	double x;
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%lf", &x);
		printf("%lf\n", der(x));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

