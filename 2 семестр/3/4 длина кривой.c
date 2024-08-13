#include <stdio.h>
#include <math.h>

typedef struct cube{
	double a, b, c, d;
} cube;

typedef struct point{
	double x, y, z;
} point;


void coor(point *p, cube x, cube y, cube z, double l, double t){
	p->x = x.a + x.b * (t - l) + x.c * pow(t - l, 2) + x.d * pow(t - l, 3);
	p->y = y.a + y.b * (t - l) + y.c * pow(t - l, 2) + y.d * pow(t - l, 3);
	p->z = z.a + z.b * (t - l) + z.c * pow(t - l, 2) + z.d * pow(t - l, 3);
}


double len(cube x, cube y, cube z, double l, double r, int n){
	double res = 0, left, right;
	point a, b;
	double delta = (r - l) / (double)(5000000 / n);
	for (int i = 0; i < (5000000 / n); i++){
		left = l + i * delta;
		right = l + (i + 1) * delta;
		coor(&a, x, y, z, l, left);
		coor(&b, x, y, z, l, right);
		res += sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
	}
	return res;
}


int main()
{
	int n;
	double l, r, sum = 0;
	cube x, y, z;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%lf%lf", &l, &r);
		scanf("%lf%lf%lf%lf", &x.a, &x.b, &x.c, &x.d);
		scanf("%lf%lf%lf%lf", &y.a, &y.b, &y.c, &y.d);
		scanf("%lf%lf%lf%lf", &z.a, &z.b, &z.c, &z.d);
		sum += len(x, y, z, l, r, n);
	}
	printf("%.15lf", sum);
	return 0;
}

