#include <stdio.h>
#include <stdlib.h>


typedef struct Dict{
	int key;
	char value[8];
} dict;


typedef struct Buf{
	dict *arr;
	int cnt;
	int cap;
} buf;


void new(buf *a, dict elem){
	if (a->cap <= a->cnt){
		a->cap *= 2;
		a->arr = realloc(a->arr, a->cap * sizeof(buf));
	}
	a->arr[(a->cnt)++] = elem;
}


int main()
{
	buf a[1000010];
	for (int i = 0; i < 1000010; i++){
		a[i].cnt = 0;
		a[i].cap = 1;
		a[i].arr = (dict*) malloc(sizeof(dict));
	}
	
	int n;
	scanf("%d", &n);
	dict elem;
	for (int i = 0; i < n; i++){
		scanf("%d%s", &elem.key, elem.value);
		new(&a[elem.key], elem);
	}
	for (int i = 0; i < 1000010; i++){
		for (int j = 0; j < a[i].cnt; j++){
			printf("%d %s\n", (a[i].arr)[j].key, (a[i].arr)[j].value);
		}
	}
	return 0;
}

