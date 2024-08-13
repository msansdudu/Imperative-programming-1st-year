#include <stdio.h>
#include <stdlib.h>


void merge(int *arr, int l, int r){
	int mid = (l + r) / 2, i = l, j = mid + 1, k = 0;
	int *tmp = (int*)malloc(sizeof(int) * (r - l + 1));
	while (i <= mid && j <= r){
		if (arr[i] < arr[j]){
			tmp[k] = arr[i];
			i++;
		}
		else {
			tmp[k] = arr[j];
			j++;
		}
		k++;
	}
	while (i <= mid){ // остатки первого
		tmp[k] = arr[i];
		k++;
		i++;
	}
	while (j <= r){ // остатки второго
		tmp[k] = arr[j];
		k++;
		j++;
	}
	for (int i = l; i <= r; i++){
		arr[i] = tmp[i - l];
	}
	free(tmp);
}


void mergesort(int *arr, int l, int r){
	int mid;
	if (l < r){
		mid = (l + r) / 2;
		mergesort(arr, l, mid); // слева
		mergesort(arr, mid + 1, r); // справа
		merge(arr, l, r); // слияние
	}
}


int main()
{
	FILE *in = fopen("input.txt", "rb"), *out = fopen("output.txt", "wb");
	int n, *arr;
	fread(&n, sizeof(int), 1, in);
	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++){
		fread(&arr[i], sizeof(int), 1, in);
	}
	mergesort(arr, 0, n - 1);
	for (int i = 0; i < n; i++){
		fwrite(&arr[i], sizeof(int), 1, out);
	}
	fclose(in);
	fclose(out);
	return 0;
}

