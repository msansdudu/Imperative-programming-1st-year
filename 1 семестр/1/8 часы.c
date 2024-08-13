#include <stdio.h>

int main()
{
	int h,m,s,k;
	scanf("%d%d%d%d",&h,&m,&s,&k);
	int sum=h*3600+m*60+s+k;
	h=(sum/3600)%24;
	sum=sum%3600;
	m=sum/60;
	s=sum%60;
	printf("%d %d %d", h,m,s);
	return 0;
}

