#include <stdio.h>


int main(int argc, char **argv)
{
	int n, q, k = 2, i, d;
	scanf("%d%d", &n, &q);
	int arr[15000001] = {1, 1};
	while (k * k <= n){
		if (!arr[k]){
			i = k * k;
			while (i <= n){
				arr[i] = 1;
				i += k;
			}
		}
		k++;
	}
	for (int i = 0; i < q; i++){
		scanf("%d", &d);
		if (arr[d]){
			printf("%d not\n", d);
		}
		else {
			printf("%d prime\n", d);
		}
	}
	return 0;
}

