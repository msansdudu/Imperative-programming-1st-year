#include <stdio.h>
#include <stdlib.h>


void quicksort(int *arr, int n){ // справа оставим элементы больше mid, слева -- меньше
	int i = 0, j = n - 1, mid = arr[n / 2], tmp;
	while (i <= j){
		while(arr[i] < mid){
			i++;
		}
		while (arr[j] > mid){
			j--;
		}
		if (i <= j){
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	if (j > 0){
		quicksort(arr, j + 1); // слева
	}
	if (i < n){
		quicksort(&arr[i], n - i); // справа
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
	quicksort(arr, n);
	for (int i = 0; i < n; i++){
		fwrite(&arr[i], sizeof(int), 1, out);
	}
	fclose(in);
	fclose(out);
	return 0;
}

