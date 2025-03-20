#include <stdio.h>
#include <time.h>

int main() {
    int i;
    int sum = 0;

    // Get the start time
    long unsigned int start_time = time(NULL);
    printf("\n start_time :-%lu",start_time);

    // Parallelize the following loop
    //#pragma omp parallel for reduction(+:sum)
    for(i = 0; i < 99999999; i++) {
        sum += i;
    }
     for(i = 0; i < 99999999; i++) {
        sum += i;
    }
     for(i = 0; i < 99999999; i++) {
        sum += i;
    }
     for(i = 0; i < 99999999; i++) {
        sum += i;
    }

    // Get the end time
    long unsigned int end_time = time(NULL);

    printf("\n end_time :-%lu",end_time);
    // Print the total sum and execution time
    printf("Total sum: %d\n", sum);
    printf("Execution time: %lu seconds\n", end_time - start_time);

    return 0;
}
