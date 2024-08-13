#include <stdio.h>

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
  int r = 0, res = 0, s = 0, lft = 0, rght = n;
  for (int i = 0; i < q; i++)
  {
    int vl;
    scanf("%d", &vl);
    vl += res;
    lft = 0;
    rght = n;
    r = 0;
    res = -1;
    while (rght > (lft + 1))
    {
      s = (lft + rght) / 2;
      if (vl == m[s])
      {
        res = s;
        r = s;
        if (vl == m[s + 1] && s != (n - 1))
        {
          lft = s;
        }
        else
        {
          break;
        }
      }
      else if (vl < m[s])
      {
        rght = s;
      }
      else
      {
        lft = s;
      }
    }
    if (vl == m[rght] && res == -1)
    {
      r = vl;
      res = rght;
    }
    else if (vl == m[lft] && res == -1)
    {
      r = vl;
      res = lft;
    }
    printf("%d\n", res);
  }
  return 0;
}

