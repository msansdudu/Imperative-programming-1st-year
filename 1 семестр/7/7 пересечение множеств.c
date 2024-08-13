#include <stdio.h>
#include <stdint.h>

int main()
{
	int n, count = 0;
	uint64_t arr[30010];
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%llx", &arr[i]);
	}
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (!(arr[i] & arr[j])){
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}

