#include <stdio.h>

int prost(int a){
	int i,k=0;
	for (i=1;i<=a;i++){
		if (a%i==0)k++;
	}
	return (k==2)? 1:0;
}

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	for (int i=1;i<=n;i++){
		if (prost(i))printf("%d\n",i);
	}
	return 0;
}

