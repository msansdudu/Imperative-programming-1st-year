#include <stdio.h>

int main()
{
	int a1, a2, b1, b2, c1, c2, a, b, c, d, e, f, g, h;
	scanf("%d %d %d %d %d %d", &a1, &a2, &b1, &b2, &c1, &c2);
	a = (b1 + c1 <= a1) && ((b2 > c2? b2:c2) <= a2);
	b = (b2 + c2 <= a1) && ((b1 > c1? b1:c1) <= a2);
	c = (b2 + c1 <= a1) && ((b1 > c2? b1:c2) <= a2);
	d = (b1 + c2 <= a1) && ((b2 > c1? b2:c1) <= a2);
	e = (b1 + c1 <= a2) && ((b2 > c2? b2:c2) <= a1);
	f = (b2 + c2 <= a2) && ((b1 > c1? b1:c1) <= a1);
	g = (b2 + c1 <= a2) && ((b1 > c2? b1:c2) <= a1);
	h = (b1 + c2 <= a2) && ((b2 > c1? b2:c1) <= a1);
	if (a || b || c || d || e || f || g || h) printf("YES");
	else printf("NO");
	return 0;
}

