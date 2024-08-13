#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b;
	scanf("%d %d", &a,&b);
	int d=a%b; //в случае отрицательного a он и остаток отрицательный пишет
	if (a%b==0){
		printf("%d %d %d %d", a/b, a/b, a/b, 0);
	} else if (a>0){
		printf("%d %d %d %d", (a-d)/b, (a+b-d)/b, (a-d)/b, d);
	} else{
		printf("%d %d %d %d", (a-b-d)/b, (a-d)/b, (a-d)/b, b+d);
	}
	return 0;
}

