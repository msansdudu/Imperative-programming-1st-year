#include <stdio.h> 
 
typedef struct List{
    char value[8]; 
    int next; 
} List;


int main()
{
	List arr[200010];
	int t, n, f, q, op, id;
	scanf("%d", &t);
	for (int j = 0; j < t; j++){
		scanf("%d%d%d", &n, &f, &q);
		for (int i = 0; i < n; i++){
			scanf("%s%d", arr[i].value, &arr[i].next);
		}
		for (int i = 0; i < q; i++){
			scanf("%d%d", &op, &id);
			if (op == 1){
				if (id == -1){
					printf("%s\n", arr[f].value);
					f = arr[f].next;
				} 
				else {
					printf("%s\n", arr[arr[id].next].value);
					arr[id].next = arr[arr[id].next].next;
				}
			}
			else {
				scanf("%s", arr[n].value);
				printf("%d\n", n);
				if (id == -1){
					arr[n].next = f;
					f = n;
				}
				else {
					arr[n].next = arr[id].next;
					arr[id].next = n;
				}
				n++;
			}
		}
		printf("===\n");
		for (int i = f; i != -1; i = arr[i].next){
			printf("%s\n", arr[i].value);
		}
        printf("===\n");
    } 
    return 0; 
}

