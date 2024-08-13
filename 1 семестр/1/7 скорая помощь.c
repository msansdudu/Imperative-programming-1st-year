#include <stdio.h>

int main()
{
	int n,m,p,k,l;
	scanf("%d%d%d%d%d",&n,&m,&p,&k,&l);
	
	int kv_on_fl = (m-(m%(l*(p-1)+k-1)))/(l*(p-1)+k-1), //делим нацело номер квартиры m на количество этажей в том числе во всех подъездах до этого
	kv_in_p = kv_on_fl*l; //квартир в подъезде = кол-во на этаже * кол-во этажей
	if (n%kv_in_p == 0){ //номер кв делится на кол-во кв в подъезде, значит кв на последнем этаже
		printf("%d %d", n/kv_in_p, l);
	} else if (n%kv_on_fl==0){
		printf("%d %d", (n-n%kv_in_p)/kv_in_p+1, (n%kv_in_p)/kv_on_fl);
	} else{
		printf("%d %d", (n-n%kv_in_p)/kv_in_p+1, (n%kv_in_p-n%kv_on_fl)/kv_on_fl+1);
	}
	return 0;
}

