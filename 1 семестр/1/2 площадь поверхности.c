#include <stdio.h>

int main(){
	int x,y,z;
	scanf("%d %d %d", &x,&y,&z);
	if (x<=0){
		printf("-1");
	} else if (y<=0){
		printf("-2");
	} else if (z<=0){
		printf("-3");
	} else{
		printf("%d", (x*y+x*z+y*z)*2);
	}
	return 0;
}
