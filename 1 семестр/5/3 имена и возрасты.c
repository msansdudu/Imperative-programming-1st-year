#include <stdio.h>
#include <string.h>


typedef struct Label_s {
	char name[16];
	int age;
} Label;


typedef struct NameStats_s {
	int cntTotal;
	int cntLong;
} NameStats;


typedef struct AgeStats_s {
	int cntTotal;
	int cntAdults;
	int cntKids;
} AgeStats;


void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges)
{
	for (int i = 0; i < cnt; i++){
		(*oNames).cntTotal += 1;
		if (strlen(arr[i].name) > 10){
			(*oNames).cntLong += 1;
		}
		(*oAges).cntTotal += 1;
		if (arr[i].age >= 18){
			(*oAges).cntAdults += 1;
		}
		else if (arr[i].age < 14){
			(*oAges).cntKids += 1;
		}
	}
}


int main()
{
	int n;
	Label arr[1000];
	NameStats oNames;
	AgeStats oAges;
	char s[6000];
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++){
		gets(s);
		sscanf(s, "%s %d let\n", arr[i].name, &arr[i].age);
	}
	calcStats(arr, n, &oNames, &oAges);
	printf("names: total = %d\n", oNames.cntTotal);
	printf("names: long = %d\n", oNames.cntLong);
	printf("ages: total = %d\n", oAges.cntTotal);
	printf("ages: adult = %d\n", oAges.cntAdults);
	printf("ages: kid = %d", oAges.cntKids);
	return 0;
}

