#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void bubble_sort(int a[], int length)
{
int i, k, tmp;
for (i = 0; i < length - 1; ++i) {
    for (k = 0; k < length - i - 1; ++k) {
        if (a[k] > a[k + 1]) {
            tmp = a[k];
            a[k] = a[k + 1];
            a[k + 1] = tmp;
        }
    }
}
}

int main()
{
int c, i;

printf("Count of Elements: ");
scanf("%d", &c);

int *arr;
arr = calloc(c, sizeof(*arr));
for (i = 0; i < c; i++)
arr[i] = getrand(0, 100000);

struct timeval tv1, tv2;
double start, end;

gettimeofday(&tv1, NULL);
bubble_sort(arr, c);
gettimeofday(&tv2, NULL);

start = tv1.tv_sec + 1e-6 * tv1.tv_usec;
end = tv2.tv_sec + 1e-6 * tv2.tv_usec;

printf("Time: %.6f sec.\n", end - start);

return 0;
}

int getrand(int min, int max)
{
return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}