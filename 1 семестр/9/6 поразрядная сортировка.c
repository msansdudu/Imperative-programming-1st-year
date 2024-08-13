#include <stdio.h>
#include <stdint.h>


void radix_sort(arr, n){
	
}


typedef struct elem{
	uint32_t key, value;
} elem;


int main()
{
	FILE *in = fopen("input.txt", "rb"), *out = fopen("output.txt", "wb");
	int n;
	elem *arr;
	fread(&n, sizeof(int), 1, in);
	arr = (elem*)malloc(sizeof(elem) * n);
	for (int i = 0; i < n; i++){
		fread(&arr[i].key, sizeof(uint32_t), 1, in);
		fread(&arr[i].value, sizeof(uint32_t), 1, in);
	}
	radix_sort(arr, n);
	for (int i = 0; i < n; i++){
		fwrite(&arr[i].key, sizeof(uint32_t), 1, in);
		fwrite(&arr[i].value, sizeof(uint32_t), 1, in);
	}
	fclose(in);
	fclose(out);
	return 0;
}

