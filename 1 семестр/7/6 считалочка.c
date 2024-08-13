#include <stdio.h>
#include <stdlib.h>


typedef struct List{
	int value;
	struct List *next;
} List;


int main()
{
	int k, n;
	scanf("%d%d", &n, &k);
	List *head, *p, *cur;
	if (k > n){
		k = k % n;
	}
	if (k == 0){
		k = n;
	}
	head = (List*)malloc(sizeof(List));
	head->value = 1;
	cur = head;
	for (int i = 2; i <= n; i++){
		p = (List*)malloc(sizeof(List));
		p->value = i;
		cur->next = p;
		cur = p;
	}
	cur->next = head;
	while (head->next != head) {
		for (int i = 1; i < k - 1; i++){
			head = head->next;
		}
		p = head->next;
		head->next = p->next;
		head = head->next;
		printf("%d\n", p->value);
		free(p);
	}
	printf("%d\n", head->value);
	return 0;
}

