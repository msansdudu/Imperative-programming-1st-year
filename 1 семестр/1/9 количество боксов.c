#include <stdio.h>
#include <math.h>

int main()
{
	long long n, k=0;
	scanf("%lld",&n);
	for (long long x=1;x<=sqrt(n);x++){
		for (long long y=x; y<=sqrt(n/x);y++){
			if (n/(x*y)-y+1>0){
				k+=n/(x*y)-y+1;
			}
		}
	}
	printf("%lld",k);
	return 0;
}

