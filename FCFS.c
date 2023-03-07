#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct FCFS
{
    int id, b, a, w, tat, et;
};
int compare_by_grade(const void *a, const void *b)
{
    struct FCFS *s1 = (struct FCFS *)a;
    struct FCFS *s2 = (struct FCFS *)b;
    return (s1->a - s2->a); // sort in descending order of grade
}
void sort(struct FCFS *ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((ar[i].a > ar[j].a) || (ar[i].a == ar[j].a && ar[i].id > ar[j].id))
            {
                ar[i].id = ar[i].id + ar[j].id - (ar[j].id = ar[i].id);
                ar[i].a = ar[i].a + ar[j].a - (ar[j].a = ar[i].a);
                ar[i].b = ar[i].b + ar[j].b - (ar[j].b = ar[i].b);
            }
        }
    }
}
void FcFs(struct FCFS *ar, int n)
{
    ar[0].et = ar[0].b + ar[0].a;
    ar[0].tat = ar[0].et - ar[0].a;
    ar[0].w = ar[0].tat - ar[0].b;
    for (int i = 1; i < n; i++)
    {
        if (ar[i - 1].et < ar[i].a)
            ar[i].et = ar[i].a + ar[i].b;
        else
            ar[i].et = ar[i - 1].et + ar[i].b;
        ar[i].tat = ar[i].et - ar[i].a;
        ar[i].w = ar[i].tat - ar[i].b;
    }
}
int main()
{
    int n;
    printf("Enter number of processed : ");
    scanf("%d", &n);
    struct FCFS ar[n];
    for (int i = 0; i < n; i++)
    {
        ar[i].id = i + 1;
        printf("Enter burst time of p%d : ", i + 1);
        scanf("%d", &(ar[i].b));
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter Arrival time of p%d : ", i + 1);
        scanf("%d", &(ar[i].a));
    }
    sort(ar, n);
    // qsort(ar, n, sizeof(struct FCFS), compare_by_grade);
    FcFs(ar, n);
    printf("+\t\tBt\t\tAt\t\tTAT\t\tWt\t\tEt\n");
    for (int i = 0; i < n; i++)
        printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", ar[i].id, ar[i].b, ar[i].a, ar[i].tat, ar[i].w, ar[i].et);
    return 0;
}