#include <stdio.h>

int vis(int n){
	if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) return 1;
	return 0;
}

int main()
{
	int d, m, y, k;
	int kol[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	scanf("%d%d%d%d", &d, &m, &y, &k);
	while (k >= 365){
		if ((m <= 2 && vis(y)) || (m > 2 && vis(y + 1))){ // если за год нам придется пройти 29 февраля (попадем в февраль или выйдем из февраля високосного года)
			k -= 365;
			y++;
			if (d == 1){
				if (m == 1){ // если мы в 1 января
					y--;
					m = 12;
					d = 31;
				} else if (m == 3){ // если первое марта и попадаем в високосный год
					m--;
					d = 29;
				} else {
					m--;
					d = kol[m];
				}
			} else d--;
		} else {
			k -= 365;
			y++;
		}
	}
	
	
	int days[13] = {0};
	days[1] = 31;
	if (vis(y)){
		days[2] = 29 + days[1];
		for (int i = 3; i <= 12; i++) days[i] = kol[i] + days[i - 1];
	} else for (int i = 2; i <= 12; i++) days[i] = kol[i] + days[i - 1];
	
	
	int day_in_y = days[m - 1] + d; // смотрим какой это день сквозной нумерацией в году
	
	
	if (days[12] - day_in_y < k){
		y++;
		k -= days[12] - day_in_y;
		d = k;
		if (vis(y)){
			days[2] = 29 + days[1];
			for (int i = 3; i <= 12; i++) days[i] = kol[i] + days[i - 1];
		} else for (int i = 2; i <= 12; i++) days[i] = kol[i] + days[i - 1];
	} else d = day_in_y + k;
	
	
	int i = 0;
	while (days[i + 1] < d) i++;
	d -= days[i];
	m = i + 1;
	
	
	printf("%d %d %d", d, m, y);		
	return 0;
}

