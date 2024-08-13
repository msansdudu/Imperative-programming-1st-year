#include <stdio.h>


typedef struct Dict{
	int key;
	char value[8];
} dict;


void sort(dict *a, int n){
	dict tmp;
	int f;
	for (int i = n - 1; i >= 0; i--){
		f = 1;
		for (int j = 0; j < i; j++){
			if (a[j].key > a[j + 1].key){
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
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
	int n;
	dict a[10001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d%s", &a[i].key, a[i].value);
	}
	sort(a, n);
	
	for (int i = 0; i < n; i++){
		printf("%d %s\n", a[i].key, a[i].value);
	}
	return 0;
}

