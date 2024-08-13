#include <stdio.h>

typedef struct List{
	int value;
	int next, prev;
} List;


int main()
{
	List arr[200010];
	int t, n, f, l, q, op, id;
	scanf("%d", &t);
	for (int i = 0; i < t; i++){
		scanf("%d%d%d%d", &n, &f, &l, &q);
		for (int j = 0; j < n; j++){
			scanf("%d%d%d", &arr[j].value, &arr[j].next, &arr[j].prev);
		}
		for (int j = 0; j < q; j++){
			scanf("%d%d", &op, &id);
			if (op == 0){
				printf("%d\n", arr[id].value);
				if (l == f){
					l = -1;
					f = -1;
                }
                else if (l == -1 && f == -1){
					continue;
				}
				else if (id == l){
					arr[arr[id].prev].next = -1;
					l = arr[id].prev;
				}
				else if (id == f){
					arr[arr[id].next].prev = -1;
					f = arr[id].next;
				}
				else {
					arr[arr[id].prev].next = arr[id].next;
					arr[arr[id].next].prev = arr[id].prev;
				}
			}
			else {
				scanf("%d", &arr[n].value);
				if (l == -1 && f == -1){
					arr[n].next = -1;
					arr[n].prev = -1;
					f = n;
					l = n;
				}
				else if (op == 1){
					if (id == -1){
						arr[n].prev = -1;
						arr[n].next = f;
						arr[f].prev = n;
						f = n;
					}
					else if (id == l){
						arr[n].prev = l;
						arr[n].next = -1;
						arr[l].next = n;
						l = n;
					}
					else {
						arr[n].prev = id;
						arr[n].next = arr[id].next;
						arr[id].next = n;
						arr[arr[n].next].prev = n;
					}
				}
				else {
					if (id == -1){
						arr[n].next = -1;
						arr[n].prev = l;
						arr[l].next = n;
						l = n;
					}
					else if (id == f){
						arr[f].prev = n;
						arr[n].next = f;
						arr[n].prev = -1;
						f = n;
					}
					else {
						arr[n].next = id;
						arr[n].prev = arr[id].prev;
						arr[id].prev = n;
						arr[arr[n].prev].next = n;
					}
				}
				printf("%d\n", n);
				n++;
			}
		}
		printf("===\n");
		for (int i = f; i != -1; i = arr[i].next){
			printf("%d\n", arr[i].value);
		}
		printf("===\n");
	}
	return 0;
}

