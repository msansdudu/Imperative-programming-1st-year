#include <stdio.h>

typedef struct DateTime_s
{
	int year, month, day;
	int hours, minutes, seconds;
} DateTime;


DateTime min(const DateTime *arr, int cnt)
{
	DateTime res = arr[0];
	for (int i = 1; i < cnt; i++){
		if (arr[i].year < res.year){
			res = arr[i];
		} else if (arr[i].year == res.year){
			if (arr[i].month < res.month){
				res = arr[i];
			} else if (arr[i].month == res.month){
				if (arr[i].day < res.day){
					res = arr[i];
				} else if (arr[i].day == res.day){
					if (arr[i].hours < res.hours){
						res = arr[i];
					} else if (arr[i].hours == res.hours){
						if (arr[i].minutes < res.minutes){
							res = arr[i];
						} else if (arr[i].minutes == res.minutes){
							if (arr[i].seconds < res.seconds){
								res = arr[i];
							}
						}
					}
				}
			}
		}
	}
	return res;
}

int main()
{
	int n;
	DateTime arr[50000], res;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d %d %d %d %d %d", &arr[i].year, &arr[i].month, &arr[i].day, &arr[i].hours, &arr[i].minutes, &arr[i].seconds);
	}
	res = min(arr, n);
	printf("%d %d %d %d %d %d", res.year, res.month, res.day, res.hours, res.minutes, res.seconds);
	return 0;
}

