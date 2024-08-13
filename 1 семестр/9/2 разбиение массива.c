#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int n, int pivot){
	int k = 0, i = 0, j = n - 1, tmp, lp = 0, rp = 0;
	while (i <= j){
		while(arr[i] <= pivot){
			i++;
			k++;
			if (arr[i] == pivot){
				lp++;
			}
			if (lp - rp > 1){
				break;
			}
		}
		while (arr[j] >= pivot){
			j--;
			if (arr[j] == pivot){
				rp++;
			}
			if (rp - lp > 1){
				break;
			}
		}
		if (i <= j){
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
			k++;
			if (rp - lp > 1){
				rp--;
				lp++;
			}
			if (lp - rp > 1){
				rp++;
				lp--;
			}
		}
	}
	return k;
}


int main()
{
	FILE *in = fopen("input.txt", "rb"), *out = fopen("output.txt", "wb");
	int n, p, *arr, k;
	fread(&n, sizeof(int), 1, in);
	fread(&p, sizeof(int), 1, in);
	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++){
		fread(&arr[i], sizeof(int), 1, in);
	}
	k = partition(arr, n, p);
	fwrite(&k, sizeof(int), 1, out);
	for (int i = 0; i < n; i++){
		fwrite(&arr[i], sizeof(int), 1, out);
	}
	fclose(in);
	fclose(out);
	return 0;
}

