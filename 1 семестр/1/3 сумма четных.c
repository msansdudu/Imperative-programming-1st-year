#include <stdio.h>

int main()
{
	int i,k=0,n,j;
	scanf("%d",&n);
	for (i=0; i<n; i++){
		scanf("%d", &j);
		if (j%2==0){
			k+=j;
		}
	}
	printf("%d",k);
	return 0;
}

