#include <stdio.h>

int main()
{
	int n, t;
	char ed[10][20] = {"", "odna", "dve", "tri", "chetyre", "pyat'", "shest'", "sem'", "vosem'", "devyat'"};
	char edm[10][20] = {"", "odin", "dva", "tri", "chetyre", "pyat'", "shest'", "sem'", "vosem'", "devyat'"};
	char des1[10][20] = {"desyat'", "odinnadtsat'", "dvenadtsat'", "trinadtsat'", "chetyrnadtsat'", "pyatnadtsat'", "shestnadtsat'", "semnadtsat'", "vosemnadtsat'", "devyatnadtsat'"};
	char des2[9][20] = {"", "dvadtsat'", "tridtsat'", "sorok", "pyat'desyat", "shest'desyat", "sem'desyat", "vosem'desyat", "devyanosto"};
	char sot[10][20]={"", "sto", "dvesti", "trista", "chetyresta", "pyat'sot", "shest'sot", "sem'sot", "vosem'sot", "devyat'sot"};
	int mil, tys, edin;
	scanf("%d", &t);
	
	for (int i = 0; i < t; i++){
		scanf("%d", &n);
		mil = n / 1000000;
		tys = (n / 1000) % 1000;
		edin = n % 1000;
		if (mil / 100 > 0){
			printf("%s ", sot[mil / 100]);
		}
		if (mil % 100 < 20 && mil % 100 > 9){
			printf("%s ", des1[mil % 10]);
		}
		else if ((mil % 100) / 10 > 0){
			printf("%s ", des2[(mil % 100) / 10 - 1]);
			if (mil % 10 > 0){
				printf("%s ", edm[mil % 10]);
			}
		}
		else if (mil % 10 > 0){
			printf("%s ", edm[mil % 10]);
		}
		if ((mil > 0 && (mil % 10 == 0 || mil % 10 > 4)) || (mil % 100 < 20 && mil % 100 > 9)){
			printf("millionov ");
		}
		else if (mil % 10 == 1){
			printf("million ");
		}
		else if (mil > 0){
			printf("milliona ");
		}
	
	
		
		if (tys / 100 > 0){
			printf("%s ", sot[tys / 100]);
		}
		if (tys % 100 < 20 && tys % 100 > 9){
			printf("%s ", des1[tys % 10]);
		}
		else if ((tys % 100) / 10 > 0){
			printf("%s ", des2[(tys % 100) / 10 - 1]);
			if (tys % 10 > 0){
				printf("%s ", ed[tys % 10]);
			}
		}
		else if (tys % 10 > 0){
			printf("%s ", ed[tys % 10]);
		}
		if ((tys > 0 && (tys % 10 == 0 || tys % 10 > 4)) || (tys % 100 < 20 && tys % 100 > 9)){
			printf("tysyach ");
		}
		else if (tys % 10 == 1){
			printf("tysyacha ");
		}
		else if (tys > 0){
			printf("tysyachi ");
		}
	
	
		
		if (edin / 100 > 0){
			printf("%s ", sot[edin / 100]);
		}
		if (edin % 100 < 20 && edin % 100 > 9){
			printf("%s ", des1[edin % 10]);
		}
		else if ((edin % 100) / 10 > 0){
			printf("%s ", des2[(edin % 100) / 10 - 1]);
			if (edin % 10 > 0){
				printf("%s ", ed[edin % 10]);
			}
		}
		else if (edin % 10 > 0){
			printf("%s ", ed[edin % 10]);
		}
	
	
	
		if ((n % 10 == 0 || n % 10 > 4) || (edin % 100 < 20 && edin % 100 > 9)){
			printf("strok");
		}
		else if (n % 10 == 1){
			printf("stroka");
		}
		else {
			printf("stroki");
		}
		printf("\n");
	}
	return 0;
}

