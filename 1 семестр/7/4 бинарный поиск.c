#include <stdio.h>


int main()
{
	freopen("output.txt", "w", stdout);
	int n, q, x, res = 0, l, r, id;
	int arr[200010];
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		scanf("%d", &x);
		x += res;
		res = -1;
		l = 0;
		r = n;
		while (l + 1 < r){
			id = (l + r) / 2;
			if (arr[id] > x){
				r = id;
			}
			else if (arr[id] < x){
				l = id;
			}
			else {
				res = id;
				if (id != n - 1 && arr[id + 1] == x){
					l = id;
				}
				else {
					break;
				}
			}
		}
		if (res == -1){
			if (arr[r] == x){
				res = r;
			}
			else if (arr[l] == x){
				res = l;
			}
		}
		printf("%d\n", res);
	}
	fclose(stdout);
	return 0;
}

