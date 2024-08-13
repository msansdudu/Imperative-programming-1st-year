#include <stdio.h>

int main()
{
	int n, k, mn=10001, mx=-10001, nmn,nmx;
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d", &k);
		if (k<mn){
			mn=k;
			nmn=i;
		}
		if (k>mx){
			mx=k;
			nmx=i;
		}
	}
	printf("%d %d %d %d", mn,nmn,mx,nmx);
	return 0;
}

