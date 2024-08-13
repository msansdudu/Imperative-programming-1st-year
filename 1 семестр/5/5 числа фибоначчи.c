#include <stdio.h>


typedef struct LongNum_s{
	int len;
	int arr[500];
} LongNum;


LongNum lsum(LongNum a, LongNum b){
	LongNum c;
	int f = 0, i;
	c.len = b.len;
	for (i = 0; i < a.len; i++){
		c.arr[i] = (a.arr[i] + b.arr[i] + f) % 10;
		if (a.arr[i] + b.arr[i] + f > 9){
			f = 1;
		}
		else {
			f = 0;
		}
	}
	for (i = a.len; i < b.len; i++){
		c.arr[i] = (b.arr[i] + f) % 10;
		if (b.arr[i] + f > 9){
			f = 1;
		}
		else {
			f = 0;
		}
	}
	if (f){
		c.arr[c.len] = 1;
		c.len++;
	}
	return c;
}


void pl(LongNum c, int *c1){
	for (int i = 0; i < c.len; i++){
		c1[c.len - 1 - i] = c.arr[i];
	}
}


int main()
{
	LongNum a, b, c;
	int n, c1[500] = {0};
	a.len = 1;
	a.arr[0] = 1;
	b.len = 1;
	b.arr[0] = 1;
	scanf("%d", &n);
	if (n == 1 || n == 2){
		printf("1");
		return 0;
	}
	for (int i = 0; i < n - 2; i++){
		c = lsum(a, b);
		a = b;
		b = c;
	}
	pl(c, c1);
	for (int i = 0; i < c.len; i++){
		printf("%d", c1[i]);
	}
	return 0;
}
