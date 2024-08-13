#include <stdio.h>
#include <stdint.h>


union int_32{
	int32_t num;
	int8_t bytes[4];
};


int32_t convert(union int_32 el){
	int8_t tmp;
	tmp = el.bytes[0];
	el.bytes[0] = el.bytes[3];
	el.bytes[3] = tmp;
	tmp = el.bytes[2];
	el.bytes[2] = el.bytes[1];
	el.bytes[1] = tmp;
	return el.num;
}


int main() {
	FILE *in = fopen("input.txt", "rb"), *out = fopen("output.txt", "wb");
	int32_t res;
	union int_32 n, elem, sum;
	sum.num = 0;
	fread(&(n.num), sizeof(int32_t), 1, in);
	if (n.num <= 10000){
		for (int i = 0; i < n.num; i++){
			fread(&(elem.num), sizeof(int32_t), 1, in);
			sum.num += elem.num;
		}
		res = sum.num;
	}
	else {
		n.num = convert(n);
		for (int i = 0; i < n.num; i++){
			fread(&(elem.num), sizeof(int32_t), 1, in);
			sum.num += convert(elem);
		}
		res = convert(sum);
	}
	fwrite(&res, sizeof(int32_t), 1, out);
	fclose(in);
	fclose(out);
	return 0;
}
