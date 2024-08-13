#include <stdio.h>
#include <string.h>


typedef struct LongNum_s{
	int len;
	int sign;			// 1 -- отрицательное; 0 -- положительное
	int arr[201];
} LongNum;


int max(LongNum a, LongNum b){
    if (a.len < b.len){
		return 2;
	}
	else {
		return 1;
	}
			
    for (int i = 0; i < a.len; i++) {
        if (a.arr[i] > b.arr[i]){
			return 1;
		}
		if (a.arr[i] < b.arr[i]){
			return 2;
		}
    }
    return 1;
}


LongNum lsub(LongNum a1, LongNum b1){
	LongNum a, b, res;
	res.len = 0;
	res.sign = 0;
	if (max(a1, b1) == 2){
		b = a1;
		a = b1;
		res.sign = 1;
	}
	for (int i = 0; i < b.len; i++){
		if (a.arr[i] >= b.arr[i]){
			res.arr[i] = a.arr[i] - b.arr[i];
		}
		else {
			a.arr[i + 1] -= 1;
			if (a.arr[i + 1] == 0){
				a.len--;
			}
			a.arr[i] += 10;
			res.arr[i] = a.arr[i] - b.arr[i];
		}
		res.len++;
		printf("%d\n", res.arr[i]);
	}
	for (int i = res.len; i < a.len; i++){
		res.arr[res.len] = a.arr[res.len];
		res.len++;
	}
	while (res.arr[res.len - 1] == 0){
		res.len--;
	}
	return res;
}


LongNum lsum(LongNum a, LongNum b){
	LongNum c;
	c.sign = a.sign;
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


LongNum lmn(LongNum a, LongNum b){
	LongNum res;
	if (a.sign == b.sign){
		res.sign = 0;
	}
	else {
		res.sign = 1;
	}
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
	int n, t, a, b;
	char s[101];
	LongNum arr[1000], a1, b1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d ", &t);
		
		if (t == 0){
			gets(s);
			if (s[0] == '-'){
				arr[i].len = strlen(s) - 1;
				arr[i].sign = 1;
				for (int j = 0; j < arr[i].len; j++){
					arr[i].arr[j] = s[arr[i].len - j] - '0';
				}
			}
			else {
				arr[i].len = strlen(s);
				arr[i].sign = 0;
				for (int j = 0; j < arr[i].len; j++){
					arr[i].arr[j] = s[arr[i].len - 1 - j] - '0';
				}
			}
		}
		
		
		else {
			scanf("%d%d", &a, &b);
			a1 = arr[a];
			b1 = arr[b];
			
			
			if (t == 1){
				if (a1.sign == b1.sign){
					arr[i] = lsum(a1, b1);
				}
				else {
					if (a1.sign == 1){
						arr[i] = lsub(b1, a1);
					}
					else {
						arr[i] = lsub(a1, b1);
					}
				}
			}
			
			
			
			else if (t == 2){
				if (a1.sign == b1.sign){
					if (a1.sign == 1){
						arr[i] = lsub(b1, a1);
					}
					else {
						arr[i] = lsub(a1, b1);
					}
				}
				else {
					arr[i] = lsum(a1, b1);
				}
			}
			
			
			
			else {
				arr[i] = lmn(a1, b1);
			}
		}
	}
	
	
	
	
	for (int j = 0; j < n; j++){
		if (arr[j].sign){
			printf("-");
		}
		for (int i = 0; i < arr[j].len; i++){
			printf("%d", arr[j].arr[arr[j].len - 1 - i]);
		}
		printf("\n");
	}

	return 0;
}

