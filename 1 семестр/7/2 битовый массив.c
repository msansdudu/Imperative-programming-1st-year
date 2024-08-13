#include <stdio.h>
#include <stdint.h>


typedef uint8_t bitword;


void bitsetZero(bitword *arr, int num){
	for (int i = 0; i < num / 8 + 1; i++){
		arr[i] = (arr[i] & (~arr[i]));
	}
}


int bitsetGet(const bitword *arr, int idx){
	int a;
	a = (arr[idx / 8] >> (idx % 8)) & (bitword)1;
	return a;
}


void bitsetSet(bitword *arr, int idx, int newval){
	if (newval == 1){
		arr[idx / 8] |= (bitword)1 << (idx % 8);
	}
	else {
		arr[idx / 8] &= ~((bitword)1 << (idx % 8));
	}
}


int bitsetAny(const bitword *arr, int left, int right){
	int cur;
	cur = left / 8;
	if (right - left < 8){ 
		for (int i = left; i < right; i++){ 
			if (i % 8 == 0 && i != left){ 
				cur++; 
			}
			if (bitsetGet(arr, i)){
				return 1; 
			}
		}
		return 0; 
	}
	if (left % 8 != 0){
		while (left % 8 != 0){
			if (bitsetGet(arr, left)){
				return 1;
			}
			left++;
		}
		cur++;
	}
	if (right % 8 != 0){
		while (right % 8 != 0){
			if (bitsetGet(arr, right - 1)){
				return 1;
			}
			right--;
		}
	}
	while (cur != right / 8){
		if (arr[cur]){
			return 1; 
		}
		cur++; 
	}
	return 0;
}


int main()
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	bitword arr[2500000];
	int n, t, num, idx, newval, left, right;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &t);
		if (t == 0){
			scanf("%d", &num);
			bitsetZero(arr, num);
		}
		else if (t == 1){
			scanf("%d", &idx);
			printf("%d\n", bitsetGet(arr, idx));
		}
		else if (t == 2){
			scanf("%d%d", &idx, &newval);
			bitsetSet(arr, idx, newval);
		}
		else {
			scanf("%d%d", &left, &right);
			if (bitsetAny(arr, left, right) == 1){
				printf("some\n");
			}
			else {
				printf("none\n");
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
