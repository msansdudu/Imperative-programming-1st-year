#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void heapify(int *arr, int n, int i)
{
	int largest = i, l = 2 * i + 1, r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest]){
		largest = l;
	}
	if (r < n && arr[r] > arr[largest]){
		largest = r;
	}
	if (largest != i)
    {
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}


void heapSort(int *arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--){
		heapify(arr, n, i);
	}
	for (int i = n - 1; i >= 0; i--){
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}


int main(){
	FILE *in = fopen("input.bin", "rb"), *out = fopen("output.bin", "wb");
	int n, *a;
	fread(&n, sizeof(int), 1, in);
	a = (int*) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++){
		fread(&a[i], sizeof(int), 1, in);
	}
	heapSort(a, n);
	for (int i = 0; i < n; i++){
		fwrite(&a[i], sizeof(int), 1, out);
	}
	free(a);
	fclose(in);
	fclose(out);
	return 0;
}
