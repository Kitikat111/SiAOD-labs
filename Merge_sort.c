#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void merge_sort(int a[], int n)
{
int *b, *c;
if (n > 1) {
int k = n / 2;

b = calloc(k, sizeof(*b));
c = calloc(n - k, sizeof(*c));

copy(a, k, b);
copy(a + k, (n - k), c);

merge_sort(b, k);
merge_sort(c, (n - k));
merge(b, k, c, (n - k), a, n);

free(b);
free(c);
}
}

void merge(int b[], int p, int c[], int q, int a[], int n)
{
int i = 0, j = 0, k = 0;
while ((i < p) && (j < q)) {
    if (b[i] <= c[j]) {
        a[k] = b[i];
        i++;
    } else {
        a[k] = c[j];
        j++;
    }
k++;
}

if (i == p) {
    copy(c + j, q - j, a + k);
} else {
    copy(b + i, p - i, a + k);
}
}

void copy(int a[], int k, int b[])
{
    int i;
    for (i = 0; i < k; i++) {
        b[i] = a[i];
    }
}


int main()
{
int c, i;

printf("Count of Elements: ");
scanf("%d", &c);

int *array;
array = calloc(c, sizeof(*array));
for (i = 0; i < c; i++)
array[i] = getrand(0, 100000);

struct timeval tv1, tv2;
double start, end;

gettimeofday(&tv1, NULL);
merge_sort(array, c);
gettimeofday(&tv2, NULL);

start = tv1.tv_sec + 1e-6 * tv1.tv_usec;
end = tv2.tv_sec + 1e-6 * tv2.tv_usec;

printf("Elapsed time: %.6f sec.\n", end - start);

return 0;
}

int getrand(int min, int max)
{
return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}