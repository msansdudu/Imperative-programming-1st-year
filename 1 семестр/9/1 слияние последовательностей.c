#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int merge(const int *a, int ak, const int *b, int bk, int *res){
	int acur = 0, bcur = 0, rk = 0;
	while (acur != ak && bcur != bk){
		if (a[acur] < b[bcur]){
			res[rk] = a[acur];
			acur++;
		}
		else {
			res[rk] = b[bcur];
			bcur++;
		}
		rk++;
	}
	if (acur == ak){
		while (bcur != bk){
			res[rk] = b[bcur];
			bcur++;
			rk++;
		}
	}
	else {
		while (acur != ak){
			res[rk] = a[acur];
			acur++;
			rk++;
		}
	}
	return rk;
}


int main()
{
	FILE *in = fopen("input.txt", "rb"), *out = fopen("output.txt", "wb");
	int n, m, rk, *a, *b, *res;
	fread(&n, sizeof(int), 1, in);
	fread(&m, sizeof(int), 1, in);
	a = (int*)malloc(sizeof(int) * n);
	b = (int*)malloc(sizeof(int) * m);
	res = (int*)malloc(sizeof(int) * (n + m));
	for (int i = 0; i < n; i++){
		fread(&a[i], sizeof(int), 1, in);
	}
	for (int i = 0; i < m; i++){
		fread(&b[i], sizeof(int), 1, in);
	}
	rk = merge(a, n, b, m, res);
	for (int i = 0; i < rk; i++){
		fwrite(&res[i], sizeof(int), 1, out);
	}
	fclose(in);
	fclose(out);
	return 0;
}

