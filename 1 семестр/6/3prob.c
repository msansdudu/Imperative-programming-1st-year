#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct strs {
  int dl;
  char* m;
} str;
str ms[100000];
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, t, l, k, mc = 0;
  char s[100000];
  char c;
  fscanf(stdin, "%d", &n);
  for (int i = 0; i < n; i++)
  {
    fscanf(stdin, "%d", &t);
    if (t == 0)
    {
      ms[mc].m = NULL;
      fscanf(stdin, "%d %s", &k, s);
      ms[mc].dl = strlen(s);
      ms[mc].m = (char*)malloc(sizeof(char) * (ms[mc].dl + 1));
      for (int y = 0; y <= ms[mc].dl; y++)
      {
        ms[mc].m[y] = s[y];
      }
      mc++;
    }
    else
    {
      if (t == 3)
      {
        fscanf(stdin, "%d %c", &k, &c);
        int p = 0;
        for (int j = 0; j < ms[k].dl; j++)
        {
          if (ms[k].m[j] == c)
          {
            p++;
          }
        }
        printf("%d\n", p);
      }
      else
      {
        fscanf(stdin, "%d", &k);
        if (t == 1)
        {
          ms[k].dl = 0;
          free(ms[k].m);
          ms[k].m = NULL;
        }
        else
        {
          printf("%s\n", ms[k].m);
        }
      }
    }
  }
  for (int i = 0; i <mc ; i++)
  {
    if (ms[i].m != NULL)
    {
      free(ms[i].m);
    }
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
