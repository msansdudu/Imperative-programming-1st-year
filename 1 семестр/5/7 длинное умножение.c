#include <stdio.h>
#include <string.h>


typedef struct LongNum_s{
	int len;
	int arr[2010];
} LongNum;


LongNum lmn(LongNum a, LongNum b){
	LongNum res;
	res.len = a.len + b.len + 1;
	
	for (int i = 0; i < res.len; i++){
        res.arr[i] = 0;
	}
	
	for (int i = 0; i < a.len; i++){
        for (int j = 0; j < b.len; j++){
            res.arr[i + j] += a.arr[i] * b.arr[j];
		}
	}
	res.arr[res.len] = 0;
    for (int i = 0; i < res.len - 1; i++){
        res.arr[i + 1] += res.arr[i] / 10;
        res.arr[i] %= 10;
	}
    while (res.arr[res.len - 1] == 0){
		res.len--;
	}
	return res;
}


int main()
{
	LongNum a, b, c;
	char a1[1010], b1[1010];
	gets(a1);
	gets(b1);
	a.len = strlen(a1);
	b.len = strlen(b1);
	
	for (int i = 0; i < a.len; i++){
		a.arr[i] = a1[a.len - 1 - i] - '0';
	}
	for (int i = 0; i < b.len; i++){
		b.arr[i] = b1[b.len - 1 - i] - '0';
	}
	
	c = lmn(a, b);
	for (int i = 0; i < c.len; i++){
		printf("%d", c.arr[c.len - 1 - i]);
	}
	return 0;
}

