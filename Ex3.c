#include <stdio.h>
#include <omp.h>

int main() {
    long long n, sum_serial = 0, sum_parallel = 0;
    double start_serial, end_serial, start_parallel, end_parallel;
    double time_serial, time_parallel;

    printf("Enter a positive integer n: ");
    scanf("%lld", &n);

    // Serial version
    start_serial = omp_get_wtime();
    for (long long i = 1; i <= n; i++) {
        sum_serial += i;
    }
    end_serial = omp_get_wtime();
    time_serial = end_serial - start_serial;

    // Parallel version
    start_parallel = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum_parallel)
    for (long long i = 1; i <= n; i++) {
        sum_parallel += i;
    }
    end_parallel = omp_get_wtime();
    time_parallel = end_parallel - start_parallel;

    // Output
    printf("\n=== Results ===\n");
    printf("Serial Sum   = %lld | Time = %f seconds\n", sum_serial, time_serial);
    printf("Parallel Sum = %lld | Time = %f seconds\n", sum_parallel, time_parallel);

    return 0;
}
