#include <stdio.h>


int main()
{
	freopen("output.txt", "w", stdout);
	int n, q, x, l, r, id;
	int arr[200010];
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		scanf("%d", &x);
		l = 0;
		r = n - 1;
		while (l + 1 < r){
			id = (l + r) / 2;
			if (arr[id] > x){
				r = id;
			}
			else {
				l = id;
			}
		}
		if (abs(arr[l] - x) < abs(arr[r] - x)){
			printf("%d %d\n", l, abs(arr[l] - x));
		}
		else {
			printf("%d %d\n", r, abs(arr[r] - x));
		}
	}
	fclose(stdout);
	return 0;
}
