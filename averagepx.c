#include <stdio.h>
#include <omp.h>

int main()
{
    int n, i;
    unsigned int ans = 0;

    int NumThreads = omp_get_max_threads();
    omp_set_num_threads(NumThreads);
    scanf("%d", &n);
    unsigned num[n];

    for (i = 0; i < n; i++)
    {
        scanf("%u", &num[i]);
    }

#pragma omp parallel for reduction(+ : ans)
    for (i = 0; i < n; i++)
    {
        ans += num[i];
    }

    printf("%u", ans / n);
    return 0;
}
