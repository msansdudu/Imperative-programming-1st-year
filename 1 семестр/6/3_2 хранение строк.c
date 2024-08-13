#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct List{
	int len;
	char *value;
} List;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, t, k = 0, id, count, len;
	char c;
	List arr[100010];
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &t);
		if (t == 0){
			scanf("%d", &len);
			arr[k].len = len;
			arr[k].value = (char*) malloc((len + 1) * sizeof(char));
			scanf("%s", arr[k].value);
			k++;
		}
		else if (t == 1){
			scanf("%d", &id);
			free(arr[id].value);
			arr[id].value = NULL;
			arr[id].len = 0;
		}
		else if (t == 2){
			scanf("%d", &id);
			printf("%s\n", arr[id].value);
		}
		else {
			count = 0;
			scanf("%d %c", &id, &c);
			for (int j = 0; j < arr[id].len; j++){
				if (arr[id].value[j] == c){
					count++;
				}
			}
			printf("%d\n", count);
		}
	}
	for (int i = 0; i < k; i++){
		if (arr[i].value != NULL){
			free(arr[i].value);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	return 0;
}

