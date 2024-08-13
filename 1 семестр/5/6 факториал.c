#include <stdio.h>


typedef struct LongNum_s{
	int len;
	int arr[3000];
} LongNum;


LongNum lmn(LongNum a, int b){
	int f = 0;
	LongNum res;
	res.len = 0;
	for (int i = 0; i < a.len; i++){
		res.arr[i] = (a.arr[i] * b + f) % 10;
		f = (a.arr[i] * b + f) / 10;
		res.len++;
	}
	while (f > 0){
		res.arr[res.len] = f % 10;
		f = f / 10;
		res.len++;
	}
	return res;
}


int main()
{
	int n;
	LongNum res;
	res.len = 1;
	res.arr[0] = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		res = lmn(res, i);
	}
	for (int i = 0; i < res.len; i++){
		printf("%d", res.arr[res.len - 1 - i]);
	}
	return 0;
}

