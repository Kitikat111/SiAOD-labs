#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void counting_sort(int m[], int n, int k)
{
int i, *a, *b;

a = calloc(k, sizeof(*a));
b = calloc(n, sizeof(*b));

for (i = 0; i < k; i++) {
    a[i] = 0;
}
for (i = 0; i < n; i++) {
    a[m[i]] = a[m[i]] + 1;
}
for (i = 1; i < k; i++) {
    a[i] = a[i] + a[i - 1];
}
for (i = (n - 1); i >= 0; i--) {
    a[m[i]] = a[m[i]] - 1;
    b[a[m[i]]] = m[i];
}
for (i = 0; i < n; i++) {
    m[i] = b[i];
}

free(a);
free(b);
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
counting_sort(arr, c, 100000);
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