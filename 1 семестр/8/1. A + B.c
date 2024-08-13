#include <stdio.h>
#include <stdint.h>


int main() {
	FILE *in = fopen("input.txt", "rb"), *out = fopen("output.txt", "wb");
	int32_t a, b, c1;
	long long c, a1, b1;
	fread(&a, sizeof(int32_t), 1, in);
	fread(&b, sizeof(int32_t), 1, in);
	a1 = (long long)a;
	b1 = (long long)b;
	c = ((a1 + b1) >> 1);
	c1 = (int32_t)c;
	fwrite(&c1, sizeof(int32_t), 1, out);
	fclose(in);
	fclose(out);
	return 0;
}
