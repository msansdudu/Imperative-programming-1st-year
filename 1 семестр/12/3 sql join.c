#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ActorBio{
	char name[33];
	int year;
	char country[13];
} ActorBio;


typedef struct ActorInMovie{
	char name[33];
	char movie[23];
} ActorInMovie;


int main()
{
	ActorBio *actors;
	ActorInMovie *movies;
	int n, m, len, str_len, f;
	char str[60];
	scanf("%d\n", &n);
	actors = (ActorBio*) malloc(n * sizeof(ActorBio));
	for (int i = 0; i < n; i++){
		gets(str);
		len = strlen(str);
		str_len = 0;
		f = 0;
		actors[i].year = 0;
		for (int j = 0; j < len; j++){
			if (str[j] == '\"'){
				f++;
				if (f == 2){
					actors[i].name[str_len++] = '\"';
					actors[i].name[str_len] = '\0';
				}
				else if (f == 4){
					actors[i].country[str_len++] = '\"';
					actors[i].country[str_len] = '\0';
				}
				str_len = 0;
			}
			if (f == 1){
				actors[i].name[str_len] = str[j];
			}
			else if (f == 2){
				if (str_len != 0 && str[j] != ' '){
					actors[i].year = actors[i].year * 10 + str[j] - '0';
				}
			}
			else if (f == 3){
				actors[i].country[str_len] = str[j];
			}
			str_len++;
		}
	}
	
	scanf("%d\n", &m);
	movies = (ActorInMovie*) malloc(m * sizeof(ActorInMovie));
	for (int i = 0; i < m; i++){
		gets(str);
		len = strlen(str);
		str_len = 0;
		f = 0;
		for (int j = 0; j < len; j++){
			if (str[j] == '\"'){
				f++;
				if (f == 2){
					movies[i].name[str_len++] = '\"';
					movies[i].name[str_len] = '\0';
				}
				else if (f == 4){
					movies[i].movie[str_len++] = '\"';
					movies[i].movie[str_len] = '\0';
				}
				str_len = 0;
			}
			if (f == 1){
				movies[i].name[str_len] = str[j];
			}
			else if (f == 3){
				movies[i].movie[str_len] = str[j];
			}
			str_len++;
		}
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (!strcmp(actors[i].name, movies[j].name)){
				printf("%s %d %s %s %s\n", actors[i].name, actors[i].year, actors[i].country, movies[j].name, movies[j].movie);
			}
		}
	}
	free(actors);
	free(movies);
	return 0;
}

