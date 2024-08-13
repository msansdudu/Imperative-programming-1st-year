#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void bin_n_p(int mm[], int vl, int n) {
  int lft = 0, rght = n - 1, s = 0;
  while (rght - lft > 1)
  {
    s = (lft + rght) / 2;
    if (vl < mm[s])
    {
      rght = s;
    }
    else
    {
      lft = s;
    }
  }
  if (abs(vl - mm[rght]) > abs(vl - mm[lft]))
  {
    printf("%d %d\n", lft, abs(vl - mm[lft]));
  }
  else
  {
    printf("%d %d\n", rght, abs(vl - mm[rght]));
  }
}

int main() {
  int n;
  int m[200001];
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &m[i]);
  }
  int q;
  scanf("%d", &q);
  int x;
  for (int i = 0; i < q; i++)
  {
    scanf("%d", &x);
    bin_n_p(m, x, n);
  }
  return 0;
}
