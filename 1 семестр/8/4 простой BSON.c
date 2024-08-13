#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int main()
{
	FILE *in = fopen("input.txt", "rb");
	int32_t size, cur = 0, l, i32, step_name;
	int64_t i64;
	int8_t t, b;
	double d;
	char *name, *str;
	fread(&size, sizeof(int32_t), 1, in);
	cur += 4;
	name = (char*)malloc(sizeof(char) * size);
	
	printf("{\n");
	while (cur < size - 1){
		fread(&t, sizeof(int8_t), 1, in);
		cur++;
		step_name = 0;
		fread(&name[step_name], sizeof(char), 1, in);
		cur++;
		while (name[step_name] != 0){
			step_name++;
			fread(&name[step_name], sizeof(char), 1, in);
			cur++;
		}
		cur++;
		printf("\t\"%s\": ", name);
		switch (t){
			case 1:
				fread(&d, sizeof(double), 1, in);
				printf("%0.15g", d);
				cur += 8;
				break;
			case 2:
				fread(&l, sizeof(int32_t), 1, in);
				str = (char*)malloc(sizeof(char) * l);
				fread(str, sizeof(char) * l, 1, in);
				printf("\"%s\"", str);
				cur += l + 1;
				break;
			case 8:
				fread(&b, sizeof(int8_t), 1, in);
				if (b){
					printf("true");
				}
				else {
					printf("false");
				}
				cur++;
				break;
			case 10:
				printf("null");
				break;
			case 16:
				fread(&i32, sizeof(int32_t), 1, in);
				printf("%d", i32);
				cur += 4;
				break;
			case 18:
				fread(&i64, sizeof(int64_t), 1, in);
				printf("%lld", i64);
				cur += 8;
				break;
		}
		if (cur < size - 1){
			printf(",");
		}
		printf("\n");
	}
	printf("}");
	
	fclose(in);
	return 0;
}

