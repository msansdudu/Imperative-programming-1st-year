#include <stdio.h>
#include <string.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char c, arr[50][101] = {{'\0'}};
	int space = 1, quote = 0, cur = 0, curcur = 0;
	while (scanf("%c", &c) != EOF){
		if (c == ' '){
			if (!space && !quote){
				space++;
				arr[cur][curcur] = '\0';
				cur++;
				curcur = 0;
			}
			else if (quote){
				arr[cur][curcur] = c;
				curcur++;
			}
		}
		else if (c == '"'){
			if (quote){
				quote = 0;
				space = 1;
				arr[cur][curcur] = '\0';
				cur++;
				curcur = 0;
			}
			else {
				quote++;
			}
		}
		else if (c == '\n'){
			break;
		}
		else {
			space = 0;
			arr[cur][curcur] = c;
			curcur++;
		}
	}
	if (arr[cur][0] == '\0'){
		cur--;
	}
	for (int i = 0; i <= cur; i++){
		printf("[%s]\n", arr[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
