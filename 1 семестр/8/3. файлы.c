#include <stdio.h>
#include <stdint.h>
#include <string.h>


typedef struct files{
	char name[21];
	int64_t size;
	int8_t isdirectory;
	int64_t c, m;
	int8_t ishide;
} files;


void sort(files *arr, int32_t n){
	files tmp;
	int f;
	for (int i = n - 1; i >= 0; i--){
		f = 1;
		for (int j = 0; j < i; j++){
			if (strcmp(arr[j].name, arr[j + 1].name) > 0){
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				f = 0;
			}
		}
		if (f){
			break;
		}
	}
}


int main()
{
	files arr[1010], cur;
	FILE *in = fopen("input.txt", "rb"), *out = fopen("output.txt", "wb");
	int32_t n, count = 0;
	int64_t a, b;
	fread(&n, sizeof(int32_t), 1, in);
	fread(&a, sizeof(int64_t), 1, in);
	fread(&b, sizeof(int64_t), 1, in);
	for (int i = 0; i < n; i++){
		fread(&cur.name, sizeof(char) * 21, 1, in);
		fread(&cur.size, sizeof(int64_t), 1, in);
		fread(&cur.isdirectory, sizeof(int8_t), 1, in);
		fread(&cur.c, sizeof(int64_t), 1, in);
		fread(&cur.m, sizeof(int64_t), 1, in);
		fread(&cur.ishide, sizeof(int8_t), 1, in);
		if ((!cur.isdirectory) && (!cur.ishide) && (cur.c >= a) && (cur.m <= b)){
			arr[count] = cur;
			count++;
		}
	}
	sort(arr, count);
	for (int i = 0; i < count; i++){
		fwrite(&arr[i].name, sizeof(char) * 21, 1, out);
		fwrite(&arr[i].size, sizeof(int64_t), 1, out);
		fwrite(&arr[i].isdirectory, sizeof(int8_t), 1, out);
		fwrite(&arr[i].c, sizeof(int64_t), 1, out);
		fwrite(&arr[i].m, sizeof(int64_t), 1, out);
		fwrite(&arr[i].ishide, sizeof(int8_t), 1, out);
	}
	fclose(in);
	fclose(out);
	return 0;
}

