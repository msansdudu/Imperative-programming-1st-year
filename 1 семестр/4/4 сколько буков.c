#include <stdio.h>

int calcLetters (char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt){
	int i = 0;
	*oLowerCnt = 0;
	*oUpperCnt = 0;
	*oDigitsCnt = 0;
	while (iStr[i] != '\n' && iStr[i] != '\0'){
		if (iStr[i] >= '0' && iStr[i] <= '9'){
			*oDigitsCnt += 1;
		} else if (iStr[i] >= 'a' && iStr[i] <= 'z'){
			*oLowerCnt += 1;
		} else if (iStr[i] >= 'A' && iStr[i] <= 'Z'){
			*oUpperCnt += 1;
		}
		i++;
	}
	return i;
}

int main()
{
	//FILE *f = fopen("in.txt", "r");
	int len, oLowerCnt, oUpperCnt, oDigitsCnt, j = 0;
	char c[110];
	while (gets(c) != NULL){
		j++;
		len = calcLetters(c, &oLowerCnt, &oUpperCnt, &oDigitsCnt);
		printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", j, len, oLowerCnt + oUpperCnt, oLowerCnt, oUpperCnt, oDigitsCnt);
	}
	return 0;
}

