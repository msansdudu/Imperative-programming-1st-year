#include <stdio.h>


int fix(char s[], char s1[], int n)
{
	for (int i = 0; i < n; i++){
		if s[i] > s1[i]
			break;
		if s1[i] > s[i]
			return 1;
	}
	
	if (i == n - 1){		// если полностью совпали -- меняем последние два символа
		s1[i - 1] = s[i];
		s1[i] = s[i - 1];
	}
	else {
		int k = i;
		while (s[i] > s1[k])
			k++;
		
	}
	return 0;
}


int main()
{
	char s[27], s1[27];
	int n;
	scanf("%d\n", &n);
	
	scanf("%c", &s[0]);
	s1[0] = s[0];
	for (int i = 1; i < n; i++){
		scanf(" %c", &s[i]);
		s1[i] = s[i];
	}
	
	int tmp, f;
	for (int i = n - 1; i >= 0; i--){	// создаем список отсортированный по алфавиту (из задачи 7)
		f = 1;
		for (int j = 0; j < i; j++){
			if (s1[j] > s1[j + 1]){
				tmp = s1[j];
				s1[j] = s1[j + 1];
				s1[j + 1] = tmp;
				f = 0;
			}
		}
		if (f) break;
	}
	
	int r = 0;
	while (!r)
		if (fix(s, s1, n))
			r = 1;
	return 0;
}

