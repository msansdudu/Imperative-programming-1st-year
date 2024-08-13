#include <stdio.h>
#include <stdlib.h>


typedef struct List{
    char value[100010];
    struct List *next;
    int id;
    int len;
} List;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, t, k = 0, id, count;
	char c;
	List *head = (List*) malloc(sizeof(List)), *tmp, *last = (List*) malloc(sizeof(List)), *p;
	head->next = NULL;
	last->next = head;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &t);
		if (t == 0){
			tmp = (List*) malloc(sizeof(List));
			scanf("%d %s", &tmp->len, tmp->value);
			tmp->next = NULL;
			tmp->id = k;
			k++;
			if (head == last->next){
				head = tmp;
				last = head;
			}
			else {
				last->next = tmp;
				last = tmp;
			}
		}
		else if (t == 1){
			scanf("%d", &id);
			if (head->id == id){
				p = (List*) malloc(sizeof(List));
				p = head;
				head = head->next;
				if (head->next == NULL){
					last = head;
				}
				free(p);
			}
			else {
				tmp = (List*) malloc(sizeof(List));
				tmp = head;
				while ((tmp->next)->id != id){
					tmp = tmp->next;
				}
				p = (List*) malloc(sizeof(List));
				p = tmp->next;
				tmp->next = p->next;
				free(p);
				if (tmp->next == NULL){
					last = tmp;
				}
			}
		}
		else if (t == 2){
			scanf("%d", &id);
			tmp = (List*) malloc(sizeof(List));
			tmp = head;
			while (tmp->id != id){
				tmp = tmp->next;
			}
			printf("%s\n", tmp->value);
		}
		else {
			count = 0;
			scanf("%d %c", &id, &c);
			tmp = (List*) malloc(sizeof(List));
			tmp = head;
			while (tmp->id != id){
				tmp = tmp->next;
			}
			for (int j = 0; j < tmp->len; j++){
				if (tmp->value[j] == c){
					count++;
				}
			}
			printf("%d\n", count);
		}
	}
	while (head != last){
		tmp = (List*) malloc(sizeof(List));
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(last);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

