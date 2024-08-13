#include <stdio.h>

int main()
{
	int n, sum, sum1, l = 0, r = 0, l1 = 0, r1 = 0, curr, f = 0; // f проверяет, были ли вообще числа >=0
	scanf("%d", &n);
	
	scanf("%d", &sum);
	sum1 = sum;
	
	for (int i = 1; i < n; i++){
		scanf("%d", &curr);
		if (curr > 0){
			sum1 += curr;
			r1 = i;
			f = 1;
		}
		else if (curr == 0)
			f = 1;
		else {
			if (sum1 > sum && f == 1){
				r = r1;
				l = l1;
				sum = sum1;
			}
			else if (curr > sum){
				sum = curr;
				r = r1;
				l = l1;
			}
			sum1 = 0;
			l1 = i + 1;
			r1 = i + 1;
		}
	}
	
	if (sum1 > sum && f == 1){
		r = r1;
		l = l1;
		sum = sum1;
	}
	printf("%d %d %d", l, r, sum);
	return 0;
}


/*10
5967 7012 -1721 7213 -4715 8124 1788 5511 1732 6741*/
