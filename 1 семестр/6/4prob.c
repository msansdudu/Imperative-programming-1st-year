#include <stdio.h>

typedef struct list {
    long int s;
    int n;
    int p;
} lst;

lst m[200001];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, op, r_of_t, q, f, l, ind;
    scanf("%d", &r_of_t);
    for (int s = 0; s < r_of_t; s++)
    {
        scanf("%d %d %d %d", &n, &f, &l, &q);
        for (int r_of_n = 0; r_of_n < n; r_of_n++)
        {
            scanf("%ld %d %d", &m[r_of_n].s, &m[r_of_n].n, &m[r_of_n].p);
        }
        for (int r_of_q = 0; r_of_q < q; r_of_q++)
        {
            scanf("%d %d", &op, &ind);
            if (op == 0)
            {
                printf("%ld\n", m[ind].s);
                if ((l == f) || (l == -1 && l == f))
                {
                    l = -1;
                    f = -1;
                }
                else
                {
                    if (ind == f)
                    {
                        m[m[ind].n].p = -1;
                        f = m[ind].n;
                    }
                    else
                    {
                        if (ind == l)
                        {
                            m[m[ind].p].n = -1;
                            l = m[ind].p;
                        }
                        else
                        {
                            m[m[ind].n].p = m[ind].p;
                            m[m[ind].p].n = m[ind].n;
                        }
                    }
                }
            }
            else if (l == -1 && l == f)
            {
                printf("%d\n", n);
                n++;
                scanf("%ld", &m[n - 1].s);
                m[n - 1].n = -1;
                m[n - 1].p = -1;
                f = n - 1;
                l = n - 1;
            }
            else
            {
                printf("%d\n", n);
                n++;
                scanf("%ld", &m[n - 1].s);
                if (op == 1)
                {
                    if (ind != -1 && ind != l)
                    {
                        m[m[ind].n].p = n - 1;
                        m[n - 1].p = ind;
                        m[n - 1].n = m[ind].n;
                        m[ind].n = n - 1;
                    }
                    else
                    {
                        if (ind == -1)
                        {
                            m[f].p = n - 1;
                            m[n - 1].n = f;
                            m[n - 1].p = -1;
                            f = n - 1;
                        }
                        if (ind == l)
                        {
                            m[l].n = n - 1;
                            m[n - 1].p = l;
                            m[n - 1].n = -1;
                            l = n - 1;
                        }
                    }
                }
                else if (op == -1)
                {
                    if (ind != -1 && ind != f)
                    {
                        m[m[ind].p].n = n - 1;
                        m[n - 1].n = ind;
                        m[n - 1].p = m[ind].p;
                        m[ind].p = n - 1;
                    }
                    else
                    {
                        if (ind == f)
                        {
                            m[f].p = n - 1;
                            m[n - 1].n = f;
                            m[n - 1].p = -1;
                            f = n - 1;
                        }
                        if (ind == -1)
                        {
                            m[l].n = n - 1;
                            m[n - 1].p = l;
                            m[n - 1].n = -1;
                            l = n - 1;
                        }
                    }
                }
            }
        }
        printf("===\n");
        for (int k = f; k != -1; k = m[k].n)
        {
            printf("%ld\n", m[k].s);
        }
        printf("===\n");
    }
    return 0;
}
